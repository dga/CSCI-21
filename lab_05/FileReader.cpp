#include "FileReader.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::cerr;

bool FileReader::read(string filename, void (*f)(string, unsigned int, unsigned int))
{
    ifstream fin(filename.c_str());

    if (fin) {
        unsigned int lineNumber = 1;
        unsigned int columnNumber = 1;
        int nextLetter = fin.get();
        string nextWord = "";

        while (nextLetter != EOF) {
            if (isalpha(nextLetter))
                nextWord += tolower(nextLetter);
            else if (isspace(nextLetter)) {
                if (nextWord.length() > 0)
                    f(nextWord, lineNumber, columnNumber - nextWord.length());               
                nextWord = "";
                if (nextLetter == '\n') {
                    lineNumber++;
                    columnNumber = 0;
                }
            }
            nextLetter = fin.get();
            columnNumber++;
        }
        
        if (nextWord.length() > 0)
            f(nextWord, lineNumber, columnNumber - nextWord.length());

        fin.close();

        return true;
    } else {
        cerr << "Could not open file \"" << filename << "\" for reading.\n";

        return false;
    }
}
