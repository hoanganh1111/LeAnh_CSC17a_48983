/*
 * myheader.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: AnhLe
 */

#include "myheader.h"
//Initialize function menuDisplay()
void menuDisplay()
{
	//Outputing the menu select for the mid term program
	cout << "\nMenu for the Final" << endl;
    cout << "Type 1 for problem 1" << endl;
    cout << "Type 2 for problem 2" << endl;
    cout << "Type 3 for problem 3" << endl;
    cout << "Type 4 for problem 4" << endl;
    cout << "Type 5 for problem 5" << endl;
    cout << "Type 6 for problem 6" << endl;
    cout << "Type anything else to exit \n"<<endl;
}

//Initialize function getN()
int getN()
{
	int inN;		//user's input
	//Promp for user's input
	cout << "Enter your choice: ";
	//Input the choice
	cin >> inN;
	//return user's input
	return inN;
}

//Initialize function def()
void def(int inN)
{
	cout << "You typed " << inN << " to exit the program" << endl;
}




