/***************************
 * Name: Daniel G. Arnold  *
 * Course: CSCI 21         *
 * Project: Lab 1          *
 * Filename: hospital_ui.h *
 ***************************/

#pragma once

#include "CinReader.h"
#include "patient.h"

#include <iostream>
using namespace std;

/**
 * \author Daniel G. Arnold\n
 * A class to create an instance of a user interface for the Hospital
 * program.
 */
class HospitalUI
{
    public:
  
        /**
         * Default constructor.
         * Prompt the user for the number of Patient instances they want to 
         * create and then dynamically allocate the new instances on the
         * heap. Print a line telling how many instances they've just
         * created.
         */
        HospitalUI();

        /**
         * Destructor.
         * Remove the dynamic array of patients from the heap.
         */
        ~HospitalUI();

        /**
         * Initiate the program's user interface.
         */
        void go();

    private:

        CinReader reader;
        Patient* myPatients;
        unsigned int patientSum;

        bool mainMenu();
        void viewAll();
        void viewSingle();
        void edit();
        bool editMenu(int patientNumber);
        void cure();
};
