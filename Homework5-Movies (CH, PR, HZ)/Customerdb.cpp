//Customerdc class meant to act as a customer container
#include "Customerdb.h"

/*
Constructor for customderdb
*/
Customerdb::Customerdb() = default;

/*
Destructor for customderdb
*/
Customerdb::~Customerdb() = default;

/*
Method meant to insert customer to hastable
Will return true if customer was inserted into the hashtable correctly
If customer was not able to be inserted return false and no insertion happens
*/
bool Customerdb::insertCustomer(Customer* customer)  {
	return collection.insert(customer->getId(), customer);
}

/*
Method meant to remove customers from the hastable
Will return true if customer was able to be removed from the hashtable correctly
If customer was not able to be removed return false
*/
bool Customerdb::removeCustomerByID(const int& id) {
	return collection.remove(id);
}

/*
Method meant to get customer information 
based on customer id
*/
void Customerdb::getCustomerInfo(int id) { //uses hashtable methods
	std::cout << collection.getValue(id)->getFirstName() << " " 
		<< collection.getValue(id)->getLastName() << " ID: " 
		<< collection.getValue(id)->getId() << std::endl;
}

/*
Method that will return amount of customers in the hashtable
*/
int Customerdb::getCustomerCount() {
	return collection.getSize(); //uses hastable method
}

/*
Method that will returns a pointer to a customer from the key
*/
Customer* Customerdb::getACustomer(const int& id) const {
	return collection.getValue(id); //uses hashtable method
}