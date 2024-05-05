//Customer class meant to contruct customers
#include "Customer.h"
#include <fstream>
#include <algorithm>

/*
Customer constructor using an ifstream
*/
Customer::Customer(std::ifstream& stream) {
    stream >> customerID >> lastName >> firstName;
}

/*
Customer constructor using an an id
*/
Customer::Customer(int id) {
    customerID = id;
}

/*
Customer destructor
*/
Customer::~Customer() = default;

/*
Return an int being the customer ID
*/
int Customer::getId() const{
    return customerID;
}

/*
Return a string being the customers first name
*/
std::string Customer::getFirstName() const{
    return firstName;
}

/*
Return a string being the customers last name
*/
std::string Customer::getLastName() const{
    return lastName;
}

/*
Method which marks a customer borrowing media 
in this method being a movie
Method will also place this transaction in customers history
*/
void Customer::borrowMedia(Movie* movie){
    borrowing.push_back(movie); //add movie to current usage
    //add movie to history (Borrowing). add to front for latest access
    history.insert(history.begin(), "Borrowing: " + movie->getKey());
    movie->setStock((movie->getStock()) - 1);
}

/*
Method which marks as a customer returning media 
in this method being a movie
Method will also place this transaction in customers history
*/
void Customer::returnMedia(Movie* movie){
    //check if movie being borrowed by customer
    if(find(borrowing.begin(), borrowing.end(), movie) != borrowing.end()){
        //add movie return to history
        history.insert(history.begin(), "Returning: " + movie->getKey());
        borrowing.erase(remove(borrowing.begin(), borrowing.end(), movie), borrowing.end());
        movie->setStock((movie->getStock()) + 1);
    }
}

/*
Method that will print out a customers history
*/
void Customer::showHistory() {
    std::cout << "------ Customer : " << firstName + "'s History ------" << std::endl;
    if(history.empty()) {
        std::cout << "No History to Show!" << std::endl;
    }
    for (int i = 0; i < history.size(); i++) {
        std::cout << history[i] << std::endl;
    }
}

/*
operator < overload to be used to compare customers by ID
*/
bool Customer::operator<(const Customer& other) const {
	return customerID < other.customerID;
}

/*
operator > overload to be used to compare customers by ID
*/
bool Customer::operator>(const Customer& other) const {
	return customerID > other.customerID;
}

/*
operator == overload to be used to compare customers by ID
*/
bool Customer::operator==(const Customer& other) const {
	return customerID == other.customerID;
}

/*
operator != overload to be used to compare customers by ID
*/
bool Customer::operator!=(const Customer& other) const {
	return customerID != other.customerID;
}