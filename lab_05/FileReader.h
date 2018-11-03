#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>

using std::string;

/**
 * \author Daniel G. Arnold\n
 * A class that reads in a text file and sends individual words off to a remote function by means of a function pointer
 */
class FileReader
{
public:
    
    /**
     * Reads in the contents of a text file and passes individual words with their corresponding line and column numbers
     * to the function pointer
     * @param filename the filename of the file to be read
     * @param f the function pointer that points to the callback function
     * that provides the means for communication between the FileReader class and the DictionaryServices class
     * @return a bool indicating whether the file was successfully read or not by returning true or false, respectively
     */
    bool read(string filename, void (*f)(string, unsigned int, unsigned int));
};

#endif
