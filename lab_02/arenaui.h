/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 2         *
 * Filename: arenaui.h    *
 **************************/

#pragma once

#include "team.h"
#include "CinReader.h"
#include <ctime>

/**
 * \author Daniel G. Arnold\n
 * A class used to create an instance of the user interface for the Battle Bots program.
 */
class ArenaUI
{
public:
    /**
     * Default constructor.
     * Initialize this instance's variables to
     * teamOne = NULL;
     * teamTwo = NULL;
     * Seed the pseudo-random number generator with time(NULL).
     */
    ArenaUI();

    /**
     * Destructor.
     * Deallocate both teams and assign to them the value NULL.
     */
    ~ArenaUI();

    /**
     * Initiate the program's user interface.
     */
    void go();

private:
    
    CinReader reader;
    Team* teamOne;
    Team* teamTwo;
    
    bool mainMenu();
    bool teamMenu();
    void createTeams();
    void startBattle();
};
