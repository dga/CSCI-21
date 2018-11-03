/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 2         *
 * Filename: bot.h        *
 **************************/

#pragma once

#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using std::string;
using std::stringstream;

/**
 * \author Daniel G. Arnold\n
 * A class to represent a bot in a fighting arena.
 */
class Bot
{
public:
    
    /**
     * Default constructor.
     * Initialize this instance's data members to
     * name = ss.str();
     * strength = (rand() % 20) + 1;
     * luck = (rand() % 25) + 1;
     * experience = (rand() % 10) + 1;
     * intelligence = (rand() % 4) + 1;
     * sum = strength + luck + experience + intelligence;
     * wins = 0;
     * losses = 0;
     * draws = 0;
     */
    Bot();
    
    /**
     * Overloaded constructor.
     * Initialize this instance's data members to
     * name = string
     * strength = (rand() % 20) + 1;
     * luck = (rand() % 25) + 1;
     * experience = (rand() % 10) + 1;
     * intelligence = (rand() % 4) + 1;
     * sum = strength + luck + experience + intelligence;
     * wins = 0;
     * losses = 0;
     * draws = 0;
     */
    Bot(string);
    
    /**
     * Destructor.
     * Does nothing.
     */
    ~Bot();
    
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
     * Assign a new value for this instance's 'draws' variable.
     * @param int the value for the 'draws' variable
     */
    void setDraws(int);

    /**
     * Assign a new value for this instance's 'strength' variable.
     * @param int the value for the 'strength' variable
     */
    void setStrength(int);

    /**
     * Assign a new value for this instance's 'luck' variable.
     * @param int the value for the 'luck' variable
     */
    void setLuck(int);

    /**
     * Assign a new value for this instance's 'experience' variable.
     * @param int the value for the 'experience' variable
     */
    void setExperience(int);

    /**
     * Assign a new value for this instance's 'intelligence' variable.
     * @param int the value for the 'intelligence' variable
     */
    void setIntelligence(int);

    /**
     * Assign a new value for this instance's 'sum' variable.
     * @param int the value for the 'sum' variable
     */
    void setSum(int);

    /**
     * Retrieve the value of this instance's 'name' variable.
     * @return a string containing the value of the 'name' variable
     */
    string getName();

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
     * Retrieve the value of this instance's 'strength' variable.
     * @return an int containing the value of the 'strength' variable
     */
    int getStrength();

    /**
     * Retrieve the value of this instance's 'luck' variable.
     * @return an int containing the value of the 'luck' variable
     */
    int getLuck();

    /**
     * Retrieve the value of this instance's 'experience' variable.
     * @return an int containing the value of the 'experience' variable
     */
    int getExperience();

    /**
     * Retrieve the value of this instance's 'intelligence' variable.
     * @return an int containing the value of the 'intelligence' variable
     */
    int getIntelligence();

    /**
     * Retrieve the sum of this instance's 'strength', 'luck', 'experience' and 'intelligence' variables.
     * @return an int containing the sum of the 'strength', 'luck', 'experience' and 'intelligence' variables
     */
    int getSum();

    /**
     * Retrieve a string representation of this instance.
     * The string returned in its longform will contain labels for each variable and the value of the variable, e.g.,
     * "Name: John Smith"; in its short form, only data separated by tabs on a single line
     * @param longform if true, print with labels and data, else print data only on a single line
     * @return a string containing the long or short form of this Bot's member data
     */
    string print(bool longform = true);

private:
    
    string name;
    int wins;
    int losses;
    int draws;
    int strength;
    int luck;
    int experience;
    int intelligence;
    int sum;
};
