/*
 * main.cpp
 *
 *  Created on: Nov 23, 2015, 12:31 PM
 *  Author: Anh Le
 *  Purpose: Convert a month and day into a number
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
class DayOfYear
{
private:
	int day;
	static const int MonthDays[];
	static const string MonthName[];
public:
	DayOfYear(string month1, int day1)
	{
			int count = 0;							//count pos
			int result = 0;							//Result

			while(month1 != MonthName[count])		//Check if month input is which pos
				count++;							//Increment count

			result = MonthDays[count-1] + day1;		//result is the sum of day input and month day
			day = result;							//Set day to result
	}
	void print();
};

void DayOfYear::print()
{
	cout << day;									//Output the day
}

//Set up the month day and name
const int DayOfYear::MonthDays[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
const string DayOfYear::MonthName[] = {"January", "February", "March", "April", "May", "June",
									   "July", "August", "September", "October", "November", "December"};


int main(int argc, char** argv)
{
	int day;								//Day input
	string month;							//month input

	//Prompt for user's input of day
	cout << "Enter a day: ";
	cin >> day;
	cin.ignore();

	//While day is legitimate between 1 and 365
	while(day < 0 || day > 365)
	{
		cout << "\nInvalid number! Please re-enter(1-365): " << endl;
		cin >> day;
	}

	//Prompt for user's input of month
	cout << "Enter the month: ";
	getline(cin, month);

	//Input month and day into the class
	DayOfYear output(month, day);

	//Output the day calculated
	output.print();

	return 0;					//End code
}
