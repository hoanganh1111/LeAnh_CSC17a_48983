/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 5, 2015, 11:22 AM
 * Purpose: Input files and change capital letters
 */

//System Libraries
#include <iostream> 	//Input/Output stream Library
#include <iomanip>  	//Format Library
#include <string.h>		//String Library
#include <fstream>		//File stream Library
#include <cctype>
using namespace std;	//Utilize standard name-space directly


void loadFile(ifstream& , char[], const int);

int main(int argc, char** argv)
{
	const int size = 120;
	//string sentence[size];
	char copyFile[size];
	int numSent;

	ifstream inFile;				// Input - The input file that holds names, IDs, and balances
	string inFileName;				// Input - Holds the name of the input file
	string outFileName;				// Input - Holds the name of the output file
	ofstream outFile;				// Output - The output file that will display the fixed sentence


	// Prompt user for file names
	cout << "Enter the name of the input file you want to open: ";
	cin >> inFileName;
	//cout << "Enter the name of the output file you want to open. ";
	//cin >> outFileName;
	//cin.ignore(100, '\n');
	cout << endl;

	inFile.open(inFileName.c_str());
	loadFile(inFile, copyFile, size);
	inFile.close();

	for(int i = 0; i < size; i++)
	{
		putchar(tolower(copyFile[i]));
		if(copyFile[i] == '.')
		{
			putchar(toupper(copyFile[i+1]));
			i++;
		}
	}
	//cout << numSent << endl;

	for(int i = 0; i < size;i++)
	{
		cout << copyFile[i];
	}


	return 0;
}

void loadFile(ifstream& inFile, char sentence[], const int size)
{
	int count = 0;
	//inFile >> sentence[count];
	inFile >> sentence[count];
	//getline(inFile, sentence[count]);
	putchar(toupper(sentence[count]));
	while(!inFile.eof() && count < size)
	{
		inFile >> sentence[count];

		//getline(inFile, sentence[count]);
		//fgets(sentence, size, stdin);
		//scanf ("%[^\n]%*c", sentence);
		//inFile.ignore('\n');
		count++;
	}
}
