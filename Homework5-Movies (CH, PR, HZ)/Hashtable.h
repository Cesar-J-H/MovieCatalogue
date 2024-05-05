//Hashtable class meant to contain objects
#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_
#include <string>
#include "BST.h"

const int hashSize = 101; //Table shouldnt hold more than 101 objects
template <typename Key, typename Val> 

class HashTable {
public:
    HashTable();
    ~HashTable();
    bool insert(Key key, Val* val);
    bool retrieve(Key key, Val*& retriever) const;
    Val* getValue(Key key) const;
    bool remove(Key key);
    int getSize();
private:
    BST<Val>* table[hashSize];
    void clear();
    int amount = 0;
};

/*
Constructor for hashtable
initializes everything in the table to nullptr
*/
template <typename Key, typename Val>
HashTable<Key, Val>::HashTable() {
    for (int i = 0; i < hashSize; i++) {
        this->table[i] = nullptr;
    }
}

/*
Destructor for the hashtable using the clear function
*/
template <typename Key, typename Val>
HashTable<Key, Val>::~HashTable() {
    clear();
}

/*
Insert method meant to insert an object
value of object corresponds to key to bucket
returns true if object was placed into table
false if not
*/
template <typename Key, typename Val>
bool HashTable<Key, Val>::insert(Key key, Val* val) {
    const int hash = reinterpret_cast<const int&>(key) % hashSize;
    if (hash < 0) { //no negatives
        return false;
    }
    if (table[hash] == nullptr) {
        table[hash] = new BST<Val>();
        amount++;
        return table[hash]->insert(val);
    }
    else { //collision
        return table[hash]->insert(val);
    }
    return false;
}

/*
Retrieve method meant to return true if object 
is able to be retrieved from hashtable
*/
template <typename Key, typename Val>
bool HashTable<Key, Val>::retrieve(Key key, Val*& retriever) const {
    const int hash = reinterpret_cast<const int&>(key) % hashSize;
    if (hash < 0 || table[hash] == nullptr) { //no negatives or empty bucket
        return false;
    }
    else { //recursevly look for object
        const Val tempTarget(key);
        return table[hash]->retrieve(tempTarget, retriever);
    }
    return false;
}

/*
Method that will return an object from the given hashtable key
*/
template <typename Key, typename Val>
Val* HashTable<Key, Val>::getValue(Key key) const {
    const int hash = reinterpret_cast<const int&>(key) % hashSize;
    if (hash < 0 || table[hash] == nullptr) { //no negatives or empty bucket
        return nullptr;
    }
    else {
        Val* tempRetrive = nullptr;
        const Val tempTarget(key);
        if (table[hash]->retrieve(tempTarget, tempRetrive)) {
            return tempRetrive;
        }   
        return nullptr;
    }
    return nullptr;
}

/*
Method that will return true if the object was able to be removed from 
the hashtable if it wasnt return false
*/
template <typename Key, typename Val>
bool HashTable<Key, Val>::remove(Key key) {
    const int hash = reinterpret_cast<const int&>(key) % hashSize;
    if (hash < 0 || table[hash] == nullptr) {
        return false;
    }
    else {
        const Val tempTarget(key);
        amount --;
        return table[hash]->remove(tempTarget);
    }
}

/*
Method meant to clear the hashtable of the objects inside of it
*/
template <typename Key, typename Val>
void HashTable<Key, Val>::clear() {
    for (int i = 0; i < hashSize; i++) {
        //std::cout << "we made it to the loop" << std::endl;
        if (this->table[i] != nullptr) {
            this->table[i]->clear();
            delete this->table[i];
            this->table[i] = nullptr;
            //std::cout << "we made it in here" << std::endl;
        }
    }
}

/*
Method meant to return the amount of objects inside of the hashtable
*/
template <typename Key, typename Val>
int HashTable<Key, Val>::getSize() {
    return amount;
} 
#endif
