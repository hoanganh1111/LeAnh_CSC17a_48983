/*
 * main.cpp
 *
 *  Created on: Nov 28, 2015, 11:29 AM
 *  Author: Anh Le
 *  Purpose: Displaying time in 24 hour type
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

//Declare class Time
class Time
{
 private:
    int hour;
    int minute;

 public:
    //Sets time t
    void setTime(int &h, int &m)
    {
	    while((h > 24) || (m > 60))
        {

            cerr << "\nError, that isn't in standard format. " << endl;
            cin >> h;
            cin >> m;
        }

        if(h <= 12 && h != 0)
        {
            hour = h;
        }
        else if(h > 12)
        {
          hour = h-12;
        }
        else if(h == 0)
        {
            hour = h+12;
        }

	    minute = m;
    }
    //Getter function for hour variable
	int getHour()
	{
	    return hour;
	}
	//Getter function for minute variable
	int getMinute()
	{
	    return minute;
	}
	//Print function to display the time
	void printTime()
	{
	    cout << "The time right now is ";
        cout << getHour() << ":" << setfill('0') << setw(2) <<
        getMinute();
	}
	//Function that displays whether it is AM or PM
	string timeOfDay(int &x, int &y)
	{
       const string timeArray[2]={"AM", "PM"};
       string noon=" Noon";
       string midnight=" Midnight";

       if(x < 12)
       {
           return timeArray[0];
       }
       else if(x == 12 && y == 0 )
       {
           return noon;
       }
       else if( x == 24 && y == 0)
       {
           return midnight;
       }
       else
        return timeArray[1];

	}
};

int main(int argc, char** argv)
{
	//Declare variables
	Time t;
	int hour;
	int min;

	//Prompt user for input
	cout << "Please enter the hour hand: ";
	cin >> hour;
	cout << "Now enter the minute hand: ";
	cin >> min;
	cout << endl;

	t.setTime(hour, min);			//Set time
	cin.get();
	t.printTime();					//Output time
	//Output the hour and minute
	cout << t.timeOfDay(hour, min) << endl;

	return 0;
}
