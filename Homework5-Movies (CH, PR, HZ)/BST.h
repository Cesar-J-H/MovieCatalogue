//Generic Binary Search Tree class
#ifndef _BST_H_
#define _BST_H_
#include <iostream>

template <typename T>
class BST {
public:
    BST();
    ~BST();
    bool insert(T*);
    bool remove(const T&);
    bool retrieve(const T&, T*&) const;
    bool isEmpty() const;
    int getTotalNode() const;
    void clear();
private:
    struct Node {
        T* data;
        Node* right;
        Node* left;
    };
    Node* root;
    int totalNode;
    bool insertHelper(T*, Node*&);
    bool retrieveHelper(Node*, const T&, T*&) const;
    bool removeHelper(Node*& current, const T& key);
    void clearHelper(Node*&);
};

/*
Constructor for Binary Search Tree
*/
template<typename T>
BST<T>::BST() {
    root = nullptr;
    totalNode = 0;
}

/*
Destructor for Binary Search Tree
Calls upon clear method
*/
template<typename T>
BST<T>::~BST() {
    clear();
}

/*
Insert method for BST
Will insert object into the BST and return true if operation done correctly
Return false if object couldnt be inserted
*/
template<typename T>
bool BST<T>::insert(T* newNode) { 
    if (root == nullptr) { //if no objects in tree
        root = new Node{newNode, nullptr, nullptr};
        totalNode++;
        return true;
    }
    if (insertHelper(newNode, root)) { //call helper to add to tree
        totalNode++;
        return true;
    }
    return false;
}

/*
Helper function for insert
Traverse through the tree in order to find where the node should be 
and insert it there recursevly
*/
template<typename T>
bool BST<T>::insertHelper(T* newNode, Node*& current) {
    if (current == nullptr) { //when reaches empty node
        current = new Node{ newNode, nullptr, nullptr };
        return true;
    }
    else if (*newNode < *current->data) { //Left
        return insertHelper(newNode, current->left);
    }
    else if (*newNode > *current->data) { //Right
        return insertHelper(newNode, current->right);
    }
    return false;
}

/*
Retrieve method 
Return true if object is able to be retrieved
If object isnt able to be retrieved return false
*/
template<typename T>
bool BST<T>::retrieve(const T& target, T*& retriever) const {
    return retrieveHelper(root, target, retriever);
}

/*
Helper function for retrieve 
Will recursevly go through the tree until object is found and return true
If the object isnt found return false
*/
template<typename T>
bool BST<T>::retrieveHelper(Node* current, const T& target, T*& retriever) const {
    if (current == nullptr) { //If out of bounds or not found
        retriever = nullptr;
        return false;
    }
    if (target < *current->data) { //left
        return retrieveHelper(current->left, target, retriever);
    }
    else if (target > *current->data) { //right
        return retrieveHelper(current->right, target, retriever);
    }
    else { //Object found
        retriever = current->data;
        return true;
    }
}

/*
Remove method which will remove an object from the BST
If removal was succesful return true
If removal wasnt succesful return false
*/
template<typename T>
bool BST<T>::remove(const T& target) {
    if (this->root == nullptr) { //if nothing is in the tree
        return false;
    }
    if (removeHelper(root, target)) { //call helper function to remove object
        totalNode--;
        return true;
    }
    return false;
}

/*
Remove helper function 
recursevly go through the tree looking for object to be removed
if removed succesfully return true
if object couldnt be found or removed return false
*/
template<typename T>
bool BST<T>::removeHelper(Node*& current, const T& target) {
    if (current == nullptr) { //if object wasnt found
        return false;
    }
    if (target < *current->data) { //left
        return removeHelper(current->left, target);
    }
    else if (target > * current->data) { //right
        return removeHelper(current->right, target);
    }
    else { 
        if (current->left == nullptr && current->right == nullptr) { //node is at the very bottom with no children
            delete current->data;
            delete current;
            current = nullptr;
            return true;
        }
        else if (current->left && current->right) { //Node has 2 children
            Node* temp = current->right; 
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            *current->data = *temp->data;
            return removeHelper(current->right, *temp->data);
        }
        else { //node only has a single child
            Node* child;
            if (current->left) {
                child = current->left;
            }
            else {
                child = current->right;
            }
            Node* temp = current;
            current = child;
            delete temp->data;
            delete temp;
            temp = nullptr;
            return true;
        }
    }
}

/*
Mehtod that returns true if tree is empty
false if tree has objects
*/
template<typename T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
}

/*
Method that returns total amount of nodes in tree
*/
template<typename T>
int BST<T>::getTotalNode() const {
    return totalNode;
}

/*
Method that clears the tree
*/
template<typename T>
void BST<T>::clear() {
    if (root == nullptr) { //if tree is empty no need to do anything
        return;
    }
    clearHelper(root); //call helper
    root = nullptr;
}

/*
Recursevly go through the tree clearing each node
*/
template<typename T>
void BST<T>::clearHelper(Node*& current) {
    if (current != nullptr) {
        clearHelper(current->left);
        clearHelper(current->right);
        if (current->data != nullptr) {
            delete current->data;           
        }
        delete current;
    }
}
#endif