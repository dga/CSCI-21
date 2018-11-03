/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 2         *
 * Filename: team.cpp     *
 **************************/

#include "team.h"

Team::Team()
{
    name = "";
    size = 0;
    wins = 0;
    losses = 0;
    draws = 0;
    morale = 0;
    myBots = NULL;
}

Team::Team(string newName, int newSize)
{
	name = newName;
    size = newSize;
    wins = 0;
    losses = 0;
    draws = 0;
    morale = (rand() % 3) + 1;
    myBots = new Bot*[size];

    for (int i = 0; i < size; i++)
        myBots[i] = NULL;
}

Team::~Team()
{
    for (int i = 0; i < size; i++) {
        delete myBots[i];
        myBots[i] = NULL;
    }

    delete [] myBots;
    myBots = NULL;
}

void Team::setName(string newName)
{
    name = newName;
}

void Team::setWins(int newWins)
{
	wins = newWins;
}

void Team::setLosses(int newLosses)
{
	losses = newLosses;
}

void Team::setDraws(int newDraws)
{
    draws = newDraws;
}

void Team::setMorale(int newMorale)
{
	morale = newMorale;
}

Bot* Team::getBot(int slot)
{
	return myBots[slot];
}

string Team::getName()
{
	return name;
}

int Team::getSize()
{
    return size;
}

int Team::getWins()
{
	return wins;
}

int Team::getLosses()
{
	return losses;
}

int Team::getDraws()
{
    return draws;
}

int Team::getMorale()
{
	return morale;
}

bool Team::populate()
{
	for (int i = 0; i < size; i++)
		if (myBots[i] == NULL)
			myBots[i] = new Bot();

	return true;
}

bool Team::expunge()
{
	for (int i = 0; i < size; i++)
		if (myBots[i] != NULL) {
			delete myBots[i];
			myBots[i] = NULL;
		}

	return true;
}

bool Team::grow()
{
    Bot** temp = new Bot*[size * 2];

    for (int i = 0; i < size; i++)
        temp[i] = myBots[i];
    
    for (int i = size; i < (size * 2); i++)
        temp[i] = NULL;

    delete [] myBots;
    myBots = temp;
    temp = NULL;
    size *= 2;

    return true;
}

bool Team::grow(int newSize)
{
    if (newSize <= size)
        return false;
    
    Bot** temp = new Bot*[newSize];
    
    for (int i = 0; i < size; i++)
        temp[i] = myBots[i];
    
    for (int i = size; i < newSize; i++)
        temp[i] = NULL;
    
    delete [] myBots;
    myBots = temp;
    temp = NULL;
    size = newSize;

    return true;
}

bool Team::addBot()
{
    for (int i = 0; i < size; i++)
        if (myBots[i] == NULL) {
            myBots[i] = new Bot();

            return true;
        }

    return false;
}

bool Team::addBot(Bot* newBot)
{
    for (int i = 0; i < size; i++)
        if (myBots[i] == NULL) {
            myBots[i] = newBot;

            return true;
        }

    return false;
}

bool Team::addBot(Bot* newBot, int slot)
{
    if (myBots[slot - 1] == NULL) {
        myBots[slot - 1] = newBot;

        return true;
    }

    return false;
}

bool Team::removeBot()
{
    for (int i = 0; i < size; i++)
        if (myBots[i] != NULL) {
            delete myBots[i];
            myBots[i] = NULL;

            return true;
        }

    return false;
}

bool Team::removeBot(int slot)
{
    if (myBots[slot - 1] != NULL) {
        delete myBots[slot - 1];
        myBots[slot - 1] = NULL;

        return true;
    }

    return false;
}

string Team::print()
{
    stringstream ss;

    ss << "Team " << name << "\t";
    ss << "Wins: " << wins << "\t";
    ss << "Losses: " << losses << "\t";
    ss << "Draws: " << draws << "\t";
    ss << "Morale: " << morale << "\n\n";
    
    for (int i = 0; i < size; i++)
        ss << myBots[i]->print(false) << "\n";

    return ss.str();
}
