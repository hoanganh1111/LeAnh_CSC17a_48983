/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 16, 2015, 11:30 AM
 * Purpose: Project 1
 */

//System Libraries
#include <iostream> 				//Input/Output stream Library
#include <iomanip>  				//Format Library
#include <string.h>					//String Library
#include <fstream>					//Input/Output stream text files
#include <cstdlib> 					//Random Library
#include <ctime>    				//Time Library
#include <stdlib.h>					//Standard Library
using namespace std;				//Utilize standard name-space directly

//Structure declaration
struct about
{
	string history;
	string rule;
}game;

//Function prototypes
void menuDisplay();
void inMenuDisplay();
string LoadGameRuleFromFile(ifstream &, int);

int main(int argc, char** argv)
{
	ifstream inFile;
	ofstream outFile;
	int size;
	int sizeRanF;
	int sizeRanT;
	int menuChoice;
	int inMenuChoice;
	char play = 'N';
	int markO;
	int turn;
	bool win = false;

	while(play == 'N' || play == 'n')
		{
		win = false;
		markO = 0;
		menuDisplay();
		cin >> menuChoice;

	while (menuChoice != 3)
	{
		if(menuChoice == 2)
		{
			menuStuffs:
			{
			inMenuDisplay();
			cin >> inMenuChoice;
			}
			if(inMenuChoice == 1)
			{
				cout << "game.history" << endl;
				goto menuStuffs;
			}
			else if(inMenuChoice == 2)
			{
				cout << "game.rule" << endl;
				goto menuStuffs;
			}
			else if(inMenuChoice == 3)
			{
				menuDisplay();
				cin >> menuChoice;
			}
			else
			{
				cout << "Invalid input, re-enter: ";
				cin >> inMenuChoice;
			}
		}
		else if(menuChoice == 1)
		{
				turn = 0;

				cout << "Input the size of the code: ";
				cin >> size; cout << endl;
				cout << "Input the random number size from(1-9): ";
				cin >> sizeRanF;
				cout << "                                    to: ";
				cin >> sizeRanT; cout << endl;

				int codeMaker[size];
				int codeBreaker[size];

				//Set random number seed with respect to time.
				srand(static_cast<unsigned int>(time(0)));

				for(int i = 0; i < size; i++)
				{
					codeMaker[i] = rand()%sizeRanT+sizeRanF;
				}


				for(turn = 0; turn < 10; turn++)
				{
					markO = 0;
					cout << "The game has begun! ";
					cout << "Input the guess: " << endl;

					for (int i = 0; i < size ; i++)
					{
						cin >> codeBreaker[i];
						cin.ignore();
					}
					//Displaying table
					for(int i = 0; i < size; i++)
					{
						cout << codeMaker[i] << " ";
					}
					cout << endl;

						for(int i = 0; i < size+(size-1); i++)
							cout << "-";
					cout << endl;
					//Table

					for(int count = 0; count < size; count++)
					{
						for (int i = 0; i < size ; i++)
						{
							if(codeBreaker[count] == codeMaker[i] && count == i)
							{
								markO++;
							}
						}
					}
					if(markO == size)
					{
						win = true;
						cout << "You win! Good Job There! \n";
						cout << "Want to continue?(Y/N): ";
						cin >> play;
					}
					cout << "You have " << markO << " numbers right!";
					cout << endl;
					turn++;
				}
					cout << "\n\nRan out of turns. You Lost! What a Suprise! " << endl;
					cout << "Want to continue?(Y/N): ";
					cin >> play;
					win = false;

				}
			}
		}
	/*	Input game rules
	inFile.open("GameRule.txt");
	rule = LoadGameRuleFromFile(inFile, size);
	inFile.close();
	*/
	return 0;
}

string LoadGameRuleFromFile(ifstream &inFile, int size)
{
		int index = 0;
		char game[size];
		//getline(inFile, game[0]);
		inFile >> game[0];
		while(!inFile.eof() && index < size)
		{
			//getline(inFile, game[0]);
			inFile >> game[0];
			index++;
		}
		return game;
}

void menuDisplay()
{
	system("CLS");
	cout << "                                 ~MASTERMIND MOD~\n";
	cout << "                                     The Game   \n";
	cout << "       1. Start the game.\n";
	cout << "       2. About the game.\n";
	cout << "       3. Quit.\n";
	cout << "\nChoose an Option: ";
}

void inMenuDisplay()
{
	system("CLS");
	cout << "								   ~ABOUT THE GAME~\n";
	cout << "       1. About.\n";
	cout << "       2. How to play.\n";
	cout << "       3. Back to main menu.\n";
	cout << "\nChoose an Option: ";
}
