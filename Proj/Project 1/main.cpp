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
void LoadGameRuleFromFile(ifstream &, string[], int);

int main(int argc, char** argv)
{
	ifstream inFile;
	ofstream outFile;


	int size = 10;
	string gameRule[size];

	int sizeRanF;
	int sizeRanT;
	int menuChoice;
	char play = 'Y';
	int markO;
	int turn;
	int turnLeft;
	char menu = 'Y';
	char gamestatus = 'Y';

	/*
	mainMenu:
	{
		menuDisplay();
		cin >> menuChoice;
	}
	while (menuChoice != 3)
	{
		if(menuChoice == 2)
		{
				cout << "game.history" << endl;
				cout << "game.rule" << endl;
				cout << "Back to main menu?(Y): \n";
				cin >> menu;
				if(menu == 'Y' || 'y')
					goto mainMenu;
		}

		else if(menuChoice == 1)
		{
			while(play == 'y' || play == 'Y')
			{
				turn = 0;
				system("CLS");
				cout << "Input the size of the sequence: ";
				cin >> size; cout << endl;
				cout << "Input the random number size from(1): ";
				cin >> sizeRanF;
				cout << "                             to(2-9): ";
				cin >> sizeRanT; cout << endl;

				int codeMaker[size];
				int codeBreaker[size];

				//Set random number seed with respect to time.
				srand(static_cast<unsigned int>(time(0)));

				for(int i = 0; i < size; i++)
				{
					codeMaker[i] = rand()%sizeRanT+sizeRanF;
				}

				turnLeft = 10;
				gamestatus = 'Y';

				while(gamestatus == 'Y' || gamestatus == 'n')
				{

					markO = 0;
					cout << "You have " << turnLeft << " turns left!\n";
					cout << "Input the guess: ";

					for (int i = 0; i < size ; i++)
					{
						cin >> codeBreaker[i];
						cin.ignore();
					}cout << endl;

					turnLeft--;

					//Displaying table
					for(int i = 0; i < size; i++)
					{
						cout << "X" << " ";
					}cout << endl;

					for(int i = 0; i < size+(size-1); i++)
						cout << "-";
					cout << endl;
					for(int i = 0; i < size; i++)
						cout << codeBreaker[i] << " ";
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
					cout << "You have " << markO << " numbers right!";
					cout << endl;
					turn++;

					if(markO == size)
					{
						cout << "\nYou win! You are the true MasterMind! \n";
						cout << "The sequence is: ";
						for(int i=0; i < size; i++)
						cout << codeMaker[i] << " ";
						turnLeft = 10;
						gamestatus = 'N';
					}

					else if (turn == 10)
					{
						cout << "\nRan out of turns. You lost! What a Surprise! \n";
						cout << "The sequence is: ";
						for(int i=0; i < size; i++)
							cout << codeMaker[i] << " ";
						turnLeft = 10;
						gamestatus = 'N';
					}
				}
				cout << "\nDo you want to continue?(Y/N): ";
				cin >> play;
			}
		}
	}*/
	//	Input game rules
	inFile.open("GameRule.txt");
	LoadGameRuleFromFile(inFile, gameRule, size);
	inFile.close();

	for(int i = 0; i < size; i++)
		cout << gameRule[i] << endl;

	return 0;
}

void LoadGameRuleFromFile(ifstream &inFile, string game[], int size)
{
		int index = 0;

		getline(inFile, game[0]);
		inFile >> game[0];
		while(!inFile.eof() && index < size)
		{
			getline(inFile, game[index]);
			index++;
		}
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
