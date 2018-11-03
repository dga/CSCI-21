/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 2         *
 * Filename: bot.cpp      *
 **************************/

#include "bot.h"

Bot::Bot()
{
    stringstream ss;

    ss << "Bot" << (rand() % 50000) + 1;
    name = ss.str();
    strength = (rand() % 20) + 1;
    luck = (rand() % 25) + 1;
    experience = (rand() % 10) + 1;
    intelligence = (rand() % 4) + 1;
    sum = strength + luck + experience + intelligence;
    wins = 0;
    losses = 0;
    draws = 0;
}

Bot::Bot(string newName)
{
    name = newName;
    strength = (rand() % 20) + 1;
    luck = (rand() % 25) + 1;
    experience = (rand() % 10) + 1;
    intelligence = (rand() % 4) + 1;
    sum = strength + luck + experience + intelligence;
    wins = 0;
    losses = 0;
    draws = 0;
}

Bot::~Bot()
{
}

void Bot::setName(string newName)
{
    name = newName;
}

void Bot::setWins(int newWins)
{
    wins = newWins;
}

void Bot::setLosses(int newLosses)
{
    losses = newLosses;
}

void Bot::setDraws(int newDraws)
{
    draws = newDraws;
}

void Bot::setStrength(int newStrength)
{
    strength = newStrength;
}

void Bot::setLuck(int newLuck)
{
    luck = newLuck;
}

void Bot::setExperience(int newExperience)
{
    experience = newExperience;
}

void Bot::setIntelligence(int newIntelligence)
{
    intelligence = newIntelligence;
}

void Bot::setSum(int newSum)
{
    sum = newSum;
}


string Bot::getName()
{
    return name;
}

int Bot::getWins()
{
    return wins;
}

int Bot::getLosses()
{
    return losses;
}

int Bot::getDraws()
{
    return draws;
}

int Bot::getStrength()
{
    return strength;
}

int Bot::getLuck()
{
    return luck;
}

int Bot::getExperience()
{
    return experience;
}

int Bot::getIntelligence()
{
    return intelligence;
}

int Bot::getSum()
{
    return sum;
}

string Bot::print(bool longform)
{
    stringstream ss;

    if (longform) {
        ss << "Name: " << name << "\n";
        ss << "Wins: " << wins << "\n";
        ss << "Losses: " << losses << "\n";
        ss << "Draws: " << draws << "\n";
        ss << "Strength: " << strength << "\n";
        ss << "Luck: " << luck << "\n";
        ss << "Experience: " << experience << "\n";
        ss << "Intelligence: " << intelligence;

        return ss.str();
    }

    ss << "Name: " << name << "\t";
    ss << "Wins: " << wins << "\t";
    ss << "Losses: " << losses << "\t";
    ss << "Draws: " << draws;

    return ss.str();
}
