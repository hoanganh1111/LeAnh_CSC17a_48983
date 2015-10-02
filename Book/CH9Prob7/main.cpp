/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 2, 2015, 1:58 PM
 */

//Libraries
#include <iomanip>
#include <iostream>
using namespace std;


// Function prototypes
 void arrSelectSort(int *[], int);
 void showArray(const int [], int);
 void showArrPtr(int *[], int);

 int main()
 {
	 int NUM_DONATIONS; // Number of donations

	 cout << "Enter the number of donations: \n";
	 cin >> NUM_DONATIONS;

 int* donations = NULL;  // An array containing the donation amounts.
 int* *arrPtr;	// An array of pointers to int.

 donations = new int[NUM_DONATIONS];
 //*arrPtr = new int[NUM_DONATIONS];

 //Initialize elements to 0;
 for(int count = 0; count < NUM_DONATIONS; count++)
  {
	 donations[count] = 0;
	  //*arrPtr[count] = {nullptr};
  }

 cout << "Enter the donation amounts: \n";
 for(int count = 0; count < NUM_DONATIONS; count++)
 {
	 cin >> donations[count];
 }

// Each element of arrPtr is a pointer to int. Make each
 // element point to an element in the donations array.
 for (int count = 0; count < NUM_DONATIONS; count++)
 {
 arrPtr[count] = &donations[count];
 *arrPtr[count] = donations[count];
 }

 // Sort the elements of the array of pointers.
 arrSelectSort(arrPtr, NUM_DONATIONS);

 // Display the donations using the array of pointers. This
 // will display them in sorted order.
 cout << "The donations, sorted in descending order are: \n";
 showArrPtr(arrPtr, NUM_DONATIONS);

 // Display the donations in their original order.
 cout << "The donations, in their original order are: \n";
 showArray(donations, NUM_DONATIONS);

 //Free the dynamic allocation
 delete [] donations;
 delete [] *arrPtr;

 donations = NULL;
 *arrPtr = NULL;

 return 0;
 }


//Initialize selectionSort
void arrSelectSort(int *arr[], int size)
 {
 int startScan, minIndex;
 int *minElem;

for (startScan = 0; startScan < (size - 1); startScan++)
 {
 minIndex = startScan;
 minElem = arr[startScan];
 for(int index = startScan + 1; index < size; index++)
 {
 if (*(arr[index]) > *minElem)
{
 minElem = arr[index];
 minIndex = index;
 }
}
 arr[minIndex] = arr[startScan];
 arr[startScan] = minElem;
 }
}

 //***********************************************************
// Definition of function showArray. *
// This function displays the contents of arr. size is the *
// number of elements. *
 //***********************************************************

void showArray(const int arr[], int size)
 {
for (int count = 0; count < size; count++)
cout << arr[count] << " ";
cout << endl;
 }

void showArrPtr(int *arr[], int size)
 {
 for (int count = 0; count < size; count++)
 cout << *(arr[count]) << " ";
cout << endl;
 }


