/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 5, 2015, 11:30 AM
 * Purpose: Project 2: MASTERMIND MOD GAME
 * 					   Tic Tac Toe
 */

#include "Functions.h"

/*******************************************************************************
********************************************************************************
****************************** MASTERMIND MOD GAME *****************************
******************************* TIC TAC TOE GAME *******************************
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
	int sizeRanF = 1;						//randomize number from 1
	int sizeRanT = 4;						//to 4
	int menuChoice;							//choice of menu
	int markO;								//Number of right guesses
	int turn;								//Number of turn(max 10)
	int turnLeft;							//count down turns
	char menu = 'Y';						//Going back to main menu
	char gamestatus = 'Y';					//While the user wants to play again

	int *codeMaker;							//Code maker
	char *codeMakerL;
	char *codeBreaker;						//Code breaker

	char boardAr[ROWS][COLUMNS];			//Array that holds the rows and columns of the board
	char gameStatus = 'N';					//Character that is used to determine the status of game
	char play = 'Y';						//Holds user's decision when prompted if they want to play
	char token;								//Holds the character of the current player
	char changeName = 'Y';					//Holds user's decision when prompted to change name
	string player1;							//Holds player 1's name
	string player2;							//Holds player 2's name

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
		play = 'N';

	while (menuChoice != 4)								//While choice is not 4(exit)
	{
		if(menuChoice == 3)								//If user picks 3
		{
				//Print rules and description using the printRules function
				printRules(game , sizeT);

				//You want to back to the main menu
				cout << "Back to main menu?(Y): \n";
				cin >> menu;							//Input the decision
				if(menu == 'Y' || menu == 'y')			//If they pick yes
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

				codeMaker   = new int[size];		//Dynamic allocated codeMaker using input size
				codeBreaker = new char[size];		//Dynamic allocated codeBreaker using input size
				codeMakerL = new char[size];

				//Set random number seed to time.
				srand(static_cast<unsigned int>(time(0)));

				//Randomize the number according to user's input
				for(int i = 0; i < size; i++)
				{
					codeMaker[i] = rand()%sizeRanT+sizeRanF;
				}

				for(int i = 0; i < size; i++)
				{
					switch(codeMaker[i])
					{
						case 1: codeMakerL[i] = 'B'; break;
						case 2: codeMakerL[i] = 'R'; break;
						case 3: codeMakerL[i] = 'Y'; break;
						case 4: codeMakerL[i] = 'W'; break;
					}
				}

				//Output sequence to binary file
				outFile << "The sequence: ";
				for(int i = 0; i < size; i++)
				outFile << codeMakerL[i] << " ";

				turnLeft = 11;							//Reset turnLeft
				gamestatus = 'Y';						//Game status is yes playing

				while(gamestatus == 'Y' || gamestatus == 'y')
				{

					markO = 0;							//User's right guess reset

					//Output how many turn user have left
					cout << "You have " << turnLeft-1 << " turns left!\n";
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
							if(codeBreaker[count] == codeMakerL[i] && count == i)
							{
								markO++;
							}
						}
					}

					//Output how may numbers the user got right
					cout << "You have " << markO << " colors right!";
					cout << endl;

					turn++;							//Adding a turn

					//Check for win function to see if the user get all the numbers right
					gamestatus = checkWinF(outFile, markO, turn, gamestatus,
							              turnLeft, codeMakerL, size);
				}
				//End the match. Prompt for continuation
				cout << "\nDo you want to continue?(Y/N): ";
				cin >> play;						//Input the decision
			}
		}
		else if(menuChoice == 2)					//If the user picks 2
		{
			TTT game;

			//Calling on OutputInstruct function
			game.OutputInstruct();

			//Prompting players if they want to play
				cout << "Do you want to start the game (Y/N): ";
				cin >> play;
				cout << endl;

			//While loop that runs the actual tic tac toe game
			while(play == 'Y' || play == 'y')
			{
				// Initializes board with blanks
				game.InitBoard(boardAr);

				// Sets token so that first player is 'X'
				token = 'X';

				// Loop that runs if changeName is 'y' or 'Y'
				if(changeName == 'Y' || changeName == 'y')
				// Calling on GetPlayers function
					game.GetPlayers(player1, player2);

				do
				{
					game.DisplayBoard(boardAr);
					game.GetAndCheckInp(boardAr, token, player1, player2);
					token = game.SwitchToken(token);
					gameStatus = game.CheckWin(boardAr);
				}while(gameStatus == 'N');

				game.DisplayBoard(boardAr);

				game.OutputWinner(gameStatus, player1, player2);

				cout << "Do you want to play again? ";
				cin >> play;
				cout << endl;

				if (play == 'Y' || play == 'y')
				{
					cout << "Would you like to change your names? ";
					cin >> changeName;
				}
			}
		}

		//Other input choice other than 1, 2, 3 or 4
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
