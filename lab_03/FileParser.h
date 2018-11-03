/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 3         *
 * Filename: FileParser.h *
 **************************/

#pragma once

#include <fstream>
#include <string>
#include <sstream>
#include "Processor.h"
#include "CinReader.h"

/**
 * \author Daniel G. Arnold\n
 * A class that parses commands from an input file.
 */
class FileParser
{
public:

    /**
     * Default constructor.
     * Does nothing.
     */
    FileParser();

    /**
     * Assign a new value to the 'processor' variable.
     * @param Processor& newProcessor the new value of the 'processor' variable
     */
    void setProcessor(Processor& newProcessor);
    
    /**
     * Read a file line-by-line and parse out commands to pass to the processor.
     * Legend:
     *   NS = 0
     *   SO = 1
     *   AF = 2
     *   AR = 3
     *   IN = 4
     *   RF = 5
     *   RR = 6
     *   RE = 7
     *   GF = 8
     *   GR = 9
     *   GP = 10
     *   BP = 11
     *   SL = 12
     *   RV = 13
     *   PR = 14
     *   CL = 15
     *   CO = 16
     * @param string filename the name of the file to be read in
     */
    void parse(string filename);

private:

    Processor* processor;
    CinReader reader;
};
