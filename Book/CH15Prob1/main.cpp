/*
 * main.cpp
 *
 *  Created on: Nov 28, 2015, 11:29 AM
 *  Author: Anh Le
 *  Purpose: Collecting data from 2 different
 *  		 classes and display the output
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
class employee
{
private:
	string employeeName;
	int employeeNum;
	int hireDay;
	int hireYear;
	int hireMonth;

public:
	employee(string name, int num, int d, int m, int y)
	{
		employeeName = name;
		employeeNum = num;
		hireDay = d;
		hireYear = y;
		hireMonth = m;
	}
	void setEmplName();
	string getEmplName() const;
	void setEmplNumber();
	int getEmplNumber() const;
	void setHireDate();
	int getHireDate() const;


void setEmplName(string name)
{
	employeeName = name;
}

string getEmplName()
{
	return employeeName;
}

void setEmplNumber(int n)
{
	employeeNum = n;
}

int getEmplNumber()
{
	return employeeNum;
}

void setHireDay(int d)
{
	hireDay = d;
}

int getHireDay()
{
	return hireDay;
}
void setHireMonth(int m)
{
	hireMonth = m;
}

int getHireMonth()
{
	return hireMonth;
}
void setHireYear(int y)
{
	hireYear = y;
}

int getHireYear()
{
	return hireYear;
}
};

class productionWorker
{
private:
	int shift;
	float hourlyPayRate;

public:
	productionWorker(int s, float hpr)
	{
		shift = s;
		hourlyPayRate = hpr;
	}
	void setShift();
	int getShift() const;
	void setHourlyPayRate();
	float getHourlyPayRate() const;

void setShift(int s)
{
	shift = s;
}

int getShift()
{
	return shift;
}

void setHourlyPayRate(float hpr)
{
	hourlyPayRate = hpr;
}

float getHourlyPayRate()
{
	return hourlyPayRate;
}

};

int main(int argc, char** argv)
{
	string name;						//Employe's name
	int number, shift;					//Number and shift
	int day, month, year;				//Day, month and year input
	float payRate;						//Employee's pay rate

	//Prompt to ask the user for the employee's name
	cout << "Enter the employee's name  : ";
	getline(cin, name);

	//Prompt to ask the user for the employee's number
	cout << "Enter the employee's number: ";
	cin >> number;

	// Input the employee's hire date
	cout << "Enter the employee's hire date(M D Y): ";
	cin >> day >> month >> year;

	//Input the shift the employee is working
	cout << "Enter the employee's work shift(1-2): ";
	cin >> shift;

	while(shift < 1 || shift > 2)
	{
		cout << "Invalid input! Please re-enter(1-2): ";
		cin >> shift;
	}

	//Input employee's pay rate
	cout << "Enter the employee's pay rate: $";
	cin >> payRate;

	productionWorker in(shift, payRate);					//Production Worker class.
	employee into(name, number, day, month, year);			//Employee class.

	//Output the employee's data.
	cout << endl << endl;
	cout << "Employee's Name      :	 " << into.getEmplName() 	<< endl;
	cout << "Employee's Number    :	 " << into.getEmplNumber() 	<< endl;
	cout << "Employee's Hire Date :	 " << into.getHireMonth() 	<< "/"
									   << into.getHireDay()     << "/"
									   << into.getHireYear()	<< endl;
	cout << "Employee's Shift     :	 " << in.getShift() 		<< endl;
	cout << "Employee's Pay Rate  :   $" << setprecision(2) 	<< fixed
									   << in.getHourlyPayRate();

	return 0;					//End Code
}
