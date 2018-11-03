/**************************
 * Name: Daniel G. Arnold *
 * Date: 3/31/07          *
 * Course: CSCI 21        *
 * Project: Lab 3         *
 * Filename: UI.h         *
 **************************/

#pragma once

#include "DLList.h"
#include "CinReader.h"
#include "Processor.h"
#include "FileParser.h"

/**
 * \author Daniel G. Arnold\n
 * A class for a basic user interface.
 */
class UI
{
public:

    /**
     * Default constructor.
     * Initialize this instance's data members to
     * list = processor.getList();
     */
    UI();

    /**
     * Deconstructor.
     * Does nothing.
     */
    ~UI();
    
    /**
     * Initiates the user interface.
     */
     void go();

private:
    
    Processor processor;
    FileParser fileParser;
    CinReader reader;
    DLList* list;
    
    bool mainMenu();
    bool manualMenu();
    void help();
};