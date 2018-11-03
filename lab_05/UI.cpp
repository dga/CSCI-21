#include "UI.h"
#include "DictionaryServices.h"

UI::UI()
{    
}

UI::~UI()
{
    // Wipe out all instances of Word from the heap
    DictionaryServices::dictionary.inorder(DictionaryServices::destroy);
}

void UI::go()
{
    while (menu()) {}
}

bool UI::menu()
{
    static bool loaded = false;
    unsigned int choice = 0;
    string filename = "";
    string inputWord = "";
    Word* word = NULL;
    Word* ref = NULL;

    cout << "Menu:\n"
        << "-----\n"
        << "[1] Load file\n"
        << "[2] Search by word\n"
        << "[3] Search by letter\n"
        << "[4] View by line\n"
        << "[5] View by column\n"
        << "[6] View index\n"
        << "[7] Get stats\n"
        << "[8] Remove word\n"
        << "[9] Clear tree\n"
        << "[0] Quit\n\n"
        << "> ";

    choice = userInput.readInt(true, 0, 9);

    switch (choice) {
        case 0:
            cout << "Program exited successfully.\n";

            return false;
        case 1:
            if (loaded)
                cout << "\nYou need to clear the tree before loading another file.\n";
            else {
                cout << "\nEnter filename: ";
                filename = userInput.readString();
                cout << "\nProcessing file...";
                
                if (fileReader.read(filename, DictionaryServices::callback)) {
                    loaded = true;
                    cout << "Done.\n";
                } else
                    cout << "Failed.\n";
            }

            break;
        case 2:
            if (loaded) {
                DictionaryServices::stop = false;
                DictionaryServices::times = 0;
                cout << "\nEnter a word: ";
                inputWord = userInput.readString();

                for (unsigned int i = 0; i < static_cast<unsigned int>(inputWord.length()); i++)
                    inputWord[i] = tolower(inputWord[i]);
                
                word = new Word(inputWord);
                
                if (ref = DictionaryServices::dictionary.find(word, DictionaryServices::compare))
                    DictionaryServices::print(ref);
                else
                    cout << "\nCouldn't locate \"" << word->getData() << "\" in the dictionary.\n";
            } else
                cout << "\nYou need to load a file first.\n";

            delete word;

            break;
        case 3:
            if (loaded) {
                DictionaryServices::success = false;
                cout << "\nEnter a letter: ";
                DictionaryServices::theLetter = userInput.readChar();
                cout << endl;
                DictionaryServices::dictionary.inorder(DictionaryServices::startsWith);
                if (DictionaryServices::success == false)
                    cout << "Couldn't find words starting with the letter '" << DictionaryServices::theLetter << "'.";
                cout << endl;
            } else
                cout << "\nYou need to load a file first.\n";
            
            break;
        case 4:
            if (loaded) {
                DictionaryServices::success = false;
                cout << "\nEnter line number: ";
                DictionaryServices::theLine = userInput.readInt();
                cout << endl;
                DictionaryServices::dictionary.inorder(DictionaryServices::printLine);
                if (DictionaryServices::success == false)
                    cout << "Empty or non-existent line.";
                cout << endl;
            } else
                cout << "\nYou need to load a file first.\n";
            
            break;
        case 5:
            if (loaded) {
                DictionaryServices::success = false;
                cout << "\nEnter column number: ";
                DictionaryServices::theColumn = userInput.readInt();
                cout << endl;
                DictionaryServices::dictionary.inorder(DictionaryServices::printColumn);
                if (DictionaryServices::success == false)
                    cout << "Empty or non-existent column.";
                cout << endl;
            } else
                cout << "\nYou need to load a file first.\n";

            break;
        case 6:
            if (loaded) {
                DictionaryServices::stop = false;
                DictionaryServices::times = 0;
                DictionaryServices::dictionary.inorder(DictionaryServices::print);
            } else
                cout << "\nYou need to load a file first.\n";

            break;
        case 7:
            if (loaded) {
                cout << "\nStatistics:\n"
                    << "-----------\n";
                DictionaryServices::dictionary.inorder(DictionaryServices::getStats);
                cout << "Most common word(s): ";
                DictionaryServices::counter = 0;
                DictionaryServices::dictionary.inorder(DictionaryServices::printMostCommon);
                cout << endl;
                cout << "Least common word(s): ";
                DictionaryServices::counter = 0;
                DictionaryServices::dictionary.inorder(DictionaryServices::printLeastCommon);
                cout << endl;
                cout << "Largest word(s): ";
                DictionaryServices::counter = 0;
                DictionaryServices::dictionary.inorder(DictionaryServices::printLargest);
                cout << endl;
                cout << "Smallest word(s): ";
                DictionaryServices::counter = 0;
                DictionaryServices::dictionary.inorder(DictionaryServices::printSmallest);
                cout << endl;
                cout << "Unique word(s): " << DictionaryServices::dictionary.getNodeCount() << endl;
            } else
                cout << "\nYou need to load a file first.\n";
            
            break;
        case 8:
            if (loaded) {
                cout << "\nEnter a word: ";
                word = new Word(userInput.readString());
                
                if (ref = DictionaryServices::dictionary.find(word, DictionaryServices::compare)) {
                    DictionaryServices::dictionary.remove(word, DictionaryServices::compare);
                    delete ref;
                    cout << "\nRemoved.\n";
                } else
                    cout << "\nCouldn't locate \"" << word->getData() << "\" in the dictionary.\n";
                delete word;
            } else
                cout << "\nYou need to load a file first.\n";

            break;
        case 9:
            if (loaded) {
                loaded = false;
                DictionaryServices::dictionary.clear();
                DictionaryServices::dictionary.inorder(DictionaryServices::destroy);
                cout << "\nTree cleared successfully.\n";
            } else
                cout << "\nCan't clear empty tree!\n";
            
            break;
        default:
            cerr << "Error.\n";
    }

    cout << "\nPress enter to continue...";
    userInput.readString();
    cout << endl;

    return true;
}
