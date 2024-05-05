//Store class which acts as the storage for the movies but also does calls to other classes
#include "Store.h"
#include "Classic.h"
#include "Comedy.h"
#include "Customer.h"
#include "Drama.h"
#include "MediaFactory.h"
#include "Movie.h"
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <vector>

/*
Method that compares 2 movies based on their genre 
*/
bool less_than(const Movie *lhs, const Movie *rhs) {
    switch (lhs->getMovieType()) {
        case COMEDY: {
            const auto *movie1 = dynamic_cast<const Comedy *>(lhs);
            const auto *movie2 = dynamic_cast<const Comedy *>(rhs);
            return movie1 < movie2;
        }
        case CLASSIC: {
            const auto *movie1 = dynamic_cast<const Classic *>(lhs);
            const auto *movie2 = dynamic_cast<const Classic *>(rhs);
            return movie1 < movie2;
        }
        case DRAMA: {
            const auto *movie1 = dynamic_cast<const Drama *>(lhs);
            const auto *movie2 = dynamic_cast<const Drama *>(rhs);
            return movie1 < movie2;
        }
    }
    return false;
}

/*
Store constructor
*/
Store::Store() {
    std::vector<Movie *> comedy;
    std::vector<Movie *> classic;
    std::vector<Movie *> drama;
    catalog.insert({"Comedy", comedy});
    catalog.insert({"Classic", classic});
    catalog.insert({"Drama", drama});
}

/*
Store destructor
*/
Store::~Store() {
    for (auto it = catalog.begin(); it != catalog.end(); it++) {
        std::vector<Movie *> d = (*it).second;
        for (int i = 0; i < d.size(); i++) {
            Movie *del = d[i];
            delete del;
        }
    }
}

/*
Method that fills in customer container using a text file
*/
void Store::fillCustomerDB(std::ifstream &stream) {
    // If the file is unable to be read
    if (!stream) {
        std::cout << "UNABLE TO READ CUSTOMER TEXT FILE" << std::endl;
        return;
    }
    Customer *person;
    while (!stream.eof()) {
        person = new Customer(stream);
        // delete customer if duplicate or unable to be added
        if (!customerDatabase.insertCustomer(person)) {
        delete person;
        }
    }
    stream.close();
}

/*
Method that returns a customers info using a customer id
*/
void Store::getCustomerInfo(int id) { 
    customerDatabase.getCustomerInfo(id); 
}

/*
Method that returns amount of customers in database
*/
void Store::getCustomerCount() {
    std::cout << customerDatabase.getCustomerCount() << std::endl;
}

/*
Method that fills in movie storage using a text file
*/
void Store::fillMovieCatalog(std::ifstream &stream) {
    if (!stream) {
        std::cout << "Cannot read movie file!" << std::endl;
        return;
    }
    while (!stream.eof()) {
        Movie *temp_movie = MediaFactory::buildMovie(stream);
        if (temp_movie) { // if not NULL
        switch (temp_movie->getMovieType()) {
            case COMEDY:
                catalog["Comedy"].push_back(temp_movie);
                break;
            case CLASSIC:
                catalog["Classic"].push_back(temp_movie);
                break;
            case DRAMA:
                catalog["Drama"].push_back(temp_movie);
                break;
            default:
                break;
            }
        }
    }
}

/*
Method that displays the current invetory of movies
*/
void Store::displayInventory() {
    std::cout << "-------------------------------------------------------"
                << std::endl;
    std::cout << "Movies Inventory" << std::endl;
    std::cout << "-------------------------------------------------------"
                << std::endl;
    // go through each of the movie genres
    for (auto it = catalog.begin(); it != catalog.end(); it++) {
        std::cout << (*it).first << " : " << std::endl;
        std::vector<Movie *> d = (*it).second;
        std::sort(d.begin(), d.end(), less_than);
        // go through movie genre and print out movies
        for (int i = 0; i < d.size(); i++) {
        std::cout << *d[i] << std::endl;
        }
    }
}

/*
Method that executes commands based on a text file
*/
void Store::executeCommands(std::ifstream &stream) {
    std::cout << "Do commands:" << std::endl;
    if (!stream) {
        std::cout << "Cannot read command file!" << std::endl;
        return;
    }
    while (!stream.eof()) {
        std::string read_input;
        getline(stream, read_input);
        std::stringstream line_input(read_input);
        // read the character
        char type;
        int cust_num;
        std::string media;
        char genre;
        // fill variables
        line_input >> type >> cust_num >> media >> genre;
        switch (type) {
        case BORROW: {
            Customer *person = customerDatabase.getACustomer(cust_num);
            if (person == nullptr) {
                std::cout << "---- Invalid Transaction , Customer not found! ---" <<std::endl;
                break;
            }
            Movie *movie = findMovie(line_input, genre);
            if (movie == nullptr) {
                std::cout << "---- Invalid Transaction , Movie not found! ---" <<std::endl;
                break;
            }
            if (movie->getStock() > 0) {
            person->borrowMedia(movie);
            }
        } break;
        case RETURN: {
            Customer *person = customerDatabase.getACustomer(cust_num);
            if (person == nullptr) {
                std::cout << "---- Invalid Transaction , Customer not found! ---" <<std::endl;
                break;
            }
            Movie *movie = findMovie(line_input, genre);
            if (movie == nullptr) {
                std::cout << "---- Invalid Transaction , Movie not found! ---" <<std::endl;
            break;
            }
            person->returnMedia(movie);
        } break;
        case INVENTORY: {
            displayInventory();
        } break;
        case HISTORY: {
            Customer *person = customerDatabase.getACustomer(cust_num);
            if (person == nullptr) {
                break;
            }
            person->showHistory();
        } break;
        default: {
            std::cout << "---- Invalid Transaction , Transaction Type not supported! ---" <<std::endl;
            } break;
        }
    }
}

/*
Method that find a movie using a string stream
*/
Movie *Store::findMovie(std::stringstream &line_input, char genre) {
    Movie *movie = nullptr;
    switch (genre) {
    case CLASSIC: {
        std::string month;
        std::string year;
        std::string first_name_ac;
        std::string last_name_ac;
        // Access classic movies
        std::vector<Movie *> d = catalog["Classic"];
        // fill strings with info to search by
        line_input >> month >> year >> first_name_ac >> last_name_ac;
        // look through classic movies
        for (int i = 0; i < d.size(); i++) {
        // search by actor and date
        if ((*d[i]).getKey().compare(month + " " + year + " " + first_name_ac +
                                    " " + last_name_ac) == 0) {
            // check stock
            movie = d[i];
        }
        }
        break;
    }

    case COMEDY: {
        std::string title;
        std::string year;
        // Access comedy movies
        std::vector<Movie *> d = catalog["Comedy"];
        // fills string with info to search by
        // Will grab whole line and stop at comma and place it to title
        getline(line_input, title,',');
        title.erase(0, 1); // Getting rid of white space from start of string
        line_input >> year;
        year.erase(0, 1); // Getting rid of white space from start of string
        // check comedy movies
        for (int i = 0; i < d.size(); i++) {
        // search by title
        if (d[i]->getTitle().compare(title) == 0) {
            // check stock
            movie = d[i];
        }
        }
        break;
    }
    case DRAMA: {
        std::string director;
        std::string title;
        // access drama movies
        std::vector<Movie *> d = catalog["Drama"];
        getline(line_input, director,','); // Will grab whole line and stop at comma and place it to director
        director.erase(0, 1); // Getting rid of white space from start of string
        getline(line_input, title,','); // Will grab whole line and stop at comma and place it to title
        title.erase(0, 1); // Getting rid of white space from start of string
        // look through dramas
        for (int i = 0; i < d.size(); i++) {
        // search by title
        if (d[i]->getTitle().compare(title) == 0) {
            // check stock
            movie = d[i];
        }
        }
        break;
    }
    default: {
        movie = nullptr;
    } break;
    }
    return movie;
}
