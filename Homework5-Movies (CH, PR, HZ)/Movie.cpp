//Movie class meant to build an movie object
#include <fstream>
#include <map>
#include <vector>
#include "Movie.h"

/*
Destructor for the movie class
*/
Movie::~Movie() = default;

/*
Operator << overload to be used in order to print out a movie object information
*/
std::ostream& operator<<(std::ostream& ostream, const Movie & movie) {
	ostream << "\tStock : " << movie.getStock() << " \n";
	ostream << "\tDirector : " << movie.getDirector() << " \n";
	ostream << "\tTitle : " << movie.getTitle() << " \n";
	ostream << "\tYear : " << movie.getYear() << " \n";
	return ostream;
}

/*
Method that returns a string that is the directors name
*/
std::string Movie::getDirector() const {
    return director;
}

/*
Method that returns a string that is the movie title
*/
std::string Movie::getTitle() const {
    return title;
}

/*
Method that returns a string that is the movies year
*/
std::string Movie::getYear() const {
    return year;
}

/*
Method that returns an int reflecting the stock
*/
int Movie::getStock() const {
	return this->stock;
}

/*
Method that sets a directors name
*/
void Movie::setDirector(std::string d) {
    director = d;
}

/*
Method that sets a movie titles name
*/
void Movie::setTitle(std::string t) {
    title = t;
}

/*
Method that sets a movies year
*/
void Movie::setYear(std::string y) {
    year = y;
}

/*
Method that sets a movies stock amount
*/
void Movie::setStock(int x){
    stock = x;
}