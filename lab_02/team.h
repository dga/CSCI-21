/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 2         *
 * Filename: team.h       *
 **************************/

#pragma once

#include "bot.h"

/**
 * \author Daniel G. Arnold\n
 * A class to represent a team of bots in a fighting arena.
 */
class Team
{
public:

    /**
     * Default constructor.
     * Initialize this instance's data members to
     * name = "";
     * size = 0;
     * wins = 0;
     * losses = 0;
     * draws = 0;
     * morale = 0;
     * myBots = NULL;
     */
    Team();
    
    /**
     * Overloaded constructor.
     * Initialize this instance's data members to
     * name = string newName;
     * size = int newSize;
     * wins = 0
     * losses = 0;
     * draws = 0;
     * morale = (rand() % 3) + 1;
     * myBots = new Bot*[size];
     * for (int i = 0; i < size; i++) myBots[i] = NULL;
     */
    Team(string, int);

    /**
     * Destructor.
     * Clear this instance's dynamically allocated data.
     * Deletes each Bot object from the heap.
     * Deletes array of pointers to Bot from the heap.
     * myBots = NULL
     */
    ~Team();

    /**
     * Assign a new value to this instance's 'name' variable.
     * @param string the value for the 'name' variable
     */
    void setName(string);

    /**
     * Assign a new value to this instance's 'wins' variable.
     * @param int the value for the 'wins' variable
     */
    void setWins(int);

    /**
     * Assign a new value to this instance's 'losses' variable.
     * @param int the value for the 'losses' variable
     */
    void setLosses(int);

    /**
     * Assign a new value to this instance's 'draws' variable.
     * @param int the value for the 'draws' variable
     */
    void setDraws(int);

    /**
     * Assign a new value to this instance's 'morale' variable.
     * @param int the value for the 'morale' variable
     */
    void setMorale(int);

    /**
     * Retrieve a pointer to a Bot from this instance.
     * @param int the slot from which to access a pointer to Bot
     * @return Bot* a pointer to a Bot from the **myBot variable
     */
    Bot* getBot(int);

    /**
     * Retrieve the value of this instance's 'name' variable.
     * @return a string containing the value of the 'name' variable
     */
    string getName();

    /**
     * Retrieve the value of this instance's 'size' variable.
     * @return an int containing the value of the 'size' variable
     */
    int getSize();

    /**
     * Retrieve the value of this instance's 'wins' variable.
     * @return an int containing the value of the 'wins' variable
     */
    int getWins();

    /**
     * Retrieve the value of this instance's 'losses' variable.
     * @return an int containing the value of the 'losses' variable
     */
    int getLosses();

    /**
     * Retrieve the value of this instance's 'draws' variable.
     * @return an int containing the value of the 'draws' variable
     */
    int getDraws();

    /**
     * Retrieve the value of this instance's 'morale' variable.
     * @return an int containing the value of the 'morale' variable
     */
    int getMorale();
    
    /**
     * Allocate Bot objects for pointers to Bot contained in **myBots that point to NULL.
     * @return a bool with the value true on success
     */
    bool populate();

    /**
     * Deallocate Bot objects for pointers to Bot contained in **myBots that do not point to NULL.
     * @return a bool with the value true on success
     */
    bool expunge();

    /**
     * Resize **myBots to twice its original size.
     * Create a new array of pointers to Bot and allocate size*2 pointers. Copy the pointers to Bot in **myBots to
     * the temporary array and then NULL out the rest of the array. Deallocate the pointers to Bot in **myBots. Copy 
     * the address of the temporary array into **myArray. Assign NULL to temp and change size to twice its original
     * size.
     * @return a bool with the value true on success
     */
    bool grow();

    /**
     * Resize **myBots to n, where n is a number more than 'size'.
     * Create a new array of pointers to Bot and allocate 'newSize' pointers. Copy the pointers to Bot in **myBots to
     * the temporary array and then NULL out the rest of the array. Deallocate the pointers to Bot in **myBots. Copy
     * the address of the temporary array into **myArray. Assign NULL to the temporary array and change size to
     * 'newSize'.
     * @return a bool with the value true on success
     */
    bool grow(int);

    /**
     * Allocate a Bot object to the first pointer with the value NULL.
     * @return a bool with the value true on success; false if no NULL pointers found
     */
    bool addBot();
    
    /**
     * Assign the address of a Bot object passed in to the first pointer with the value NULL.
     * @return a bool with the value true on success; false if no NULL pointers found
     */
    bool addBot(Bot*);

    /**
     * Assign the address of a Bot object passed in to a pointer to Bot specified by the int passed in as the slot.
     * The specified slot must be pointing to NULL.
     * @return a bool with the value true on success; false if the slot specified is not NULL
     */
    bool addBot(Bot*, int);

    /**
     * Deallocate a Bot object from the first pointer to Bot found that does not point to NULL.
     * @return a bool with the value true on success; false if only NULL pointers found
     */
    bool removeBot();

    /**
     * Deallocate a Bot object from a pointer to Bot specified by the int passed in as the slot. The specified slot
     * must not point to NULL.
     * @return a bool with the value true on success; false if the slot specified is NULL
     */
    bool removeBot(int);

    /**
     * Retrieve a string representation of this instance.
     * The string returned will contain labels for each variable and the value of the variable, e.g., "Name: Blah".
     * It will then print details about each bot.
     * @return a string containing labels and values for team and bot data
     */
    string print();

private:
    
    Bot** myBots;
    string name;
    int size;
    int wins;
    int losses;
    int draws;
    int morale;
};
