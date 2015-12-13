/*
 * Functions.h
 *
 *  Created on: Dec 10, 2015
 *      Author: AnhLe
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//System Libraries
#include <iostream> 				//Input/Output stream Library
#include <iomanip>  				//Format Library
#include <string.h>					//String Library
#include <fstream>					//Input/Output stream text files
#include <cstdlib> 					//Random Library
#include <ctime>    				//Time Library
#include <stdlib.h>					//Standard Library
using namespace std;				//Utilize standard name-space directly

	//Constant variables
	const int COLUMNS = 3;
	const int ROWS = 3;
	const int sizeT = 12;

	//Structure declaration
	struct about					//Structure about
	{
		string history[sizeT];		//String array
		string rule[sizeT];			//string array
	};

	//Class Declaration
	class TTT
	{
	private:

	public:
		void OutputInstruct();
		void InitBoard(char boardAr[][COLUMNS]);
		void DisplayBoard(const char boardAr[][COLUMNS]);
		void GetAndCheckInp(char boardAr[][COLUMNS], char token, string player1, string player2);
		char SwitchToken(char token);
		void GetPlayers(string& player1, string& player2);
		char CheckWin(char boardAr[][COLUMNS]);
		void OutputWinner(char whoWon, string player1, string player2);
	};

	//Function prototypes
	void menuDisplay();
	void LoadGameRuleFromFile(ifstream &, string game[], int);
	void printRules(struct about game, int sizeT);
	void tableDisplay(char [], int);
	char checkWinF(ofstream &outFile, int, int, char, int, char [], int);


#endif /* FUNCTIONS_H_ */
