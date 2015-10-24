/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 16, 2015, 11:30 AM
 * Purpose: Project 1: MASTERMIND MOD GAME
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

	//Global constants
	const int sizeT = 12;

	//Structure declaration
	struct about					//Structure about
	{
		string history[sizeT];		//String array
		string rule[sizeT];			//string array
	};


//Function prototypes
void menuDisplay();
void LoadGameRuleFromFile(ifstream &, string game[], int);
void printRules(struct about game, int sizeT);
void tableDisplay(int [], int);
char checkWin(ofstream &outFile, int, int, char, int, int [], int);



/******************************************************************************/
/***************************** MASTERMIND MOD GAME *****************************
********************************************************************************
********************************************************************************
********************************************************************************
*******************************************************************************/
int main(int argc, char** argv)
{
	ifstream inFile;						//Input binary file
	ofstream outFile;						//Output binary file

	string gameRule[sizeT];					//string to retrieve game rule
	string gameHis[sizeT];					//string to retrieve game description

	about game;								//structure game with description and rule

	int size;								//size of the sequence
	int sizeRanF;							//randomize number from 1
	int sizeRanT;							//to 9
	int menuChoice;							//choice of menu
	char play = 'Y';						//while the game is running
	int markO;								//Number of right guesses
	int turn;								//Number of turn(max 10)
	int turnLeft;							//count down turns
	char menu = 'Y';						//Going back to main menu
	char gamestatus = 'Y';					//While the user wants to play again

	int *codeMaker;							//Code maker
	int *codeBreaker;						//Code breaker

		//Open GameRule.txt file
		inFile.open("GameRule.txt");
		//Loading game rule from file
		LoadGameRuleFromFile(inFile, gameRule, sizeT);
		//Close the text file
		inFile.close();

		//Open GameHistory.txt file
		inFile.open("GameHistory.txt");
		//Load game description from file
		LoadGameRuleFromFile(inFile, gameHis, sizeT);
		//Close the text file
		inFile.close();

		//Open Output.txt file
		outFile.open("Output.txt");
		//Output headline to file
		outFile << "                             ~YOUR STATUS AFTER THE GAME~\n\n";

		//Setting the string inside the structure
		for(int i = 0; i < sizeT; i++)
		{
			game.rule[i]= gameRule[i];
			game.history[i]= gameHis[i];
		}

		//Main menu with choices 1, 2, 3
	mainMenu:
		{
		menuDisplay();									//Display the menu
		cin >> menuChoice;								//Input choice
	}

	while (menuChoice != 3)								//While choice is not 3(exit)
	{
		if(menuChoice == 2)								//If user picks 2
		{
				//Print rules and description using the printRules function
				printRules(game , sizeT);

				//You want to back to the main menu
				cout << "Back to main menu?(Y): \n";
				cin >> menu;							//Input the decision
				if(menu == 'Y' || 'y')					//If they pick yes
					goto mainMenu;						//GO back to displaying main menu
				else if (menu == 'N' || menu == 'n')
					menuChoice = 3;						//Set menu choice to 3(exit the code)
		}

		else if(menuChoice == 1)						//If menu choice is 1
		{
			while(play == 'y' || play == 'Y')			//While play is yes
			{
				turn = 0;								//Reset the turn

				system("CLS");							//Clear the screen

				//Prompt for inputing the sequence size
				cout << "Input the size of the sequence: ";
				cin >> size; cout << endl;				//Input the size

				//Prompt for randomize range from 1
				cout << "Input the random number size from(1): ";
				cin >> sizeRanF;						//Input 1

				//to 2-9
				cout << "                             to(2-9): ";
				cin >> sizeRanT; cout << endl;			//Input from 2-9

				codeMaker   = new int[size];		//Dynamic allocated codeMaker using input size
				codeBreaker = new int[size];		//Dynamic allocated codeBreaker using input size

				//Set random number seed to time.
				srand(static_cast<unsigned int>(time(0)));

				//Randomize the number according to user's input
				for(int i = 0; i < size; i++)
				{
					codeMaker[i] = rand()%sizeRanT+sizeRanF;
				}

				//Output sequence to binary file
				outFile << "The sequence: ";
				for(int i = 0; i < size; i++)
					outFile << codeMaker[i] << " ";

				turnLeft = 10;							//Reset turnLeft
				gamestatus = 'Y';						//Game status is yes playing

				while(gamestatus == 'Y' || gamestatus == 'y')
				{

					markO = 0;							//User's right guess reset

					//Output how many turn user have left
					cout << "You have " << turnLeft << " turns left!\n";
					//Prompt for inputing the guess
					cout << "Input the guess: ";

					//Inputing the guess using codeBreaker array
					for (int i = 0; i < size ; i++)
					{
						cin >> codeBreaker[i];
						cin.ignore();
					}cout << endl;

					//Lost a turn
					turnLeft--;

					//Output their turn into the binary file
					outFile << "\n\nTurn " << turn+1 << ": ";
					outFile << "\nYour guess: ";

					//Output the guess into the binary file
					for(int i = 0; i < size; i++)
						outFile << codeBreaker[i] << " ";
					//Output how many turns left into the binary file
					outFile <<	"\nTurn left: " << turnLeft << " turns.\n";

					//Displaying table with the guesses and sequence size
					tableDisplay(codeBreaker, size);

					//Check for right guesses of the sequence
					for(int count = 0; count < size; count++)
					{
						for (int i = 0; i < size ; i++)
						{
							//If the input match the default number by array position and value
							if(codeBreaker[count] == codeMaker[i] && count == i)
							{
								markO++;
							}
						}
					}

					//Output how may numbers the user got right
					cout << "You have " << markO << " numbers right!";
					cout << endl;

					turn++;							//Adding a turn

					//Check for win funtion to see if the user get all the numbers right
					gamestatus = checkWin(outFile, markO, turn, gamestatus,
							              turnLeft, codeMaker, size);
				}
				//End the match. Prompt for continuation
				cout << "\nDo you want to continue?(Y/N): ";
				cin >> play;						//Input the decision
			}
		}
		//Other input choice other than 1,2 or 3
		else
		{
			//Display invalid
			cout << "\nInvalid input, please re-enter: ";
			cin >> menuChoice;						//Re-input the main menu choice
		}
	}

	//Close the binary file Output.txt
	outFile.close();

	delete [] codeMaker;							//Delete the array stored
	delete [] codeBreaker;							//Delete the array stored

	//End code
	return 0;
}

/******************************************************************************/
/*************************** Output the Main Menu ******************************
********************************************************************************
 * Void menuDisplay();
*******************************************************************************/
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

/******************************************************************************/
/************* Loading Game Rule & Description from binary files ***************
********************************************************************************
 * Inputs
 *      inFile  -> input the binary file into the array
 *      game[]  -> Array to holds the string from the file
 *      sizeT   -> Size of the string
*******************************************************************************/
void LoadGameRuleFromFile(ifstream &inFile, string game[], int sizeT)
{
		int index = 0;							//Index set to 0

		getline(inFile, game[0]);				//Input the first line of the file
		while(!inFile.eof() && index < sizeT)	//While it's not end of the file
		{										//and index < size of the file
			getline(inFile, game[index]);		//Inputing the sentence into the array
			index++;							//Increment index
		}
}

/******************************************************************************/
/************************ Output Game Rules & Descriptions ********************
********************************************************************************
 * Inputs
 *      inFile  -> input the binary file into the array
 *      game[]  -> Array to holds the string from the file
 *      sizeT   -> Size of the string
*******************************************************************************/
void printRules(struct about game, int sizeT)
{
	system("CLS");								//Clear the screen

	//Output the headline of the menu
	cout << "                                ~About The Game Page~\n\n";

	//Output the game description
	for(int i = 0; i < sizeT; i++)
		cout << game.history[i] << endl;

	//Output how to play
	cout << "HOW TO PLAY:\n";

	//Output the game rule
	for(int i = 0; i < sizeT; i++)
		cout << game.rule[i] << endl;
}

/******************************************************************************/
/************************ Display Table inside the game ********************
********************************************************************************
 * Inputs
 *      codeBreaker[]  -> The user's guess input array
 *      size  		   -> Size of the sequence
*******************************************************************************/
void tableDisplay(int codeBreaker[], int size)
{
	//Output the X X X X with the size
	for(int i = 0; i < size; i++)
	{
		cout << "X" << " ";
	}cout << endl;

	//Output the ----- with the size
	for(int i = 0; i < size+(size-1); i++)
		cout << "-";
	cout << endl;

	//Output spaces
	for(int i = 0; i < size; i++)
		cout << codeBreaker[i] << " ";
	cout << endl;
}

/******************************************************************************/
/************************ Check for The Solution *******************************
********************************************************************************
 * Inputs
 *      outFile  	-> output into the binary file
 *      markO  		-> numbers of right degits
 *      turn       	-> turn the user is on
 * 		gamestatus  -> Game status to repeating the match
 *      turnLeft    -> Number of turn left
 *      codeMaker[] -> The code ramdomize sequence
 *      size        -> Size of the sequence
*******************************************************************************/
char checkWin(ofstream &outFile, int markO, int turn,
		     char gamestatus, int turnLeft, int codeMaker[],
		     int size)
{
	//If the user guess all numbers right
	if(markO == size)
	{
		//Output the winning and he/she is the true Master mind
		cout << "\nYou win! You are the true MasterMind! \n";
		cout << "The sequence is: ";

		//Output that the user win into the binary file
		outFile << "You won! At turn " << turn+1;

		//Output the actual randomize sequence
		for(int i=0; i < size; i++)
			cout << codeMaker[i] << " ";

		turnLeft = 10;						//Reset turn left to 10
		gamestatus = 'N';					//Game ended
	}

	//If user ran out of turn without guessing the right sequence
	else if (turn == 10)
	{
		//Output that they lost and the actual sequence is
		cout << "\nRan out of turns. You lost! What a Surprise! \n";
		cout << "The sequence is: ";

		//Output that they lost into the binary file
		outFile << "You lost! Maximum of turns reached!";

		//Output the actual randomize sequence
		for(int i=0; i < size; i++)
			cout << codeMaker[i] << " ";

		turnLeft = 10;						//Reset turn left to 10
		gamestatus = 'N';					//Game ended
	}

	return gamestatus;						//Return game status is N
}

