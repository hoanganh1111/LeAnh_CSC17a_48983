/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 4, 2015, 11:27 AM
 * Purpose: Detecting words in a string
 * 			Output average number of each word
 */

//System Libraries
#include <iostream> //Input/Output stream Library
#include <iomanip>  //Format Library
#include <string>	//String Library
using namespace std;//Utilize standard name-space directly

//Function prototyped
int wordCheck(char *, const int);
int letterCheck(char *, const int, int);

int main(int argc, char** argv)
{
	//Declaring variables
	const int SIZE = 70;	//constant size of the string
	char userInput[SIZE];	//declaring string
	int words;				//words count
	int avg;			//average letter in each word

	//Prompt for user's input the string
	cout << "Enter the sentence(cannot be longer than 70 characters): \n";
	cin.getline(userInput, SIZE);

	//Calling the wordCheck function
	//Calling the letterCheck function
	//OUTPUT the average letters in each word
	words = wordCheck(userInput, SIZE);
	avg = letterCheck(userInput, SIZE, words);

	//COUT the numbers of words found as well as the average letters
	cout << "Numbers of words found in the sentence: " << words << "words"   << endl;
	cout << "Average number of letters in each word: " << avg 	<< "letters" << endl;

	//Exit the code
	return 0;
}

//Initializing wordCheck function
int wordCheck(char *strPtr, const int size)
{
	//Declaring variables
	int count = 0;
	int words = 1;

	for(;count < size; count ++)	//Using for loops to look for word
		{
		if(strPtr[count] == ' ')	//If the word seperate by blank space
			words++;				//Add a word
		}

	return words;					//Return words found
}

//Initializing letterCheck function
int letterCheck(char *strPtr, const int size, int words)
{
	//Declaring variables
	int letters = 0;

	//Using for loops to look for letters
	for(int count=0;count < size; count ++)
		{
		//Character between A-Z or a-z count as a letter
		if(((strPtr[count] >= 'a') && (strPtr[count] <= 'z')) ||
		   ((strPtr[count] >= 'A') && (strPtr[count] <= 'Z')))

			letters++;				//Add a letter
		}

		//Return the average letters in each word
		return letters/words;
}

