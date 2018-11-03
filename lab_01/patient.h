/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 1         *
 * Filename: patient.h    *
 **************************/

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

/**
 * \author Daniel G. Arnold\n
 * A class to represent a patient in a hospital.
 */
class Patient
{
    public:

        /**
         * Default constructor.
         * Initialize this instance's data members to
         * name = "blah"
         * id = (rand() + 1) % 10000;
         * arrivalTime = 0;
         * departureTime = 0
         * chargeAmount = 0;
         * randomNumber = rand() % 14;
         * injuryType = injuryList[randomNumber];
         * injurySeverity = randomNumber + 1;
         * treated = false;
         * cured = false;
         */
        Patient();

        /**
         * Overloaded constructor.
         * Initialize this instance's data members to
         * name = string uniqueName
         * id = (rand() + 1) % 10000;
         * arrivalTime = 0;
         * departureTime = 0;
         * chargeAmount = 0;
         * randomNumber = rand() % 14;
         * injuryType = injuryList[randomNumber];
         * injurySeverity = randomNumber + 1;
         * treated = false;
         * cured = false;
         */
        Patient(string uniqueName);
        
        /**
         * Destructor.
         * Does nothing.
         */
        ~Patient();

        /**
         * Assign new values to each element of this instance's
         * 'injuryList' array.
         */
        void fillInjuryList();
        
        /**
         * Assign a new value to this instance's 'name' variable.
         * @param newName the value for the 'name' variable
         */
        void setName(string newName);

        /**
         * Assign a new value to this instance's 'treated' variable.
         * @param newTreated the value for the 'treated' variable
         */
        void setTreated(bool newTreated);

        /**
         * Assign a new value to this instance's 'cured' variable.
         * @param newCured the value for the 'cured' variable
         */
        void setCured(bool newCured);

        /**
         * Assign a new value to this instance's 'id' variable.
         * @param newId the new value for the 'id' variable
         */
        void setId(unsigned int newId);

        /**
         * Assign a new value to this instance's 'arrivalTime' variable.
         * @param newArrivalTime the value for the new 'arrivalTime' 
         * variable
         */
        void setArrivalTime(unsigned short int newArrivalTime);

        /**
         * Assign a new value to this instance's 'departureTime' variable.
         * @param newDepartureTime the value for the new 'departureTime' 
         * variable
         */
        void setDepartureTime(unsigned short int newDepartureTime);

        /**
         * Assign a new value to this instance's 'chargeAmount' variable.
         * @param newChargeAmount the value for the new 'chargeValue' 
         * variable
         */
        void setChargeAmount(double newChargeAmount);

        /**
         * Assign a new value to this instance's 'injuryType' variable.
         * @param newInjuryType the value for the new 'injuryType' variable
         */
        void setInjuryType(string newInjuryType);

        /**
         * Assign a new value to this instance's 'injurySeverity' variable.
         * @param newInjurySeverity the value for the new 'injurySeverity'
         * variable
         */
        void setInjurySeverity(unsigned short int newInjurySeverity);

        /**
         * Retrieve the value of this instance's 'name' variable.
         * @return a string containing the value of the 'name' variable
         */
        string getName();

        /**
         * Retrieve the value of this instance's 'treated' variable.
         * @return a bool containing the value of the 'treated' variable
         */
        bool getTreated();

        /**
         * Retrieve the value of this instance's 'cured' variable.
         * @return a bool containing the value of the 'cured' variable
         */
        bool getCured();

        /**
         * Retrieve the value of this instance's 'id' variable.
         * @return an unsigned short int containing the value of the 'id' 
         * variable
         */
        unsigned int getId();

        /**
         * Retrieve the value of this instance's 'arrivalTime' variable.
         * @return an unsigned short int containing the value of the 
         * 'arrivalTime' variable
         */
        unsigned short int getArrivalTime();

        /**
         * Retrieve the value of this instance's 'departureTime' variable.
         * @return an unsigned short int containing the value of the
         * 'departureTime' variable
         */
        unsigned short int getDepartureTime();
        
        /**
         * Retrieve the value of this instance's 'chargeAmount' variable.
         * @return a double containing the value of the 'chargeAmount' 
         * variable
         */
        double getChargeAmount();
        
        /**
         * Retrieve the value of this instance's 'injuryType' variable.
         * @return an unsigned short int containing the value of the 
         * 'injuryType' variable
         */
        string getInjuryType();
        
        /**
         * Retrieve the value of this instance's 'injurySeverity' variable.
         * @return an unsigned short int containing the value of the 
         * 'injurySeverity' variable
         */
        unsigned short int getInjurySeverity();

        /**
         * Retrieve a string representation of this instance.
         * The string returned in its longform will contain labels for each
         * variable and the value of the variable, e.g., "name: John Smith";
         * in its short form, only data separated by tabs on a single line
         * @param longform if true, print with labels and data, else print 
         * data only on a single line
         * @return a string containing the long or short form of this 
         * Patient's member data
         */
        string print(bool longform = true);

    private:

        string name;
        bool treated;
        bool cured;
        unsigned int id;
        unsigned short int arrivalTime;
        unsigned short int departureTime;
        double chargeAmount;
        string injuryType;
        unsigned short int injurySeverity;
        string injuryList[14];
        int randomNumber;
};
