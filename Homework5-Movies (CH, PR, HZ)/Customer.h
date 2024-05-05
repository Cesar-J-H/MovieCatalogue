//Customer header file
#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include <iostream>
#include "Movie.h"
#include <vector>

class Customer {
public:
    Customer(int id);
    Customer(std::ifstream& stream);
    ~Customer();
    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    void showHistory();
    void returnMedia(Movie* movie);
    void borrowMedia(Movie* movie);

    bool operator<(const Customer&) const;
    bool operator>(const Customer&) const;
    bool operator==(const Customer&) const;
    bool operator!=(const Customer&) const;
private:
    int customerID;
    std::string firstName;
    std::string lastName;
    std::vector<Movie*> borrowing;
    std::vector<std::string> history;
};
#endif
