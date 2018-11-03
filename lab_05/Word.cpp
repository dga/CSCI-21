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
 * Filename: Word.cpp
 * Last revised: 5/23/07
 */

#include "Word.h"

Word::Word()
{
    data = "";
    count = 1;
}

Word::Word(string word)
{
    data = word;
    count = 1;
}

Word::~Word()
{
}

void Word::setData(string newData)
{
    data = newData;
}

void Word::setCount(unsigned int newCount)
{
    count = newCount;
}

void Word::setLines(unsigned int newLine)
{
    lines.push_back(newLine);
}

void Word::setColumns(unsigned int newColumn)
{
    columns.push_back(newColumn);
}

string Word::getData() const
{
    return data;
}

unsigned int Word::getCount() const
{
    return count;
}

list<unsigned int> Word::getLines() const
{
    return lines;
}

list<unsigned int> Word::getColumns() const
{
    return columns;
}