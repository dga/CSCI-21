/*****************************
 * Name: Daniel G. Arnold    *
 * Course: CSCI 21           *
 * Project: Lab 1            *
 * Filename: hospital_ui.cpp *
 *****************************/

#include "hospital_ui.h"

HospitalUI::HospitalUI()
{
    cout << "How many patients would you like to manage? ";
    patientSum = reader.readInt();

    myPatients = new Patient[patientSum];

    cout << "You have chosen to manage " << patientSum << " patients.\n";
}

HospitalUI::~HospitalUI()
{
    delete [] myPatients;
}

void HospitalUI::go()
{
    cout << "\nEnloe Hospital ER Management System\n";

    while (mainMenu()) {};

    cout << "Program exited successfully.\n";
}

bool HospitalUI::mainMenu()
{
    bool proceed = true;
    
    cout <<
        "\nMenu:\n"
        "[1] View all patients\n"
        "[2] View single patient\n"
        "[3] Edit patient data\n"
        "[4] Cure Patient\n"
        "[0] Quit\n\n"
        "> ";
    
    switch (reader.readInt(true, 0, 4)) {
        case 0:
            proceed = false;
            
            break;
        case 1:
            viewAll();

            cout << "\nPress enter to continue...";
            reader.readString();
            
            break;
        case 2:
            viewSingle();

            cout << "\nPress enter to continue...";
            reader.readString();
            
            break;
        case 3:
            edit();
            
            cout << "\nPress enter to continue...";
            reader.readString();
            
            break;
        case 4:
            cure();

            cout << "\nPress enter to continue...";
            reader.readString();
            
            break;
    }

    return proceed;
}

void HospitalUI::viewAll()
{
    cout << "[#] Name\tId\n\n";
    for (int i = 0; i < patientSum; i++)
        cout << "[" << (i + 1) << "] " << myPatients[i].print(false)
            << endl;
}

void HospitalUI::viewSingle()
{
    unsigned int id = 0;
    bool idFound = false;

    cout << "Patient Id: ";
    id = reader.readInt();

    for (int i = 0; i < patientSum && !idFound; i++) {
        if (id == myPatients[i].getId()) {
            cout << myPatients[i].print() << endl;
            idFound = true;
        }
    }
    if (!idFound) {
        cout << "There is no patient associated with Id number " << id
            << ".\n";
    }
}

void HospitalUI::edit()
{
    int patientNumber = 0;
    
    cout << "Patient number: ";
    patientNumber = reader.readInt(true, 1, (patientSum));

    while (editMenu(patientNumber)) {}
}

bool HospitalUI::editMenu(int patientNumber)
{
    bool proceed = true;
    unsigned int id = 0;
    bool found = false;

    cout << "\nEdit Menu:\n";
    cout << "[1] Name\n";
    cout << "[2] Id\n";
    cout << "[3] Arrival\n";
    cout << "[4] Departure\n";
    cout << "[5] Charge\n";
    cout << "[6] Injury Type\n";
    cout << "[7] Injury Severity\n";
    cout << "[0] Return to Main\n\n";
    cout << "> ";

    switch (reader.readInt(true, 0, 7)) {
        case 0:
            proceed = false;

            break;
        case 1:
            cout << "Current name: "
                << myPatients[patientNumber - 1].getName() << endl;
            cout << "New name: ";
            myPatients[patientNumber - 1].setName(reader.readString());

            cout << "\nPress enter to continue...";
            reader.readString();

            break;
        case 2:
            cout << "Current Id: "
                << myPatients[patientNumber - 1].getId() << endl;
            cout << "New Id: ";
            id = reader.readInt();

            for (int i = 0; i < patientSum && !found; i++) {
                if (myPatients[i].getId() == id) {
                    found = true;
                }
            }

            if (found) {
                cout << "The Id " << id << " has already been assigned.\n";
            } else {
                myPatients[patientNumber - 1].setId(id);
            }

            cout << "\nPress enter to continue...";
            reader.readString();

            break;
        case 3:
            cout << "Current arrival time: "
                << myPatients[patientNumber - 1].getArrivalTime() << endl;
            cout << "New arrival time: ";
            myPatients[patientNumber - 1].setArrivalTime(reader.readInt(
                        0, 2359));

            cout << "\nPress enter to continue...";
            reader.readString();

            break;
        case 4:
            cout << "Current departure time: "
                << myPatients[patientNumber - 1].getDepartureTime()
                << endl;
            cout << "New departure time: ";
            myPatients[patientNumber - 1].setDepartureTime(
                    reader.readInt(0, 2359));

            cout << "\nPress enter to continue...";
            reader.readString();

            break;
        case 5:
            cout << "Current charge amount: $"
            << myPatients[patientNumber - 1].getChargeAmount() << endl;
            cout << "New charge amount: $";
            myPatients[patientNumber - 1].setChargeAmount(
                    reader.readDouble());

            cout << "\nPress enter to continue...";
            reader.readString();

            break;
        case 6:
            cout << "Current injury type: "
                << myPatients[patientNumber - 1].getInjuryType() << endl;
            cout << "New injury type: ";
            myPatients[patientNumber - 1].setInjuryType(
                    reader.readString());

            cout << "\nPress enter to continue...";
            reader.readString();

            break;
        case 7:
            cout << "Current injury severity: "
                << myPatients[patientNumber - 1].getInjurySeverity()
                << endl;
            cout << "New injury severity: ";
            myPatients[patientNumber - 1].setInjurySeverity(
                    reader.readInt());

            cout << "\nPress enter to continue...";
            reader.readString();

            break;
    }

    return proceed;
}

void HospitalUI::cure()
{
    unsigned int id = 0;
    bool alreadyTreated = false;

    for (int i = 0; i < patientSum; i++) {
        cout << "[" << (i + 1) << "] " << myPatients[i].getId()
           << " " << myPatients[i].getName() << "\t\t"
           << myPatients[i].getInjuryType() << "\t"
           << myPatients[i].getInjurySeverity() << endl;
    }
    
    cout << "\nPatient number: ";
    id = reader.readInt(true, 1, patientSum);

    if (myPatients[id - 1].getTreated()) {
        alreadyTreated = true;
        cout << "Patient " << id << " has already been treated.\n";
    } else {
        myPatients[id - 1].setCured(true);
        myPatients[id - 1].setTreated(true);

        if (myPatients[id - 1].getInjurySeverity() > 6) {
            if ((rand() % 5) == 3) {
                myPatients[id - 1].setCured(false);
                myPatients[id - 1].setName("*Deceased*");
                cout << "\nPatient " << id << " has died.\n";
                cout << "Time of death: ";
                myPatients[id - 1].setDepartureTime(reader.readInt(
                            true, 0, 2359));
            }
        }
        if (myPatients[id - 1].getCured()
                && !alreadyTreated) {
            myPatients[id - 1].setName("*Cured*");
            cout << "\nPatient " << id << " has been cured!\n";
            cout << "Departure time: ";
            myPatients[id - 1].setDepartureTime(reader.readInt(
                        true, 0, 2359));
        }
    }
}
