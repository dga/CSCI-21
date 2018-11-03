/***************************
 * Name: Daniel G. Arnold  *
 * Course: CSCI 21         *
 * Project: Lab 3          *
 * Filename: Processor.cpp *
 ***************************/

#include "Processor.h"

Processor::Processor()
{
    sorted = false;
    num = 0;
}

void Processor::process(int command, int argument)
{
    try {
        switch (command) {
            case 0:
                cout << "List will not be sorted.\n";
                sorted = false;
                
                break;
            case 1:
                cout << "List will be sorted.\n";
                sorted = true;
                
                break;
            case 2:
                if (list.get(argument) != NULL)
                    throw argument;
                
                list.insertHead(argument);
                cout << argument << " added to front of list.\n";
                
                break;
            case 3:
                if (list.get(argument) != NULL)
                    throw argument;
                
                list.insertTail(argument);
                cout << argument << " added to rear of list.\n";
                
                break;
            case 4:
                if (list.get(argument) != NULL)
                    throw argument;
                
                if (sorted) {
                    list.insert(argument);
                    cout << argument << " inserted to list.\n";
                } else
                    cout << "List must be sorted.\n";
                
                break;
            case 5:
           if (list.getSize() > 0) {
                num = list.getHead()->getData();
                list.removeHead();
                cout << num << " removed from front of list.\n";
            } else
                cout << "RF: Cannot remove node from empty list.\n";

            break;
        case 6:
            if (list.getSize() > 0) {
                num = list.getTail()->getData();
                list.removeTail();
                cout << num << " removed from rear of list.\n";
            } else
                cout << "RR: Cannot remove node from empty list.\n";

            break;
        case 7:
            if (list.getSize() > 0) {
                list.remove(argument);
                cout << argument << " removed from list.\n";
            } else
                cout << "RE " << argument << ": Cannot remove node from empty list.\n";

            break;
        case 8:
            if (list.getSize() > 0)
                cout << list.getHead()->getData() << " retrieved from front.\n";
            else
                cout << "GF: Cannot retrieve from empty list.\n";

            break;
        case 9:
            if (list.getSize() > 0)
                cout << list.getTail()->getData() << " retrieved from rear.\n";
            else
                cout << "GR: Cannot retrieve from empty list.\n";

            break;
        case 10:
            if (list.getSize() > 0)
                if (list.get(argument) != NULL)
                    cout << argument << " found in list.\n";
                else
                    cout << argument << " could not be found in list.\n";
            else
                cout << "GP " << argument << ": Cannot retrieve from empty list.\n";

            break;
        case 11:
            if (list.getSize() > 0) {
                list.bump();
                cout << "List values increased be 1.\n";
            } else
                cout << "BP: Cannot bump empty list.\n";
            
            break;
        case 12:
            if (list.getSize() > 0) {
                list.sort();
                sorted = true;
                cout << "List is now sorted.\n";
            } else
                cout << "SL: Cannot sort empty list.\n";

            break;
        case 13:
            if (list.getSize() > 0) {
                list.reverse();
                cout << "List reversed.\n";
            } else
                cout << "RV: Cannot reverse empty list.\n";

            break;
        case 14:
            if (list.getSize() > 0)
                list.print();
            else
                cout << "PR: Cannot print empty list.\n";
            
            break;
        case 15:
            if (list.getSize() > 0)
                list.clear();
            else
                cout << "CL: Cannot clear empty list.\n";

            break;
        case 16:
            if (list.getSize() > 0)
                cout << "There are " << list.getSize() << " nodes in the list.\n";
            else
                cout << "The list is empty.\n";

            break;
        default:
            cerr << "Error: Invalid selection.\n";

            break;
    }
    }
    catch(int e)
    {
        cout << "\nException: " << e << " is already in the list.\n\n"
            << "Press enter to resume normal program execution...";
        reader.readString();
    }
    }

DLList* Processor::getList()
{
    return &list;
}
