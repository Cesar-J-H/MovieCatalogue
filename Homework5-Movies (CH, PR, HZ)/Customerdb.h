//Customerdb header file
#ifndef _CUSTOMERDB_H_
#define _CUSTOMERDB_H_
#include "Hashtable.h"
#include "Customer.h"

class Customerdb {
public: 
    Customerdb();
    ~Customerdb();
    bool insertCustomer(Customer* customer);
    bool retrieveCustomer(const int& id, Customer*& retriever) const;
    bool removeCustomerByID(const int& id);
    Customer* getACustomer(const int& id) const;
    void getCustomerInfo(int id);
    int getCustomerCount();
private:
    HashTable<int, Customer> collection;
};
#endif
