/******************************************************************************
* class.cpp
* This header.cpp is created to define and declares all the class TTT public
* functions that will be use in the main.cpp. It includes:
*
* OutputInstruct() : Output the game rules and how to play tic tac toe
* InitiBoard() 	   : Initialized board to 0 or else you will get garbages
* DisplayBoard()   : Display the board with 0 in the 2 dimensional array
* GetAndCheckInput():Check to see if the input is valid for the array slot
* CheckWin(): Check the possibilities for the player to win the match
* GetPlayers(): Get players names
* SwitchToken(): Switch between X and O in every turns
* Output Winner(): Output the winner according to checkwin() and getplayers()
*
*****************************************************************************/

//System Libraries Header
#include "functions.h"

/******************************************************************************
* OutputInstruct
* This function outputs instructions to the users. There are no input
* or output parameters for this function as it only displays text to
* the screen.
*
* RETURNS: nothing
* -> Displays the instructions to the user
*****************************************************************************/
void TTT::OutputInstruct()
{
	cout << "*TIC-TAC-TOE" << endl << endl;
	cout << "*There are two players 'X' and 'O'. " << endl << endl;
	cout << "*X always goes first." << endl << endl;
	cout << "*Players alternate placing Xs and Os on the board until " << endl;
	cout <<	" either (a) one player has three in a row, horizontally, " << endl;
	cout << " vertically or diagonally, or (b) all nine squares are " << endl;
	cout <<	" filled." << endl << endl;
	cout << "*If a player is able to draw three X's or three O's in a " << endl;
	cout <<	" row, that player wins." << endl << endl;
	cout << "*If all nine squares are filled and neither player has " << endl;
	cout <<	" three in a row, the game is a draw." << endl << endl;
}

/******************************************************************************
* InitBoard
* This function initializes each spot in the board to a space ' '.
*
* RETURNS: Board initialized with all spaces
*****************************************************************************/
void TTT::InitBoard(char boardAr[][COLUMNS]) // tic-tac-toe board – OUT
{
	for(int i = 0; i < ROWS; i ++)
	{
		for (int j = 0; j < COLUMNS; j ++)
			boardAr[i][j] = ' ';
	}
}

/******************************************************************************
* DisplayBoard
* This function outputs the tic tac toe board including the tokens
* played in the proper format (as described below).
*
* 	 				1 		 2 	      3
*				 [1][1] | [1][2] | [1][3]
* 					   | 	    |
* 	 1 				   | 	    |
* 					   | 	    |
* 				 --------------------------
* 				 [2][1] | [2][2] | [2][3]
* 					   | 		|
* 	 2 				   | 		|
* 					   | 	    |
* 				 --------------------------
* 				 [3][1] | [3][2] | [3][3]
* 				       | 		|
* 	 3 				   | 		|
*					   |	    |
*
* RETURNS: nothing
* -> outputs the current state of the board
*****************************************************************************/

void TTT::DisplayBoard(const char boardAr[][COLUMNS])
{
	int i;
	int j;

	system("cls");

	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";
		for (i = 0; i < 3; i++)
	{
			cout << setw(7) << "[" << i+1 << "][1] | " << "[" << i+1;
			cout << "][2] | " << "[" << i+1 << "][3]" << endl;
			cout << setw(14) << "|" << setw(9) << "|" << endl;

			for (j = 0; j < 3; j++)
		{
				switch(j)
			{
					case 0: cout << i + 1 << setw(9) << boardAr[i][j];
					cout << setw(4) << "|";
					break;

					case 1: cout << setw(4) << boardAr[i][j];
					cout << setw(5) << "|";
					break;

					case 2: cout << setw(4) << boardAr[i][j] << endl;
					break;

					default: cout <<"ERROR!\n\n";
			}
	}
	cout << setw(14)<< "|" << setw(10) << "|\n";

			if (i != 2)
		{
			cout << setw(32) << "--------------------------\n";
		}
	}
	cout << endl << endl;
}

void TTT::GetAndCheckInp(char boardAr[][COLUMNS], char token, string player1, string player2)
{
	bool retry;
	int column;
	int row;
		switch(token)
		{
			case 'X': cout << player1 << " it's your turn." << endl;
			break;
			case 'O': cout << player2 << " it's your turn." << endl;
			break;
		}
		cout << "Enter your move: ";
		cin >> row;
		cin	>> column;
		do
		{
			if(row<1 || row>ROWS || column<1 || column>COLUMNS)
				retry= true;
			else if(boardAr[row-1][column-1] != ' ')
				retry=true;
			else
				retry = false;
			if(retry == true)
			{
				cout<<"Invalid move, try again ";
				cin>>row;
				cin>>column;
			}
			else
				boardAr[row-1][column-1]= token;
		}while(retry == true);
}

char TTT::SwitchToken(char token)
{
	// If token is currently X, switch it to O
	if(token == 'X')
	{
		token = 'O';
	}

	// If token is currently O, switch it to X
	else
	{
		token = 'X';
	}
	return token;
}

/******************************************************************************
* GetPlayers
* This function prompts the user and gets the input for the players’ names.
* player1 will always contain the name of the player that is using the X token.
* player2 will always contain the name of the player that is using the O token.
*
* RETURNS: the players names through the variables player1 and player2.
*****************************************************************************/
void TTT::GetPlayers(string& player1, 	// Player X’s name
					string& player2) 	// Player O’x name
{
	cin.ignore(100, '\n');
	cout << "\nEnter the first player's name:  ";
	getline(cin, player1);

	cout << "\nEnter the second player's name: ";
	getline(cin, player2);
}

char TTT::CheckWin(char boardAr[][COLUMNS])
{
	int r=0;    // Number for rows
	int c=0;	// Number for columns
	char W;		// Winning

	// Check 3 rows of X
	if (boardAr[r][c] =='X' && boardAr[r][c+1] == 'X'
	    && boardAr[r][c+2]== 'X' )
		W = 'X';
	else if (boardAr[r+1][c]== 'X' && boardAr[r+1][c+1]== 'X'
			 && boardAr[r+1][c+2]== 'X' )
		W = 'X';
	else if (boardAr[r+2][c] == 'X'&& boardAr[r+2][c+1]== 'X'
			 && boardAr[r+2][c+2]== 'X')
		W = 'X';

	// Check 3 columns of X
	else if (boardAr[r][c] =='X' && boardAr[r+1][c]== 'X'
			 && boardAr[r+2][c]== 'X')
		W = 'X';
	else if (boardAr[r][c+1]=='X' && boardAr[r+1][c+1]=='X'
			 && boardAr[r+2][c+1]== 'X')
		W = 'X';
	else if (boardAr[r][c+2]=='X' && boardAr[r+1][c+2] =='X'
			 && boardAr[r+2][c+2]== 'X')
		W ='X';

	// Check diagonally for X
	else if (boardAr[r][c] =='X' && boardAr[r+1][c+1]=='X'
			 && boardAr[r+2][c+2]=='X')

		W = 'X';
	else if (boardAr[r+2][c]=='X' && boardAr[r+1][c+1]=='X'
			&& boardAr[r][c+2]== 'X')
		W = 'X';
	// Check 3 rows for O
	else if (boardAr[r][c]=='O' && boardAr[r][c+1]=='O'
			 && boardAr[r][c+2]== 'O' )
		W = 'O';
	else if (boardAr[r+1][c] =='O'&& boardAr[r+1][c+1]=='O'
			 && boardAr[r+1][c+2]== 'O')
	    W = 'O';
	else if (boardAr[r+2][c]=='O' && boardAr[r+2][c+1]=='O'
			 && boardAr[r+2][c+2]== 'O')
	    W = 'O';
	// Check 3 columns for O
	else if (boardAr[r][c]=='O' && boardAr[r+1][c]=='O'
			 && boardAr[r+2][c]== 'O')
	    W = 'O';
	else if (boardAr[r][c+1]=='O' && boardAr[r+1][c+1]=='O'
			 && boardAr[r+2][c+1]== 'O')
	    W = 'O';
	else if (boardAr[r][c+2]=='O' && boardAr[r+1][c+2]=='O'
			 && boardAr[r+2][c+2]== 'O')
	    W = 'O';
	// Check diagonally for O
	else if (boardAr[r][c]=='O' && boardAr[r+1][c+1]=='O'
			 && boardAr[r+2][c+2]== 'O')
	    W = 'O';
	else if (boardAr[r+2][c]=='O' && boardAr[r+1][c+1]=='O'
			 && boardAr[r][c+2]== 'O')
	    W = 'O';
	// Check if the game is a tie
	else if (boardAr[r][c]!= ' ' && boardAr[r][c+1] != ' '
			 &&boardAr[r][c+2]!= ' ' && boardAr[r+1][c]!= ' '
			 && boardAr[r+1][c+1]!= ' ' && boardAr[r+1][c+2]!= ' '
			 && boardAr[r+2][c]!= ' ' && boardAr[r+2][c+1]!= ' '
			 && boardAr[r+2][c+2]!= ' ')
	    W = 'T';
	// Check if the game is still playing
	else
	    W = 'N';

	return W;
}

void TTT::OutputWinner(char whoWon, 		// represents the winner or a value
									// indicating a tied game. - IN
				  string player1, 	// player X’s name - OUT
				  string player2) 	// player O’x name - OUT
{
// 	Switch on winner
	switch (whoWon)
	{
		// Player X wins
		case 'X': cout << player1 << " Is The Winner!" << endl;
		break;

		// Player O wins
		case 'O': cout << player2 << " Is The Winner!" << endl;
		break;

		// Tie
		case 'T': cout << "The game is a tie, you are all losers." << endl;
		break;
	}
}
