/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 9, 2015, 10:45 AM
 * Purpose: Display informations for soccer players
 */

//System Libraries
#include <iostream> 				//Input/Output stream Library
#include <iomanip>  				//Format Library
#include <string.h>					//String Library
using namespace std;				//Utilize standard name-space directly

	//Declare structure
	struct soccerPlayer
	{
		string playerName;			//Input - Player's name
		int playerNum;				//Input - Player's team number
		int pointsScored;			//Input - Points scored by the player
	};

int main()
{
	//Declare variables
	const int SIZE = 12;			// Size of array, to fit 12 players
	soccerPlayer players[SIZE];		//Array contain players
	float total;					//Total points scored by players
	int highestPoints;				//Highest points
	string highPlayer;				//highest player name
	int highNum;					//highest player number
	float average;					//average point scored

	//Prompt user to enter player information
	for(int count = 0; count < SIZE; count++)
	{
		cout << "Enter the player's name:" << endl;
		getline(cin, players[count].playerName);
		cout << "Enter the player's number:" << endl;
		cin >> players[count].playerNum;
		cout << "Enter the number of points scored by player:" << endl;
		cin >> players[count].pointsScored;
		cin.ignore(100, '\n');

		total += players[count].pointsScored;
	}
		average = total / SIZE;

 	//Looking for the highest player's number, point, name
 	highPlayer = players[0].playerName;
	highestPoints = players[0].pointsScored;
	highNum = players[0].playerNum;
	for(int count = 1; count < SIZE; count++)
	{
		if(players[count].pointsScored > highestPoints)
		{
			highPlayer = players[count].playerName;
			highNum = players[count].playerNum;
			highestPoints = players[count].pointsScored;
		}
	}

	//Display table with player information
	cout << left;
	cout << setw(25) << "Player Name" << setw(25) << "Player Number" << "Player points" << endl;
 	cout << "---------------------------------------------------------------" << endl;

	for (int count = 0; count < SIZE; count++)
	{
		cout << setw(25) << players[count].playerName << setw(25) << players[count].playerNum
			 << players[count].pointsScored << endl;
	}

	//Display total and average
 	cout << "\nTotal points scored by team:                 " << total 		 << endl;
 	cout << "Average points scored:             	 	    " << average 	 << endl;

	//Display player info with highest points
	cout << "Player who scored the most points:           " << highPlayer 	 << endl;
	cout << "Player's number:                             " << highNum 		 << endl;
	cout << "Points scored by this player:                " << highestPoints << endl;

	return 0;
}
