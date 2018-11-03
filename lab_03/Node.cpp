/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 3         *
 * Filename: Node.cpp     *
 **************************/

#include "Node.h"

Node::Node()
{
    data = 0;
    next = NULL;
    prev = NULL;
}

Node::Node(int newData)
{
    data = newData;
    next = NULL;
    prev = NULL;
}

Node::~Node()
{
}

Node& Node::operator++(int nothingness)
{
    data++;

    return *this;
}

void Node::setData(int newData)
{
    data = newData;
}

void Node::setNext(Node* newNext)
{
    next = newNext;
}

void Node::setPrev(Node* newPrev)
{
    prev = newPrev;
}

int Node::getData()
{
    return data;
}

Node* Node::getNext() const
{
    return next;
}

Node*& Node::getNext()
{
    return next;
}

Node* Node::getPrev() const
{
    return prev;
}

Node*& Node::getPrev()
{
    return prev;
}
