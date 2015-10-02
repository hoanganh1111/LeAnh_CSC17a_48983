/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 2, 2015, 12:12 AM
 */

// This program shows the donations made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donations in order from lowest to highest
// and in the original order they were received.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void SelectSort(int *, int);
void showArray(int *, int);

int main()
{
	int NUM_DONATIONS; // Number of donations
	int *donations;

	cout << "Enter the number of donations: \n";
	cin >> NUM_DONATIONS;

// An array containing the donation amounts.
donations = new int[NUM_DONATIONS];

cout << "Enter the donations amount: \n";
for(int count= 0; count < NUM_DONATIONS; count++)
{
	cin >> donations[count];
}

// Display the donations in their original order.
cout << "The donations, in their original order are: \n";
showArray(donations, NUM_DONATIONS);

// Sort the elements of the array of pointers.
SelectSort(donations, NUM_DONATIONS);

// Display the donations using the array of pointers. This
// will display them in sorted order.
cout << "The donations, sorted in ascending order are: \n";
showArray(donations, NUM_DONATIONS);


delete  [] donations;
donations = 0;

return 0;
}

void SelectSort(int array[], int size)
{
	int startScan, minIndex, minValue;
		for(startScan = 0; startScan <(size-1); startScan++)
		{
					minIndex = startScan;
					minValue = array[startScan];
	for(int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
					minValue = array[index];
					minIndex = index;
			}
		}
			array[minIndex] = array[startScan];
			array[startScan] = minValue;
		}
}

//***********************************************************
// Definition of function showArray. *
// This function displays the contents of arr. size is the *
// number of elements. *
//***********************************************************

void showArray(int array[], int size)
 {
	for (int count = 0; count < size; count++)
		cout << array[count] << " ";
	cout << endl;
 }
