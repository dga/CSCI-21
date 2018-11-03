/**************************
 * Name: Daniel G. Arnold *
 * Course: CSCI 21        *
 * Project: Lab 2         *
 * Filename: arenaui.cpp  *
 **************************/

#include "arenaui.h"

ArenaUI::ArenaUI()
{
    teamOne = NULL;
    teamTwo = NULL;
    srand(time(NULL));
}

ArenaUI::~ArenaUI()
{
    delete teamOne;
	teamOne = NULL;
    delete teamTwo;
	teamTwo = NULL;
}

void ArenaUI::go()
{
    cout << "Welcome to Battle Bots!\n\n";

    while (mainMenu()) {}
}

bool ArenaUI::mainMenu()
{
    bool goAgain = true;
    bool populated = true;

    cout << "\nMain Menu:\n";
    cout << "---------\n";
    cout << "[1] Create teams\n";
    cout << "[2] Edit teams\n";
    cout << "[3] Start battle\n";
    cout << "[4] View team summary\n";
    cout << "[0] Quit\n\n";
    cout << "> ";

    switch (reader.readInt(true, 0, 4)) {
        case 0:
            cout << "Program exited successfully.\n";

            goAgain = false;

            break;
        case 1:
            if (teamOne != NULL)
                cout << "You have already created your teams.\n";
            else
                createTeams();

            cout << "\nPress enter to continue...\n";
            reader.readString();

            break;
        case 2:
            if (teamOne == NULL) {
                cout << "You haven't created your teams yet.\n";
                cout << "\nPress enter to continue...\n";
                reader.readString();
            } else
                while (teamMenu()) {}

            break;
        case 3:
            if (teamOne == NULL)
                cout << "You haven't created your teams yet.\n";
            else {
                for (int i = 0; i < teamOne->getSize() && populated; i++)
                    if (teamOne->getBot(i) == NULL || teamTwo->getBot(i) == NULL)
                        populated = false;
                
                if (!populated)
                    cout << "You haven't populated your teams yet.\n";
                else
                    startBattle();
            }
            
            cout << "\nPress enter to continue...\n";
            reader.readString();

            break;
        case 4:
            if (teamOne == NULL)
                cout << "You haven't created your teams yet.\n";
            else {
                for (int i = 0; i < teamOne->getSize() && populated; i++)
                    if (teamOne->getBot(i) == NULL || teamTwo->getBot(i) == NULL)
                        populated = false;
                
                if (!populated)
                    cout << "You haven't populated your teams yet.\n";
                else {
                    cout << "Choose team (1-2): ";
                    if (reader.readInt(true, 1, 2) == 1)
                        cout << teamOne->print();
                    else
                        cout << teamTwo->print();
                }
            }
            
            cout << "\nPress enter to continue...\n";
            reader.readString();

            break;
    }

    return goAgain;
}

void ArenaUI::createTeams()
{
	string teamOneName = "";
	string teamTwoName = "";
	int teamSize = 0;

	cout << "Team #1 name: ";
	teamOneName = reader.readString();
	cout << "Team #2 name: ";
	teamTwoName = reader.readString();
    cout << "Team sizes: ";
    teamSize = reader.readInt();
    
    teamOne = new Team(teamOneName, teamSize);
    teamTwo = new Team(teamTwoName, teamSize);
}

bool ArenaUI::teamMenu()
{
    bool goAgain = true;
    int newSize = 0;
    int slot = 0;

    cout << "\nTeam Menu:\n";
    cout << "---------\n";
	cout << "[1] Populate team\n";
	cout << "[2] Expunge team\n";
    cout << "[3] Grow teams\n";
    cout << "[4] Add a bot to team\n";
    cout << "[5] Remove a bot from team\n";
    cout << "[6] Show bot stats\n";
    cout << "[0] Return to main\n\n";
    cout << "> ";

    switch (reader.readInt(true, 0, 6)) {
        case 0:
            goAgain = false;

            break;
		case 1:
			cout << "\nChoose team:\n";
			cout << "-----------\n";
			cout << "[1] " << teamOne->getName() << "\n";
			cout << "[2] " << teamTwo->getName() << "\n\n";
			cout << "> ";

			if (reader.readInt(true, 1, 2) == 1)
				if (teamOne->populate())
					cout << "Team successfully populated.\n";
				else
					cout << "Team failed to be populated. Expunge team first.\n";
			else
				if (teamTwo->populate())
					cout << "Team successfully populated.\n";
				else
					cout << "Team failed to be populated. Expunge team first.\n";

			cout << "\nPress enter to continue...\n";
			reader.readString();

			break;
		case 2:
			cout << "\nChoose team:\n";
			cout << "-----------\n";
			cout << "[1] " << teamOne->getName() << "\n";
			cout << "[2] " << teamTwo->getName() << "\n\n";
			cout << "> ";

			if (reader.readInt(true, 1, 2) == 1)
				if (teamOne->expunge())
					cout << "Team expunged successfully.\n";
				else
					cout << "Team failed to be expunged.\n";
			else
				if (teamTwo->expunge())
					cout << "Team expunged successfully.\n";
				else
					cout << "Team failed to be expunged.\n";

			cout << "\nPress enter to continue...\n";
			reader.readString();

			break;
        case 3:
            cout << "New size: ";
            newSize = reader.readInt();
            
            if (teamOne->grow(newSize) && teamTwo->grow(newSize))
                cout << "Teams grew successfully.\n";
            else
                cout << "Teams grow failed.\n";

            cout << "\nPress enter to continue...\n";
            reader.readString();

            break;
        case 4:
            cout << "Choose team (1-2): ";
            
            if (reader.readInt(true, 1, 2) == 1) {
                cout << "Choose slot (1-" << teamOne->getSize() << "): ";
                
                if (teamOne->addBot(new Bot(), reader.readInt(true, 1, teamOne->getSize())))
					cout << "Bot added successfully.\n";
                else
                    cout << "Bot failed to be added.\n";
            } else {
                cout << "Choose slot (1-" << teamTwo->getSize() << "): ";
                
                if (teamTwo->addBot(new Bot(), reader.readInt(true, 1, teamTwo->getSize())))
                    cout << "Bot added successfully.\n";
                else
                    cout << "Bot failed to be added.\n";
            }

            cout << "\nPress enter to continue...\n";
            reader.readString();
 
            break;
        case 5:
            cout << "Choose team (1-2): ";

            if (reader.readInt(true, 1, 2) == 1) {
                cout << "Choose slot (1-" << teamOne->getSize() << "): ";

                if (teamOne->removeBot(reader.readInt(true, 1, teamOne->getSize())))
                    cout << "Bot removed successfully.\n";
                else
                    cout << "Bot failed to be removed.\n";
            } else {
                cout << "Choose slot (1-" << teamTwo->getSize() << "): ";

                if (teamTwo->removeBot(reader.readInt(true, 1, teamTwo->getSize())))
                    cout << "Bot removed successfully.\n";
                else
                    cout << "Bot failed to be removed.\n";
            }

            cout << "\nPress enter to continue...\n";
            reader.readString();

            break;
        case 6:
            cout << "Choose team (1-2): ";

            if (reader.readInt(true, 1, 2) == 1) {
                cout << "Choose slot (1-" << teamOne->getSize() << "): ";
                slot = reader.readInt(true, 1, teamOne->getSize());
                cout << "\n" << teamOne->getBot(slot)->print() << "\n";
            } else {
                cout << "Choose slot (1-" << teamTwo->getSize() << "): ";
                slot = reader.readInt(true, 1, teamTwo->getSize());
                cout << "\n" << teamTwo->getBot(slot)->print() << "\n";
            }

            cout << "\nPress enter to continue...\n";
            reader.readString();

            break;
    }

    return goAgain;
}

void ArenaUI::startBattle()
{
    int t1 = 0;
    int t2 = 0;

    cout << "\n";

    for (int i = 0; i < teamOne->getSize(); i++) {
        cout << "Round " << i + 1 << ": ";
        teamOne->getBot(i)->setSum(teamOne->getBot(i)->getSum() + teamOne->getMorale());
        teamTwo->getBot(i)->setSum(teamTwo->getBot(i)->getSum() + teamTwo->getMorale());
        
        if (teamOne->getBot(i)->getSum() > teamTwo->getBot(i)->getSum()) {
            t1++;
            teamOne->getBot(i)->setWins(teamOne->getBot(i)->getWins() + 1);
            teamTwo->getBot(i)->setLosses(teamTwo->getBot(i)->getLosses() + 1);
            
            if (teamOne->getBot(i)->getStrength() < 20)
                teamOne->getBot(i)->setStrength(teamOne->getBot(i)->getStrength() + 1);
            
            if (teamOne->getBot(i)->getExperience() < 10)
                teamOne->getBot(i)->setExperience(teamOne->getBot(i)->getExperience() + 1);
            
            if (teamOne->getBot(i)->getIntelligence() < 4)
                teamOne->getBot(i)->setIntelligence(teamOne->getBot(i)->getIntelligence() + 1);
            
            cout << teamOne->getBot(i)->getName() << " of Team " << teamOne->getName() << " wins.\n";
        } else if (teamTwo->getBot(i)->getSum() > teamOne->getBot(i)->getSum()) {
            t2++;
            teamTwo->getBot(i)->setWins(teamTwo->getBot(i)->getWins() + 1);
            teamOne->getBot(i)->setLosses(teamOne->getLosses() + 1);
            
            if (teamTwo->getBot(i)->getStrength() < 20)
                teamTwo->getBot(i)->setStrength(teamTwo->getBot(i)->getStrength() + 1);
            
            if (teamTwo->getBot(i)->getExperience() < 10)
                teamTwo->getBot(i)->setExperience(teamTwo->getBot(i)->getExperience() + 1);
            
            if (teamTwo->getBot(i)->getIntelligence() < 4)
                teamTwo->getBot(i)->setIntelligence(teamTwo->getBot(i)->getIntelligence() + 1);
            
            cout << teamTwo->getBot(i)->getName() << " of Team " << teamTwo->getName() << " wins.\n";
        } else {
            t1 = 0;
            t2 = 0;
            cout << "Draw.\n";
            cout << "Coin toss determines Team ";
            
            if (rand() % 2) {
                teamOne->getBot(i)->setDraws(teamOne->getBot(i)->getDraws() + 1);
                teamTwo->getBot(i)->setDraws(teamTwo->getBot(i)->getDraws() + 1);
                teamOne->getBot(i)->setWins(teamOne->getBot(i)->getWins() + 1);
                teamTwo->getBot(i)->setLosses(teamTwo->getBot(i)->getLosses() + 1);
                cout << teamOne->getBot(i)->getName() << " of Team " << teamOne->getName() << " the winner.\n";
            } else {
                teamOne->getBot(i)->setDraws(teamOne->getBot(i)->getDraws() + 1);
                teamTwo->getBot(i)->setDraws(teamTwo->getBot(i)->getDraws() + 1);
                teamTwo->getBot(i)->setWins(teamTwo->getBot(i)->getWins() + 1);
                teamOne->getBot(i)->setLosses(teamOne->getBot(i)->getLosses() + 1);
                cout << teamTwo->getBot(i)->getName() << " of Team " << teamTwo->getName() << " the winner.\n";
            }
        }
    }

    if (t1 > t2) {
        teamOne->setWins(teamOne->getWins() + 1);
        teamTwo->setLosses(teamTwo->getLosses() + 1);
        
        if (teamOne->getMorale() < 3)
            teamOne->setMorale(teamOne->getMorale() + 1);
        
        if (teamTwo->getMorale() > 1)
            teamTwo->setMorale(teamTwo->getMorale() - 1);
        
        cout << "Team " << teamOne->getName() << " wins!\n";
    } else if (t2 > t1) {
        teamTwo->setWins(teamOne->getWins() + 1);
        teamOne->setLosses(teamOne->getLosses() + 1);
        
        if (teamTwo->getMorale() < 3)
            teamTwo->setMorale(teamTwo->getMorale() + 1);
        
        if (teamOne->getMorale() > 1)
            teamOne->setMorale(teamOne->getMorale() - 1);
        
        cout << "Team " << teamTwo->getName() << " wins!\n";
    } else {
        teamOne->setDraws(teamOne->getDraws() + 1);
        teamTwo->setDraws(teamTwo->getDraws() + 1);
        cout << "Battle ends in a draw.\n";
    }
}
