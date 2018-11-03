/**************************
 * Name: Daniel G. Arnold *
 * Date: 3/31/07          *
 * Course: CSCI 21        *
 * Project: Lab 3         *
 * Filename: Processor.h  *
 **************************/

#pragma once

#include <stdexcept>
#include "DLList.h"
#include "CinReader.h"

/**
 * \author Daniel G. Arnold\n
 * A class that processes list operations.
 */
class Processor
{
public:
    
    /**
     * Default constructor.
     * Initialize this instance's data members to
     * sorted = false;
     * num = 0;
     */
    Processor();

    /**
     * Process commands given by either the user or a file.
     * @param int command an int containing the numeric command code to be processed
     * @param int argument an int containing the data argument to accompany the command
     */
    void process(int command, int argument = 0);
    
    /**
     * Retrieve a reference to this instance's 'list' variable.
     * @return a DLList* containing the address of the 'list' variable
     */
    DLList* getList();

private:

    DLList list;
    CinReader reader;
    bool sorted;
    int num;
};