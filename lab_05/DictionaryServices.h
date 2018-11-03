#ifndef DICTIONARYSERVICES_H
#define DICTIONARYSERVICES_H

#include "Word.h"
#include "BSTree.h"
#include "CinReader.h"

/**
 * \author Daniel G. Arnold\n
 * A class that provides the program with tree functionality by means of function pointers
 */
class DictionaryServices
{
public:
    
    // Static member declarations
    
    /**
     * The binary search tree that this program depends on for just about everything.
     */
    static BSTree<Word*> dictionary;
    
    /**
     * The object for gathering user input.
     */
    static CinReader userInput;

    /**
     * The line number specified by the user for use with the 'printLine' function.
     */
    static unsigned int theLine;

    /**
     * The column number specified by the user for use with the 'printColumn' function.
     */
    static unsigned int theColumn;
    
    /**
     * The number used to keep track of the word(s) with the most occurrences.
     */
    static unsigned int most;
    
    /**
     * The number used to keep track of the word(s) with the least occurrences.
     */
    static unsigned int least;
    
    /**
     * The number used to keep track of the length of the longest word(s).
     */
    static unsigned int largest;
    
    /**
     * The number used to keep track of the length of the smallest word(s).
     */
    static unsigned int smallest;
    
    /**
     * This number is used as a generic loop counter.
     */
    static unsigned int counter;
    
    /**
     * The number used to keep track of how many lines have been printed to the screen with the 'print' function.
     */
    static unsigned int times;
    
    /**
     * The value used to tell the 'print' function when to halt execution.
     */
    static bool stop;
    
    /**
     * Indicator of whether or not a matching word for some criteria was found.
     */
    static bool success;
    
    /**
     * The letter specified by the user for use with the 'startsWith' function.
     */
    static char theLetter;
    
    /**
     * Deallocates a Word instance from the heap.
     */
    static void destroy(Word*);
    
    /**
     * Prints out all words that start with a letter specified in the 'theLetter' variable.
     */
    static void startsWith(Word*);
    
    /**
     * Prints out all of the words on a line specified in the 'theLine' variable.
     */
    static void printLine(Word*);
    
    /**
     * Gathers some interesting statistics.
     */
    static void getStats(Word*);

    /**
     * Prints out the most commonly occurring word(s).
     */
    static void printMostCommon(Word*);
    
    /**
     * Prints out the least commonly occuring word(s).
     */
    static void printLeastCommon(Word*);
    
    /**
     * Prints out the longest word(s).
     */
    static void printLargest(Word*);
    
    /**
     * Prints out the shortest word(s).
     */
    static void printSmallest(Word*);
    
    /**
     * Prints out all of the words in a column number specified in the 'theColumn' variable.
     */
    static void printColumn(Word*);
    
    /**
     * Prints out a word, its number of occurrences and its corresponding column and line numbers.
     */
    static void print(Word*);
    
    /**
     * The callback function that is responsible for getting words from the FileReader and putting them into the tree.
     */
    static void callback(string, unsigned int, unsigned int);
    
    /**
     * Provides the ability to compare nodes' data outside of the tree so the tree doesn't have to.
     */
    static int compare(Word*, Word*);

private:
};

#endif
