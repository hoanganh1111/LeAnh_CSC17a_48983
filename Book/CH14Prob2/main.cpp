/*
 * main.cpp
 *
 *  Created on: Nov 23, 2015, 11:29 AM
 *  Author: Anh Le
 *  Purpose: Convert a number into a actual month and day
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
public:
	static const int MonthDays[];
	static const string MonthName[];
	void print(int);
};

void DayOfYear::print(int day)
{
	int count = 0;					//Month count

	//While month days is not in the range of day
	while (DayOfYear::MonthDays[count] < day)
		count = (count + 1) %12;	//set count to mod of count+1 12

	//Output the month and day according to the date mod
	cout << DayOfYear::MonthName[count] << " " << day - DayOfYear::MonthDays[count-1];
}

//Set up the month day and name
const int DayOfYear::MonthDays[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
const string DayOfYear::MonthName[] = {"January", "February", "March", "April", "May", "June",
									   "July", "August", "September", "October", "November", "December"};


int main(int argc, char** argv)
{
	DayOfYear dayofyear;			//Declaring class day of year
	int day;						//day input

	//Prompt for user's input
	cout << "Enter a number to convert into a month and day: ";
	cin >> day;						//Input day

	//While day is legitimate between 1 and 365
	while(day < 0 || day > 365)
	{
		//Re-enter the day
		cout << "\nInvalid number! Please re-enter(1-365): " << endl;
		cin >> day;
	}

	dayofyear.print(day);			//Output the month and day followed

	return 0;						//End code
}
