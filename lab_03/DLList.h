/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 3         *
 * Filename: DLList.h     *
 **************************/

#pragma once

#include <iostream>

#include "Node.h"

using std::cout;
using std::endl;


/**
 * \author Daniel G. Arnold\n
 * A class that implements a doubly-linked list.
 */
class DLList
{
public:

    /**
     * Default constructor.
     * Initialize this instance's data members to
     * head = NULL;
     * tail = NULL;
     * size = 0;
     */
    DLList();

    /**
     * Destructor.
     * Deallocate the list from memory if the user has not already done so.
     */
    ~DLList();

    /**
     * Inserts a new node to the front of the list.
     * @param int newData the value for the 'data' variable
     */
    void insertHead(int newData);

    /**
     * Inserts a new node to the rear of the list.
     * @param int newData the value for the 'data' variable
     */
    void insertTail(int newData);
    
    /**
     * Inserts a new node before a node with a greater value in its 'data' variable.
     * @param int newData the value for the 'data' variable
     */
    void insert(int newData);
    
    /**
     * Assigns a new value to this instance's 'size' variable.
     * @param int newSize the value for the 'size' variable
     */
    void setSize(int newSize);
    
    /**
     * Removes a node from the front of the list.
     */
    void removeHead();

    /**
     * Removes a node from the rear of the list.
     */
    void removeTail();

    /**
     * Removes a node with its 'data' variable matching the value of 'newData'.
     * @param int newData the value used for comparing with the 'data' variable
     */
    void remove(int newData);

    /**
     * Retrieve the value of this instance's 'head' variable.
     * @return a Node* containing the value of the 'head' variable
     */
    Node* getHead();
    
    /**
     * Retrieve the value of this instance's 'tail' variable.
     * @return a Node* containing the value of the 'tail' variable
     */
    Node* getTail();

    /**
     * Search for and retrieve a node.
     * @param int newData the data used to search for and retrieve
     */
    Node* get(int newData);
    
    /**
     * Retrieve the value of this instance's 'size' variable.
     * @return an int containing the value of the 'size' variable
     */
    int getSize();
    
    /**
     * Increase each node's 'data' variable by 1 using the overloaded ++.
     */
    void bump();
    
    /**
     * Sort the list in ascending order.
     * @param bool move run the first, "move", algorithm if true; run the second, "copy", algorithm if false
     */
    void sort(bool move = true);

    /**
     * Reverse the list.
     */
    void reverse();

    /**
     * Print the list to the screen.
     */
    void print();

    /**
     * Deallocate the list from memory.
     */
    void clear();

private:

    Node* head;
    Node* tail;
    int size;
    void clear(Node* marker);
};
