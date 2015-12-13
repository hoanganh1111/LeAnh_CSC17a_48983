/******************************************************************************
* functions.cpp
* This functions.cpp is created to define and declares all the functions
* prototypes that will be use in the main.cpp. It includes:
*
* void menuDisplay(): Display the menu
* void LoadGameRuleFromFile() : Load the game rule and how to from text files
* void printRules(): Print the rules and how to play MasterMind game
* void tableDisplay(): Display the slot with X
* char checkWinF(): Check to see if the players win the game
*
*****************************************************************************/

#include "functions.h"

/******************************************************************************/
/*************************** Output the Main Menu ******************************
********************************************************************************
 * Void menuDisplay();
*******************************************************************************/
void menuDisplay()
{
	system("CLS");
	cout << "                        ~MASTERMIND MOD + TIC TAC TOE~\n";
	cout << "                                     The Game   \n";
	cout << "       1. Start Mastermind Modified.\n";
	cout << "       2. Start Tic Tac Toe.\n";
	cout << "       3. About the game(Mastermind).\n";
	cout << "      4. Quit.\n";
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
void tableDisplay(char codeBreaker[], int size)
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
char checkWinF(ofstream &outFile, int markO, int turn,
		     char gamestatus, int turnLeft, char codeMakerL[],
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
			cout << codeMakerL[i] << " ";

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
			cout << codeMakerL[i] << " ";

		turnLeft = 10;						//Reset turn left to 10
		gamestatus = 'N';					//Game ended
	}

	return gamestatus;						//Return game status is N
}
