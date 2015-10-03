/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on September 12, 2015, 6:12 PM
 * Purpose: Calculating and finding mode
*/

//System Libraries
#include <iostream> 	//Input/Output stream Library
#include <iomanip>  	//Format Library
using namespace std;	//Utilize standard name-space directly

int main()
{
	int number;
	int mode;
	int count = 1;
	int countMode = 1;

	int SIZE = 5;
	int array[] = {1,3,2,2,4};

	number = array[0];

	for (int i=1; i<SIZE; i++)
	{
	      if (array[i] == number)
	      { // count occurrences of the current number
	         count++;
	        // mode = number;
	      }

	      else
	      {
	    		if (count > countMode)
	            {
	                  countMode = count;
	                  mode = number;
	            }
	           count = 1;
	           number = array[i];
	      }

	}
	//if (countMode == 1)
	    		 // cout << "There is no mode in the array\n";
	cout << "mode : " << mode << endl;
}

