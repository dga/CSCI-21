/**************************
 * Name: Daniel G. Arnold *
 * Date: 3/31/07          *
 * Course: CSCI 21        *
 * Project: Lab 3         *
 * Filename: UI.cpp       *
 **************************/

#include "UI.h"

UI::UI()
{
    list = processor.getList();
    fileParser.setProcessor(processor);
}

UI::~UI()
{
}

void UI::go()
{
    while (mainMenu()) {}
}

bool UI::mainMenu()
{
    bool goAgain = true;

    cout << "\nMain Menu\n"
        << "---------\n"
        << "[1] Manual\n"
        << "[2] Automatic\n"
        << "[3] Help\n"
        << "[0] Quit\n\n"
        << "> ";

    switch (reader.readInt(true, 0, 3)) {
        case 0:
            cout << "\nProgram exited successfully.\n";
            return false;

            break;
        case 1:
            while (manualMenu()) {}

            break;
        case 2:
            cout << "\nEnter filename: ";
            fileParser.parse(reader.readString());
            cout << "\nPress enter to return to main menu...";
            reader.readString();

            break;
        case 3:
            help();

            cout << "\nPress enter to return to main menu...";
            reader.readString();

            break;
        default:
            break;
    }

    return true;
}

bool UI::manualMenu()
{
    int num = 0;

    cout << "\nManual Menu\n"
        << "-----------\n"
        << "[1] Insert front\n"
        << "[2] Insert rear\n"
        << "[3] Insert sorted\n"
        << "[4] Remove front\n"
        << "[5] Remove rear\n"
        << "[6] Search and remove\n"
        << "[7] Retrieve front\n"
        << "[8] Retrieve rear\n"
        << "[9] Search and retrieve\n"
        << "[10] Bump\n"
        << "[11] Sort\n"
        << "[12] Reverse\n"
        << "[13] Print\n"
        << "[14] Clear\n"
        << "[0]  Return to main menu\n"
        << "\nCurrent list size: ";
    if (list->getSize() == 0)
        cout << "Empty\n\n";
    else
        cout << list->getSize() << "\n\n";
    cout << "> ";

    switch (reader.readInt(true, 0, 14)) {
        case 0:
            return false;

            break;
        case 1:
            cout << "\nEnter a number: ";
            processor.process(2, reader.readInt());

            break;
        case 2:
            cout << "\nEnter a number: ";
            processor.process(3, reader.readInt());

            break;
        case 3:
            cout << "\nEnter a number: ";
            processor.process(4, reader.readInt());

            break;
        case 4:
            processor.process(5);

            break;
        case 5:
            processor.process(6);

            break;
        case 6:
            cout << "\nEnter a number: ";
            processor.process(7, reader.readInt());

            break;
        case 7:
            processor.process(8);

            break;
        case 8:
            processor.process(9);

            break;
        case 9:
            cout << "\nEnter a number: ";
            processor.process(10, reader.readInt());
            
            break;
        case 10:
            processor.process(11);

            break;
        case 11:
            processor.process(12);

            break;
        case 12:
            processor.process(13);

            break;
        case 13:
            processor.process(14);

            break;
        case 14:
            processor.process(15);

            break;
        default:
            cerr << "Invalid option.\n";

            break;
    }
    
    cout << "\nPress enter to continue...";
    reader.readString();

    return true;
}

void UI::help()
{
    cout << "\nHelp:\n"
        << "-----\n"
        << "(1) You can manipulate the list manually with the first option.\n"
        << "(2) With the second option, you can prepare a file for input and\n"
        << "    have the program parse commands from it and process the list\n"
        << "    automatically. The commands must be on their own line. They are\n"
        << "    listed as follows:\n\n"
        << "    Commands:\n\n"
        << "      -NS: Do not sort list (first line only)\n"
        << "      -SO: Keep sorted list (first line only)\n"
        << "      -AF #: Insert a node containing # at the front of the list\n"
        << "      -AR #: Insert a node containing # at the rear of the list\n"
        << "      -IN #: Insert a node containing # in a sorted list\n"
        << "      -RF: Remove a node from the front of the list\n"
        << "      -RR: Remove a node from the rear of the list\n"
        << "      -RE #: Remove a node containing # from the list\n"
        << "      -GF: Retrieve first node in the list\n"
        << "      -GR: Retrieve last node in the list\n"
        << "      -GP #: Retrieve node containing # from the list\n"
        << "      -BP: Increase the # contained in the nodes by 1\n"
        << "      -SL: Sort the list\n"
        << "      -RV: Reverse the list\n"
        << "      -PR: Print the list to the screen\n"
        << "      -CL: Clear the list\n"
        << "      -CO: Show list count\n";
}