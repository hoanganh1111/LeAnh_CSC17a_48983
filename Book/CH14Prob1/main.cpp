/*
 * main.cpp
 *
 *  Created on: Nov 22, 2015, 1:03 PM
 *  Author: Anh Le
 *  Purpose: Display whole dollar amounts for the number between 0-9999
 */

//System Libraries
#include <iostream> 				//Input/Output stream Library
#include <iomanip>  				//Format Library
#include <string.h>					//String Library
#include <fstream>					//Input/Output stream text files
#include <cstdlib> 					//Random Library
#include <ctime>    				//Time Library
#include <stdlib.h>					//Standard Library
using namespace std;				//Utilize standard name-space directly


//Class declaration
class Numbers
{
private:
	int number;							//Number input
	static string one[];				//single digit from 1-9
	static string teen[];				//digit from 10-19
	static string ten[];				//digit 20-90 in ten's
	static string hundred[];			//digit 100-900 in hundred's
	static string thousand[];			//digit 1000-9000 in thousands's
public:
	Numbers();
	Numbers(int num){setNum(num);};		//Numbers function to compare
	void setNum(int num){number= num;};	//Copy and paste the new number
	void print();						//Output the number in words
};
string Numbers::one[]  = {"one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
string Numbers::teen[] = {"ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ",
						  "seventeen ", "eighteen ", "nineteen "};
string Numbers::ten[]  = {"twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
string Numbers::hundred[]  = {"one hundred ", "two hundred ", "three hundred ", "four hundred ", "five hundred ",
							  "six hundred ", "seven hundred ","eight hundred ","nine hundred "};
string Numbers::thousand[] = {"one thousand ", "two thousand ", "three thousand ", "four thousand ", "five thousand ",
							  "six thousand ", "seven thousand ","eight thousand ","nine thousand "};

void Numbers::print()
{
	if(number == 0)							//If number = 0
		cout << "zero";						//Output zero

	if (number >= 1000)						//Number in the range of thousands
	{
		cout << thousand[number/1000-1];	//Output the words according to array pos
		number %= 1000;						//Mod the number to 1000
	}
	if (number >= 100)						//Number in the range of hundreds
	{
		cout << hundred[number/100-1];		//Output the words according to array pos
		number %= 100;						//Mod the number to 100
	}
	if (number >= 20)						//Number in the range of ten
	{
		cout << ten[number/10-2];			//Output the words according to array pos
		number %= 10;						//Mod the number to 10
	}
	if (number >= 10 && number <= 19)		//Number is between 10 and 19
		cout << teen[number%10];			//Output the words according to array pos
	if (number >=1 && number <= 9)			//Number is between 1 and 9
		cout << one[number-1];				//Output the words according to array pos
}

int main(int argc, char** argv)
{
	int number;								//Number being input

	//Prompt for user's input
	cout << "Enter a number between 0 and 9999: ";
	cin >> number;							//Input the number

	while(number < 0 || number > 9999)		//While the number is not in the range of 0-9999
	{
		cout << "Invalid number! Please re-enter(0-9999): ";
		cin >> number;						//Re-enter the number
	}

		Numbers input(number);				//Pass the number into the class functions
		input.print();						//Print the results into words

	return 0;								//End code
}
