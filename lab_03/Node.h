/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 3         *
 * Filename: Node.h       *
 **************************/

#pragma once

#include <cstdlib>

/**
 * \author Daniel G. Arnold\n
 * A class for a node in a doubly-linked list.
 */
class Node
{
public:

    /**
     * Default constructor.
     * Initialize this instance's data members to
     * data = 0;
     * next = NULL;
     * prev = NULL;
     */
    Node();

    /**
     * Overloaded constructor.
     * Initialize this instance's data members to
     * data = newData;
     * next = NULL;
     * prev = NULL;
     */
    Node(int newData);
    
    /**
     * Destructor.
     * Does nothing.
     */
    ~Node();

    /**
     * Overload this type's ++ operator.
     * Increases this instance's 'data' variable by 1.
     * @param int nothinginess this value does absolutely nothing
     * @return Node& a reference to this instance
     */
    Node& operator++(int nothingness);
    
    /**
     * Assign a new value to this instance's 'data' variable.
     * @param int newData the value for the 'data' variable
     */
    void setData(int newData);
    
    /**
     * Assign a new value to this instance's 'next' variable.
     * @param Node* newNext the value for the 'next' variable
     */
    void setNext(Node* newNext);
    
    /**
     * Assign a new value to this instance's 'prev' variable.
     * @param Node* newPrev the value for the 'prev' variable
     */
    void setPrev(Node* newPrev);
    
    /**
     * Retrieve the value of this instance's 'data' variable.
     * @return an int containing the value of the 'data' variable
     */
    int getData();
    
    /**
     * Retrieve the value of this instance's 'next' variable.
     * @return a Node* containing the value of the 'next' variable
     */
    Node* getNext() const;

    /**
     * Retrieve a reference to this instance's 'next' variable.
     * @return a Node*& containing the address of the 'next' variable
     */
    Node*& getNext();
    
    /**
     * Retrieve the value of this instance's 'prev' variable.
     * @return a Node* containing the value of the 'next' variable
     */
    Node* getPrev() const;

    /**
     * Retrieve a reference to this instance's 'prev' variable.
     * @return a Node*& containing the address of the 'prev' variable
     */
    Node*& getPrev();

private:

    int data;
    Node* next;
    Node* prev;
};
