#ifndef CIN_READER_H
#define CIN_READER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <sstream>

using namespace std;

/**
 *   A class for handling keyboard input.  CinReader provides
 *   functions for reading all of the C++ primitive data types
 *   and C++ strings, and performs error checking on the input.
 */
 class CinReader
{
	public:
	
		/**
		 *  Constructor.
		 *  CinReader has no data members.  The default constructor
		 *  is provided to reinforce OO ideas and practices.
		 */
		CinReader ();
		
		/**
		 *  Destructor.
		 *  CinReader performs no dynamic memory allocation.  Destructor
		 *  is provided for thoroughness and to reinforce good OO/C++ 
		 *  programming practices.
		 */
		~CinReader ();
		
		/**
		 *  Read integer input from the keyboard.
		 *  Used with no arguments, the function will return an integer between
		 *  INT_MIN and INT_MAX.  Optionally the function can be called
		 *  with user-specified upper and lower limits.
		 * @param ul if true, limit keyboard input to user-specified range
		 * @param l if provided, sets the lower limit of the input
		 * @param u if provided, sets the upper limit of the input
		 * @return an integer between INT_MIN and INT_MAX if called with
		 *               no arguments, or between l and u
		 */
		int readInt (bool ul=false, int l=-1, int u=-1);
		
		/**
		 *  Read double input from the keyboard.
		 *  Unlike readInt, this function does not limit the range of the
		 *  input value.
		 *  @return a double
		 */
		double readDouble ();
		
		/**
		 *  Read float input from the keyboard.
		 *  Unlike readInt, this function does not limit the range of the
		 *  input value.
		 *  @return a float
		 */
		float readFloat ();
		
		/**
		 *  Read input from the keyboard as a boolean value.
		 *  Will accept "T", "F" or "TRUE", "FALSE" as input and will
		 *  return a corresponding boolean value.  The function is NOT
		 *  case sensitive, it will accept input as any combination of
		 *  uppercase and lowercase characters.
		 *  @return a bool
		 */
		bool readBool ();
		
		/**
		 * Read char input from the keyboard.
		 *  Used with no arguments, the function will return the char entered at 
		 *  the keyboard.  Optionally, a range of acceptable inputs can
		 *  be specified.  The range must be written as a list of chars, such as
		 *  "abcdef".
		 *  @param range the range of acceptable inputs
		 *  @return a char that is a member of range if specified, or
		 *                 any single char if no range is provided
		 */
		char readChar (string range="");
		
		/**
		 *  Read string input from the keyboard.
		 *  Used with no arguments, the function will return the string
		 *  entered at the keyboard, which can include an empty string.
		 *  @param allowEmpty if true, allow empty string as input, else
		 *                 require at least one character of input
		 *  @param limitTo if 0, do not limit the number of characters of
		 *                 input; if not 0, return only "limitTo" number of
		 *                 characters
		 *  @return a string
		 */
		string readString (bool allowEmpty = true, unsigned int limitTo = 0);
		
	private:
		
		string stripCommas (string input);
		bool testIntInput (string, string&, int l=-1, int u=-1);
		bool testDoubleInput (string);
		bool testCharInput (char, string);
		bool testBoolInput (string);
		bool getBoolValue (string);
		void toUpperCase (string&);
		bool ignoreCaseCompare (string, string);
};

#endif

