/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 1         *
 * Filename: hospital.cpp *
 **************************/

#include "hospital_ui.h"

int main()
{
    HospitalUI* ui = new HospitalUI;

    ui->go();

    delete ui;

    return 0;
}
