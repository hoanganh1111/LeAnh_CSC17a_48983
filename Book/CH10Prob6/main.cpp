/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 4, 2015, 11:27 AM
 * Purpose: Detecting vowels and consonants in a string
 */

//System Libraries
#include <iostream> 	//Input/Output stream Library
#include <iomanip>  	//Format Library
#include <string.h>		//String Library
using namespace std;	//Utilize standard name-space directly

//Function prototyped
int vowelCheck(char *, const int);
int consCheck (char *, const int);
void menuDisplay();

int main(int argc, char** argv)
{
	//Declaring variables
	int SIZE = 20;				//constant size of the string
	char userInput[SIZE];		//declaring string
	int vowelN = 0;				//vowels in the string
	int consN = 0;				//Consonants in the string
	char selection;				//User's selection for the menu
	/************/
	inputLine:
		{
	cout << "Enter your sentence: " << endl;//Ask for input
	cin.getline(userInput ,SIZE);			//INPUT user's string

	SIZE = strlen(userInput);				//Setting size to length input
		}
	/************/
	inputSelect:
	{
		menuDisplay();						//Display menu
		cout << "Input your selection: \n";	//Ask for selection
		cin >> selection;					//INPUT selection
	}
	/************/

	while(selection != 'e' || selection == 'E')		//while selection is not E
	{
		if(selection == 'a' || selection == 'A')	//Selection is a or A
		{
			vowelN = vowelCheck(userInput, SIZE);	//Calling vowelCheck function

			//OUTPUT the vowels and input selection again
			cout << "Number of vowels: " << vowelN << endl << endl;
			cout << "Input your selection: \n";
			cin >> selection;
		}
		else if(selection == 'b' || selection == 'B')//Selection is b or B
		{
			consN  = consCheck (userInput, SIZE);	//Calling consCheck function

			//OUTPUT the consonants and input selection again
			cout << "Number of consonants: " << consN << endl<< endl;
			cout << "Input your selection: \n";
			cin >> selection;
		}
		else if(selection == 'c' || selection == 'C')//Selection is c or C
		{
			vowelN = vowelCheck(userInput, SIZE);	//Calling vowelCheck function
			consN  = consCheck (userInput, SIZE);	//Calling consCheck function

			//OUTPUT the vowels, consonants and input selection again
			cout << "Number of vowels: " << vowelN << endl;
			cout << "Number of consonants: " << consN << endl<< endl;
			cout << "Input your selection: \n";
			cin >> selection;
		}
		else if(selection == 'd' || selection == 'D')//Selection is d or D
		{
			goto inputLine;				//Go to input string
			goto inputSelect;			//Go to input selection
		}
		else										//Other selection input
		{
			//OUTPUT error, input selection again
			cout << "Unknown selection, please enter again: \n";
			cin >> selection;
		}
	}

	//Exit code
	return 0;
}

//Initializing vowelCheck function
int vowelCheck(char *strPtr, const int size)
{
	//Declaring variables
	int vowels = 0;
	char temp;

	//Loop to check the vowels
	for(int count = 0; count < size; count++)
	{
		//Setting temp character to the corresponding letter
		temp = strPtr[count];

		//Looking for vowels: a,e,i,o,u,y
		if(temp == 'a' || temp == 'A' || temp == 'e' || temp == 'E'||
		   temp == 'i' || temp == 'I' || temp == 'o' || temp == 'O'||
		   temp == 'u' || temp == 'U' || temp == 'y' || temp == 'Y')
		vowels++;						//Accumulating vowels
		else							//Else, skip them
		{
										//Move on to next part
		}
	}

	return vowels;						//Return consonants found
}

//Initializing vowelCheck function
int consCheck(char *strPtr, const int size)
{
	//Declaring variables
	int cons = 0;
	char temp;

	for(int count = 0; count < size; count++)	//Loop to check the consonants
	{
		temp = strPtr[count];			//Setting temp character to the corresponding letter

		switch(temp)
		{
		//Looking for consonants: b,c,d,f,g,h,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,z
		case'b':case'B': case'c':case'C': case'd':case'D': case'f':case'F': case'g':case'G':
		case'h':case'H': case'j':case'J': case'k':case'K': case'l':case'L': case'm':case'M':
		case'n':case'N': case'p':case'P': case'q':case'Q': case'r':case'R': case's':case'S':
		case't':case'T': case'v':case'V': case'x':case'X': case'z':case'Z':
			cons++;						//Accumulating consonants
			break;						//Move on to next part
		default:						//Else, skip them
			break;						//Move on to next part
		}
	}

	return cons;						//Return consonants found
}

//Initialize menuDisplay function
void menuDisplay()
{
	//OUTPUT menu
	cout << "A) Count the number of vowels in the string\n";
	cout << "B) Count the number of consonants in the string\n";
	cout << "C) Count both the vowels and consonants in the string\n";
	cout << "D) Enter another string\n";
	cout << "E) Exit the program\n";
}
