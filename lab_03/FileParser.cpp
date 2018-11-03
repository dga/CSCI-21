/****************************
 * Name: Daniel G. Arnold   *
 * Course: CSCI 21          *
 * Project: Lab 3           *
 * Filename: FileParser.cpp *
 ****************************/

#include "FileParser.h"

FileParser::FileParser()
{
}

void FileParser::setProcessor(Processor& newProcessor)
{
    processor = &newProcessor;
}

void FileParser::parse(string filename)
{
    stringstream ss;
    string line;
    string op;
    int arg = 0;
    ifstream fin(filename.c_str());

    if (fin) {
        if (getline(fin, line)) {
            ss.str(line);

            if (ss >> op)
                if (op == "NS")
                    processor->process(0);
                else if (op == "SO")
                    processor->process(1);

            ss.clear();

            while (getline(fin, line)) {
                ss.clear();
                ss.str(line);

                if (ss >> op)
                    if (op == "AF") {
                        if (ss >> arg)
                            processor->process(2, arg);
                    } else if (op == "AR") {
                        if (ss >> arg)
                            processor->process(3, arg);
                    } else if (op == "IN") {
                        if (ss >> arg)
                            processor->process(4, arg);
                    } else if (op == "RF") {
                        processor->process(5);
                    } else if (op == "RR") {
                        processor->process(6);
                    } else if (op == "RE") {
                        if (ss >> arg)
                            processor->process(7);
                    } else if (op == "GF") {
                        processor->process(8);
                    } else if (op == "GR") {
                        processor->process(9);
                    } else if (op == "GP") {
                        if (ss >> arg)
                            processor->process(10);
                    } else if (op == "BP") {
                        processor->process(11);
                    } else if (op == "SL") {
                        processor->process(12);
                    } else if (op == "RV") {
                        processor->process(13);
                    } else if (op == "PR") {
                        processor->process(14);
                    } else if (op == "CL") {
                        processor->process(15);
                    } else if (op == "CO") {
                        processor->process(16);
                    }
            }

            fin.close();
        }
    } else
        cerr << "Could not open file \"" << filename << "\" for reading.\n";
}
