/*
 * File: main.cpp
 * Created on: October 5, 2015 6:06 PM
 * Author: Anh Le
 * Purpose: Read and writes array to a file
 */

//System Libraries
#include <iostream>			//Input/Output stream Library
#include <fstream>			//File stream Library
#include <iomanip>  		//Format Library
#include <string.h>			//String Library
using namespace std;		//Utilize standard name-space directly

// Function prototypes
void arrayToFile(string,int *, int);
void fileToArray(string, int *, int);

int main()
{
	// Declare variables
	string outFileName;		// Holds name of output file
	string inFileName;		// Holds name of input file
	const int SIZE = 10;
	int arr[SIZE] = {2,15,53,21,56,84,1,24,80,27};

	// Write array to file
	arrayToFile(outFileName, arr, SIZE);

	// Read data from file to array
	fileToArray(inFileName, arr, SIZE);

	// Output data in array
	for(int i=0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
// Defining function arrayToFile
void arrayToFile(string outName, int *array, int size)
{
	ofstream outFile;

	// Read in name of output file
	cout << "Enter the name of the output file you want to open: ";
	cin >> outName;
	outFile.open(outName.c_str());

	// Writes data from array to file
	for(int i=0; i<size; i++)
	{
		outFile << array[i] << " ";
	}
	outFile.close();
}

// Defining function fileToArray
void fileToArray(string inName, int *array, int size)
{
	ifstream inFile;
	// Read in name of input file

	cout << "Enter the name of the input file you want to open: ";
	cin >> inName;

	inFile.open(inName.c_str());

	// Read in data from file
	for(int i=0; i<size; i++)
	{
		inFile >> array[i];
	}
	inFile.close();
}
