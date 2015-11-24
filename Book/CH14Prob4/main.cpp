/*
 * main.cpp
 *
 *  Created on: Nov 23, 2015, 9:00 PM
 *  Author: Anh Le
 *  Purpose: Convert a hours to work day
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
class Numdays
{
	private:
		float days;
		int hours;

	public:
		Numdays();
		Numdays(int h);
		void setHours(int);
		void setDays(double);
		int getHours();
		float getDays();

	float operator + (const Numdays a)
	{
		return hours + a.hours;
	}
	float operator - (const Numdays a)
	{
		return hours - a.hours;
	}
	Numdays operator ++ ()
	{
		++hours;
		days = hours / 8.00;
		return *this;
	}
	Numdays operator ++ (int)
	{
		Numdays temp(hours);
		hours++;
		days = (hours + 1) / 8.00;
		return temp;
	}
	Numdays operator -- ()
	{
		--hours;
		days = hours / 8;
		return *this;
	}
	Numdays operator -- (int)
	{
		Numdays temp(hours);
		hours--;
		days = hours / 8.00;
		return temp;
	}
};

Numdays::Numdays()
{
	days = 0;
	hours = 0;
}

Numdays::Numdays(int h)
{
	hours = h;
	days = 0;
}

void Numdays::setHours(int h)
{
	hours = h;
	days = h / 8.00;
}

void Numdays::setDays( double d)
{
	if (hours >= 8)
		days += 1;
}

int Numdays::getHours()
{
	return hours;
}

float Numdays::getDays()
{
	return days-1;
}

int main(int argc, char** argv)
{
	Numdays work(0);
	int numHours;

	cout << "Enter the amount of hours worked: ";
	cin >> numHours;
	cin.ignore();

	work.setHours(numHours);
	work.setDays(numHours);

	cout << "The amount of hours : " << work.getHours() << endl;
	cout << numHours << " work hours = " << work.getDays() << " days " << endl;

	return 0;					//End code
}
