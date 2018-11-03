/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 3         *
 * Filename: DLList.cpp   *
 **************************/

#include "DLList.h"

DLList::DLList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

DLList::~DLList()
{
    if (head != NULL)
        clear(head);
}

void DLList::insertHead(int newData)
{
    Node* newNode = new Node(newData);

    if (head == NULL)
        head = tail = newNode;
    else {
        head->setPrev(newNode);
        newNode->setNext(head);
        head = newNode;
    }

    size++;
}

void DLList::insertTail(int newData)
{
    Node* newNode = new Node(newData);

    if (head == NULL)
        head = tail = newNode;
    else {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }

    size++;
}

void DLList::insert(int newData)
{
    if (head == NULL)
        insertHead(newData);
    else {
        Node* marker = head;

        while (marker != NULL && marker->getData() < newData)
            marker = marker->getNext();

        if (marker == NULL)
            insertTail(newData);
        else if (marker == head)
            insertHead(newData);
        else {
            Node* newNode = new Node(newData);

            newNode->setPrev(marker->getPrev());
            newNode->setNext(marker);
            marker->getPrev()->setNext(newNode);
            marker->setPrev(newNode);
            size++;
        }
    }
}

void DLList::setSize(int newSize)
{
    size = newSize;
}

void DLList::removeHead()
{
    if (size == 1) {
        delete head;
        head = tail = NULL;
    } else {
        head = head->getNext();
        delete head->getPrev();
        head->setPrev(NULL);
    }
    
    size--;
}

void DLList::removeTail()
{
    if (size == 1) {
        delete tail;
        tail = head = NULL;
    } else {
        tail = tail->getPrev();
        delete tail->getNext();
        tail->setNext(NULL);
    }

    size--;
}

void DLList::remove(int newData)
{
    Node* marker = head;

    while (marker != NULL && marker->getData() != newData)
        marker = marker->getNext();

    if (marker == head)
        removeHead();
    else if (marker == tail)
        removeTail();
    else if (marker == NULL);
    else {
        marker->getPrev()->setNext(marker->getNext());
        marker->getNext()->setPrev(marker->getPrev());
        delete marker;
        size--;
    }
}

Node* DLList::getHead()
{
    return head;
}

Node* DLList::getTail()
{
    return tail;
}

Node* DLList::get(int newData)
{
    if (head == NULL)
        return head;
    else {
        Node* marker = head;

        while (marker != NULL && marker->getData() != newData)
            marker = marker->getNext();

        return marker;
    }
}

int DLList::getSize()
{
    return size;
}

void DLList::bump()
{
    if (head != NULL) {
        Node* marker = head;

        while (marker != NULL) {
            (*marker)++;
            marker = marker->getNext();
        }
    } else;

}

void DLList::sort(bool move)
{
    
    Node* marker = head;
    Node* temp = NULL;

    if (move) {
        for (int i = 0; i < (size - 1); i++, marker = head)
            for (int j = 0; j < (size - 1); j++) {
                if (marker->getNext()->getData() < marker->getData()) {
                    if (marker == head) {
                        temp = marker->getNext();
                        
                        if (size == 2)
                            marker->setNext(NULL);
                        else {
                            marker->setNext(temp->getNext());
                            marker->getNext()->setPrev(marker);
                        }
                        
                        marker->setPrev(temp);
                        temp->setNext(marker);
                        temp->setPrev(NULL);
                        
                        if (size == 2)
                            tail = marker;
                        
                        head = temp;
                    } else if (marker->getNext() == tail) {
                        temp = marker->getNext();
                        marker->getNext()->setNext(marker);
                        marker->getPrev()->setNext(temp);
                        temp->setPrev(marker->getPrev());
                        marker->setPrev(temp);
                        marker->setNext(NULL);
                        tail = marker;
                    } else {
                        bool tempIsTail = false;
                        
                        temp = marker->getNext();
                        
                        if (temp == tail)
                            tempIsTail = true;
                        
                        marker->setNext(marker->getNext()->getNext());
                        marker->getNext()->setPrev(marker);
                        temp->setPrev(marker->getPrev());
                        marker->setPrev(temp);
                        temp->setNext(marker);
                        temp->getPrev()->setNext(temp);
                        
                        if (tempIsTail)
                            tail = marker;
                    }
                } else
                    marker = marker->getNext();
            }
    } else {
        Node* marker = head;
        int temp = 0;
        
        for (int i = 0; i < (size - 1); i++, marker = head)
            for (int j = 0; j < (size - 1); j++, marker = marker->getNext())
                if (marker->getNext()->getData() < marker->getData()) {
                    temp = marker->getData();
                    marker->setData(marker->getNext()->getData());
                    marker->getNext()->setData(temp);
                }
    }
}

    

void DLList::reverse()
{
    Node* marker = head;
    Node* temp = NULL;

    temp = head;
    head = tail;
    tail = temp;

    while (marker != NULL) {
        temp = marker->getPrev();
        marker->setPrev(marker->getNext());
        marker->setNext(temp);
        marker = marker->getPrev();
    }
}

void DLList::print()
{
    Node* startNode = head;

    cout << "\nhead -> " << head << "\n";

    while (startNode != NULL) {
        cout << startNode << " [" << startNode->getData() << "] -> " << startNode->getNext() << "\n";
        startNode = startNode->getNext();
    }

    cout << endl;
}

void DLList::clear(Node* marker)
{
    if (marker != NULL) {
        clear(marker->getNext());
        cout << "Deleting: " << marker->getData() << "\n";
        delete marker;
    }
}

void DLList::clear()
{
    clear(head);
    head = tail = NULL;
    size = 0;
}
