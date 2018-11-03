/*
 * Copyright (c) 2007, Daniel G. Arnold
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 *    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *      disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *      following disclaimer in the documentation and/or other materials provided with the distribution.
 *    * The name of the author may not be used to endorse or promote products derived from this software without 
 *      specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Filename: Word.h
 * Last revised: 5/23/07
 */

#ifndef WORD_H
#define WORD_H

#include <string>
#include <list>

using std::string;
using std::list;

/**
 * \author Daniel G. Arnold\n
 * A class to store individual words and their corresponding column and line numbers
 */
class Word
{
public:

    /**
     * Default constructor.
     * Initializes this instance's data members to
     * data = ""
     * count = 1
     */
    Word();

    /**
     * Overloaded constructor.
     * Initializes this instance's data members to
     * data = word
     * count = 1
     */
    Word(string word);
    
    /**
     * Destructor.
     * Does nothing
     */
    ~Word();

    /**
     * Assigns a new value to this instance's 'data' variable.
     * @param newData the value to be stored in the 'data' variable
     */
    void setData(string newData);
    
    /**
     * Assigns a new value to this instance's 'count' variable.
     * @param newCount the value to be stored in the 'count' variable
     */
    void setCount(unsigned int newCount);
    
    /**
     * Adds a new line number to this instance's 'lines' variable.
     * @param newLine the new line number to be added to the 'lines' variable
     */
    void setLines(unsigned int newLine);
    
    /**
     * Adds a new column number to this instance's 'columns' variable.
     * @param newColumn the new column number to be added to the 'columns' variable
     */
    void setColumns(unsigned int newColumn);

    /**
     * Retrieves the value of this instance's 'data' variable.
     * @return a string containing the value of the 'data' variable
     */
    string getData() const;
    
    /**
     * Retrieves the value of this instance's 'count' variable.
     * @return an unsigned int containing the value of the 'count' variable
     */
    unsigned int getCount() const;

    /**
     * Retrieves the value of this instance's 'lines' variable.
     * @return a list<unsigned int> containing the line numbers of the 'lines' variable
     */
    list<unsigned int> getLines() const;

    /**
     * Retrieves the value of this instance's 'columns' variable.
     * @return a list<unsigned int> containing the column numbers of the 'columns' variable
     */
    list<unsigned int> getColumns() const;

private:

    string data;
    unsigned int count;
    list<unsigned int> lines;
    list<unsigned int> columns;
};

#endif