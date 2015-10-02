/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 1, 2015, 12:58 AM
 */

//Libraries
#include <iomanip>
#include <iostream>
using namespace std;


//Function prototypes
void selectionSort(int *, int);
float arrayAvg(float, int);


int main()
{
//Define variables
int *array;
float total = 0.0, average;
int size, count;

//Get the number of test scores you want to enter
cout << "How many test scores do you wish to enter?";
cin >> size;

//Dynamically allocate an array large enough to hold that many scores
array = new int[size];

//User's entered test scores
cout << "Enter the test scores below.\n";

for (count = 0; count < size; count++)
{
	//Display score
	cout << "Test Score " << (count + 1) << ": ";
	cin >> array[count];
}

//Input validation. Don't accept negative numbers
while (size < 0)
{
	cout << "You must enter a scores that non-negative" << endl;
	cout << "Please enter again: ";
	cin >> array[count];
}

//Calling function selectionSort
selectionSort(array, size);

//Accumilating total scores as it entered in the array
for (count = 0; count < size; count++)
{
	total += array[count];
}

//Calling function arrayAvg
average = arrayAvg (total, size);

//OUTPUT the sorted test scores
cout << "Test scores in ascending order\n";
cout << "------------------------------\n";
for(int i = 0; i < size; i++)
{
	cout << array[i];
	cout << endl;
}

//OUTPUT the average
cout << fixed << setprecision(2);
cout << "The average of all the test scores is " << average << endl;

//Free dynamically allocated memory
delete [] array;
array = 0; 			//Make TestScores point to null

//Exit the code
return 0;
}


//Initialize selectionSort
void selectionSort(int array[], int size)
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

//Initialize arrAvg function
float arrayAvg (float totalS, int size)
{
float average;
	average = totalS / size;

	return average;
}


