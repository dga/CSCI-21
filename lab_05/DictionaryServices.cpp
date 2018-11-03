#include "DictionaryServices.h"

// Static member definitions

BSTree<Word*> DictionaryServices::dictionary;
CinReader DictionaryServices::userInput;
unsigned int DictionaryServices::most = 0;
unsigned int DictionaryServices::least = 100;
unsigned int DictionaryServices::largest = 0;
unsigned int DictionaryServices::smallest = 100;
unsigned int DictionaryServices::counter = 0;
unsigned int DictionaryServices::times = 0;
unsigned int DictionaryServices::theLine;
unsigned int DictionaryServices::theColumn;
bool DictionaryServices::stop = false;
bool DictionaryServices::success = false;
char DictionaryServices::theLetter;

void DictionaryServices::callback(string word, unsigned int ln, unsigned int col)
{
    Word* aWord = new Word(word);
    Word* ref = NULL;

    if (ref = dictionary.find(aWord, compare)) {
        ref->setCount(ref->getCount() + 1);
        ref->setLines(ln);
        ref->setColumns(col);
        delete aWord;
    } else if (ref == NULL) {
        aWord->setLines(ln);
        aWord->setColumns(col);
        dictionary.insert(aWord, compare);
    }
}

int DictionaryServices::compare(Word* left, Word* right)
{
    if (left->getData() > right->getData())
        return 1;
    else if (left->getData() < right->getData())
        return -1;
    else
        return 0;
}

void DictionaryServices::print(Word* data)
{
    unsigned int i = 0;

    if (!stop) {
        list<unsigned int> lines = data->getLines();
        list<unsigned int> columns = data->getColumns();
        cout << "\nWord: \"" << data->getData() << "\" with " << data->getCount() << " occurrence";
        
        if (data->getCount() == 1)
            cout << " at:\n";
        else
            cout << "s at:\n";
        times++;
        
        list<unsigned int>::const_iterator iter;
        list<unsigned int>::const_iterator iter2;
        
        for (iter=lines.begin(), iter2=columns.begin(); iter != lines.end(); iter++, iter2++, i++)
        {
            cout << "(" << i + 1 << ") Ln " << (*iter) << ", Col " << (*iter2) << "\n";
            times++;
            
            if (times >= 15) {
                cout << "\nContinue? (Y/N): ";
                if (toupper(userInput.readChar("ynYN")) == 'N') {
                    stop = true;
                    break;
                }
                times = 0;
            }
        }
    }
}

void DictionaryServices::destroy(Word* data)
{
    delete data;
}

void DictionaryServices::startsWith(Word* data)
{

    if (data->getData()[0] == theLetter) {
        success = true;
        cout << data->getData() << " ";
    }
}

void DictionaryServices::printLine(Word* data)
{
    list<unsigned int> lines = data->getLines();
    list<unsigned int>::const_iterator iter;

    for (iter=lines.begin(); iter != lines.end(); iter++)
        if ((*iter) == theLine) {
            success = true;
            cout << data->getData() << " ";
        }

}

void DictionaryServices::printColumn(Word* data)
{
    list<unsigned int>columns = data->getColumns();
    list<unsigned int>::const_iterator iter;

    for (iter = columns.begin(); iter != columns.end(); iter++)
        if ((*iter) == theColumn) {
            success = true;
            cout << data->getData() << " ";
        }
}

void DictionaryServices::getStats(Word* data)
{
    if (data->getCount() > most)
        most = data->getCount();

    if (data->getCount() < least)
        least = data->getCount();

    if (static_cast<unsigned int>(data->getData().length()) > largest)
        largest = static_cast<unsigned int>(data->getData().length());

    if (static_cast<unsigned int>(data->getData().length()) < smallest)
        smallest = static_cast<unsigned int>(data->getData().length());
}

void DictionaryServices::printMostCommon(Word* data)
{
    if (data->getCount() == most && counter < 10) {
        cout << data->getData() << " ";
        counter++;
    }
}

void DictionaryServices::printLeastCommon(Word* data)
{
    if (data->getCount() == least && counter < 10) {
        cout << data->getData() << " ";
        counter++;
    }
}

void DictionaryServices::printLargest(Word* data)
{
    if (data->getData().length() == largest && counter < 10) {
        cout << data->getData() << " ";
        counter++;
    }
}

void DictionaryServices::printSmallest(Word* data)
{
    if (data->getData().length() == smallest && counter < 10) {
        cout << data->getData() << " ";
        counter++;
    }
}
