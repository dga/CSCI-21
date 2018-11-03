/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 1         *
 * Filename: patient.cpp  *
 **************************/

#include "patient.h"

Patient::Patient()
{
    fillInjuryList();
    name = "blah";
    id = (rand() + 1) % 10000;
    arrivalTime = 0;
    departureTime = 0;
    chargeAmount = 0;
    randomNumber = rand() % 14;
    injuryType = injuryList[randomNumber];
    injurySeverity = randomNumber + 1;
    treated = false;
    cured = false;
}

Patient::Patient(string uniqueName)
{
    fillInjuryList();
    name = uniqueName;
    id = (rand() + 1) % 10000;
    arrivalTime = 0;
    departureTime = 0;
    randomNumber = rand() % 14;
    injuryType = injuryList[randomNumber];
    injurySeverity = randomNumber + 1;
    treated = false;
    cured = false;
}

Patient::~Patient() {} // destructor

void Patient::fillInjuryList()
{
    injuryList[0] = "Bruise";
    injuryList[1] = "Sprained Ankle";
    injuryList[2] = "Cut";
    injuryList[3] = "Bee Sting";
    injuryList[4] = "Food Poisoning";
    injuryList[5] = "Broken Limb";
    injuryList[6] = "Burn";
    injuryList[7] = "Drug Overdose";
    injuryList[8] = "Chest Wound";
    injuryList[9] = "Head Wound";
    injuryList[10] = "Appendicitis";
    injuryList[11] = "Aneurysm";
    injuryList[12] = "Stroke";
    injuryList[13] = "Heart Attack";
}

// mutators/sets
void Patient::setName(string newName)
{
    name = newName;
}

void Patient::setTreated(bool newTreated)
{
    treated = newTreated;
}

void Patient::setCured(bool newCured)
{
    cured = newCured;
}

void Patient::setId(unsigned int newId)
{
    id = newId;
}

void Patient::setArrivalTime(unsigned short int newArrivalTime)
{
    arrivalTime = newArrivalTime;
}

void Patient::setDepartureTime(unsigned short int newDepartureTime)
{
    departureTime = newDepartureTime;
}

void Patient::setChargeAmount(double newChargeAmount)
{
    chargeAmount = newChargeAmount;
}

void Patient::setInjuryType(string newInjuryType)
{
    injuryType = newInjuryType;
}

void Patient::setInjurySeverity(unsigned short int newInjurySeverity)
{
    injurySeverity = newInjurySeverity;
}

// accessors/gets
string Patient::getName()
{
    return name;
}

bool Patient::getTreated()
{
    return treated;
}

bool Patient::getCured()
{
    return cured;
}

unsigned int Patient::getId()
{
    return id;
}

unsigned short int Patient::getArrivalTime()
{
    return arrivalTime;
}

unsigned short int Patient::getDepartureTime()
{
    return departureTime;
}

double Patient::getChargeAmount()
{
    return chargeAmount;
}

string Patient::getInjuryType()
{
    return injuryType;
}

unsigned short int Patient::getInjurySeverity()
{
    return injurySeverity;
}


string Patient::print(bool longform)
{
    stringstream ss;
    
    if (longform == true) {
        ss << "Name:\t\t\t\t" << name << "\n";
        ss << "Id:\t\t\t\t" << id << "\n";
        ss << "Arrival Time:\t\t\t" << arrivalTime << "\n";
        ss << "Departure Time:\t\t\t" << departureTime << "\n";
        ss << "Charge Amount:\t\t\t$" << chargeAmount << "\n";
        ss << "Injury Type:\t\t\t" << injuryType << "\n";
        ss << "Injury Severity:\t\t" << injurySeverity << "\n";
    } else
        ss << name << "\t" << id;

    return ss.str();
}
