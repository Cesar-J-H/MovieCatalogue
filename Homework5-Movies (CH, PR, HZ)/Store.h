#ifndef _STORE_H_
#define _STORE_H_
#include <fstream>
#include <ostream>
#include <sstream>
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include "Customerdb.h"

const int SIZE = 3;
const std::string MOVIE_TYPES[] = { "Classic", "Comedy", "Drama"  };
const char BORROW = 'B';
const char HISTORY = 'H';
const char RETURN = 'R';
const char INVENTORY = 'I';
class Store {
    public:
        Store();
        ~Store();
        void fillMovieCatalog(std::ifstream& stream);
        void fillCustomerDB(std::ifstream& stream);
        void addMovie(std::ifstream& stream); //For testing
        void doCommands(std::ifstream& stream);
        void getCustomerInfo(int id);
        void getCustomerCount();
        void displayInventory();
        void executeCommands(std::ifstream &stream);
        Movie* findMovie(std::stringstream &line_input, char genre);
        enum COMMAND {
            BORROW_Enum,
            RETURN_Enum,
            HISTORY_Enum,
            INVENTORY_Enum,
        };

        enum GENRE {
            COMEDY_Enum ,
            CLASSIC_Enum ,
            DRAMA_Enum ,
            END
        };
        

private: 
    Customerdb customerDatabase;
    std::map<std::string, std::vector<Movie*>> catalog;
};
#endif
