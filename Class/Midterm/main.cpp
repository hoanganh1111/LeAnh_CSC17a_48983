/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 16, 2015, 11:30 AM
 * Purpose: MIDTERM
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


struct statsResult
{
	float Avg;
	float median;
	int *mode;
	int nMode;
	int maxFreq;
};
//Function prototypes
void menuDisplay();
int getN();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();

void sortArray(int[], int);
void printStat(statsResult);

int main(int argc, char** argv)
{
	int inN;

	do
	{
		menuDisplay();
		inN = getN();
		switch(inN)
		{
		case 1:
			problem1();
			break;
		case 2:
			problem2();
			break;
		case 3:
			problem3();
			break;
		case 4:
			problem4();
			break;
		case 5:
			problem5();
			break;
		case 6: //run problem 6
			break;
		case 7: //run problem 7
			break;
		default:
			getN();
			break;
		}
	}while(inN >= 1 && inN <= 7);

	return 0;
}

void menuDisplay()
{
	cout << "\nMenu for the Mid-term" << endl;
    cout << "Type 1 for problem 1" << endl;
    cout << "Type 2 for problem 2" << endl;
    cout << "Type 3 for problem 3" << endl;
    cout << "Type 4 for problem 4" << endl;
    cout << "Type 5 for problem 5" << endl;
    cout << "Type 6 for problem 6" << endl;
    cout << "Type anything else to exit \n"<<endl;
}

int getN()
{
	int inN;
	cout << "Enter your choice: ";
	cin >> inN;
	return inN;
}

void problem1()
{
	struct bank
	{
		string acctNum;
		float balanceBegin;
		float totalCheck;
		float totalDeposit;
	}user;

	float checks = 0;
	float deposits = 0;
	float newBalance = 0;

	user.balanceBegin = 0;
	user.totalCheck = 0;
	user.totalDeposit = 0;

	cout << "Input your account number(5-digits only!)  : ";
	while(getline(cin, user.acctNum) && user.acctNum.size() != 5)
		cout << "Invalid numbers(5 digits), please re-enter : ";

	cout << endl;

	cout << "Your balance at the beginning of the month : $";
	cin >> user.balanceBegin;
	cout << endl;

	while(checks != -1)
	{
		cout << "Input your checks(Enter -1 when you done)  : - $";
		cin >> checks;
		user.totalCheck += checks;
	}

	cout << "(-1 is not a part of the value!)" << endl << endl;

	while(deposits != -1)
	{
		cout << "Input your deposits(Enter -1 when you done): + $";
		cin >> deposits;
		user.totalDeposit += deposits;
	}
	cout << "(-1 is not a part of the value!)\n" << endl;

	newBalance = user.balanceBegin + (user.totalDeposit - user.totalCheck);

	if(newBalance < 0)
	{
		cout << "\nCustomer with account#: "  << user.acctNum;
		cout << fixed << setprecision(2);
		cout << "\nYour new balance is   : $" << newBalance;
		cout << "\nAccount has been overdrawn! "
				"You will be charged $15 fee!\n";

		newBalance += -15.00;

		cout << "Your new balance(plus fee)is: $" << newBalance << endl;
	}

	else
	{
		cout << "\nCustomer with account#: " << user.acctNum << endl;
		cout << fixed << setprecision(2);
		cout << "Your new balance is   : $" << newBalance << endl;
	}
}

void problem2()
{
	struct employee
	{
		string name;
		int hours;
		float rate;
		float gross;
	};

	int size;

	cout << "Input numbers of employee: ";
	cin >> size;
	cin.ignore();

	employee grossPay[size];

	for(int count = 0; count < size; count++)
	{
		cout << "\nEnter the employee's name    : ";
		getline(cin, grossPay[count].name);
		cout << "Enter the hours he/she worked: ";
		while(cin >> grossPay[count].hours && grossPay[count].hours < 0)
			exit(0);
		cin.ignore();
		cout << "Enter the his/her pay rate   : $";
		while(cin >> grossPay[count].rate && grossPay[count].rate < 0)
			exit(0);
		cin.ignore();

		if(grossPay[count].hours >= 0 && grossPay[count].hours <= 40)
		{
			grossPay[count].rate *= 1;
		}
		else if(grossPay[count].hours > 40 && grossPay[count].hours <= 50)
		{
			grossPay[count].rate *= 2;
		}
		else if(grossPay[count].hours > 50)
		{
			grossPay[count].rate *= 3;
		}

		grossPay[count].gross = grossPay[count].rate * grossPay[count].hours;

		cout << fixed << setprecision(2);
		cout << "\n---------------------------------------------------";
		cout << "\n                                    Date 10/28/2015    ";
		cout << "\nPay to the                                                  ";
		cout << "\norder of          " << grossPay[count].name << "            ";
		cout << "\nAmount            " << grossPay[count].gross << "           dollars  ";
		cout << "\nHours worked " << grossPay[count].hours  << " hours";
		cout << "   |   Pay rate       : $" << grossPay[count].rate;
		cout << "\n---------------------------------------------------";
		cout << endl;
	}
}

void problem3()
{
		statsResult mode;
		int size;
		int *array;

		//Input size of the array
		cout << "Enter the size of the array: \n";
		cin >> size;

		array = new int[size];

		//Input the array
		cout << "Enter the numbers in the array(space between each number): ";
		for(int count = 0; count < size; count++)
		{
			cin >> array[count];
		}

		//Sorting the array
		sortArray(array, size);

		//Output sorted array
		cout << "\n{ ";
		for(int count = 0; count < size; count++)
				cout << array[count] << " ";
		cout << "}";

		//Calculating average
		float total = 0.00;

		for(int count = 0; count < size; count++)
			total += array[count];

		mode.Avg = total/size;

		//Calculating median
		if(size % 2 == 0)
			mode.median = (array[size/2] + array[size/2 - 1])/2.0;
		else
			mode.median = array[size/2];

		//Max Frequency
		mode.maxFreq = 0;
		mode.nMode = 0;
		int currentFre = 0;

		for(int count= 0; count < size; count++)
			{
				if(array[count] == array[count+1])
					currentFre++;
				else if(array[count] != array[count+1])
				{
					if(currentFre > mode.maxFreq)
						mode.maxFreq = currentFre;
				currentFre = 1;
			}
		}

		int modeCount = 0;
		int maxCount = 0;
		int currentMode = array[0];

		for (int i=1; i < size; i++)
		{
			if (array[i] == array[i+1])
				modeCount++;

			else
			{
				if (modeCount > maxCount)
				{
				    mode.nMode++;
				    maxCount = modeCount;
				}
				    modeCount = 0;
			}
		}
		mode.mode = new int[mode.nMode];
		for(int count = 0; count < mode.nMode; count++)
			mode.mode[count] = currentMode;

		printStat(mode);

		delete [] array;
		delete [] mode.mode;
}

void problem4()
{
	char num[4];
	int digit[4];

	cout << "Encrypting the data!\n";
	cout << "Enter 4-digit numbers(0-7): ";

	for(int i= 0; i<4; i++)
	{
		cin >> num[i];
	}

	for(int i= 0; i<4; i++)
	{
		digit[i] = num[i] - 48;
	}

	//Encrypting the sequence
	for(int i= 0; i<4; i++)
	{
		if(digit[i] == 8 || digit[i] == 9)
			digit[i] %= 8;
	}
	for(int i = 0;i<4; i++)
		digit[i] += 5;
	for(int i = 0;i<4; i++)
	{
		if(digit[i] > 7)
			digit[i] %= 8;
	}
	int temp;
	temp = digit[0];
	digit[0] = digit[1];
	digit[1] = temp;

	temp = digit[2];
	digit[2] = digit[3];
	digit[3] = temp;
	//Finished encrypting

	cout << "The encrypted sequence is : ";
	for(int i= 0; i<4; i++)
		cout << digit[i];
	cout << endl;

	cout << "\nDecrypting the data!\n";
	cout << "Enter 4-digit numbers(0-7): ";

	for(int i= 0; i<4; i++)
	{
		cin >> num[i];
	}
	for(int i= 0; i<4; i++)
	{
		digit[i] = num[i] - 48;
	}
	//Decrypting the data
	for(int i=0; i<4; i++)
		digit[i] = (digit[i]+3)%8;
	temp = digit[0];
	digit[0] = digit[1];
	digit[1] = temp;

	temp = digit[2];
	digit[2] = digit[3];
	digit[3] = temp;
	cout << "The decrypted sequence is : ";
	for(int i= 0; i<4; i++)
		cout << digit[i];
	cout << endl;
}
void problem5()
{
	cout << "a. \nThe factorial of 1 is 1\n";
	cout << "\nb. \n";
	cout << "short                  : The factorial of 15 is 22528\n";
	cout << "short int              : The factorial of 15 is 22528\n";
	cout << "signed short           : The factorial of 15 is 22528\n";
	cout << "signed short int       : The factorial of 15 is 22528\n";
	cout << "unsigned short         : The factorial of 17 is 32768\n";
	cout << "unsigned short int     : The factorial of 17 is 32768\n";
	cout << endl;
	cout << "int                    : The factorial of 31 is 738197504\n";
	cout << "signed                 : The factorial of 31 is 738197504\n";
	cout << "signed int             : The factorial of 31 is 738197504\n";
	cout << "unsigned               : The factorial of 33 is 2147483648\n";
	cout << "usigned int            : The factorial of 33 is 2147483648\n";
	cout << endl;
	cout << "long                   : The factorial of 31 is 738197504\n";
	cout << "long int               : The factorial of 31 is 738197504\n";
	cout << "signed long            : The factorial of 31 is 738197504\n";
	cout << "signed long int        : The factorial of 31 is 738197504\n";
	cout << "unsigned long          : The factorial of 33 is 2147483648\n";
	cout << "unsigned long int      : The factorial of 33 is 2147483648\n";
	cout << endl;
	cout << "long long              : The factorial of 63 is 1585267068834414592\n";
	cout << "long long int          : The factorial of 63 is 1585267068834414592\n";
	cout << "signed long long       : The factorial of 63 is 1585267068834414592\n";
	cout << "signed long long int   : The factorial of 63 is 1585267068834414592\n";
	cout << "unsigned long long     : The factorial of 65 is 9223372036854775808\n";
	cout << "unsigned long long int : The factorial of 65 is 9223372036854775808\n";
	cout << endl;
	cout << "float   				: The factorial of 9 is 362880\n";
	cout << "double                 : The factorial of 9 is 362880\n";
	cout << "long double            : None(Giving -4.32779e+273, -0, etc. numbers)\n";
}

void sortArray(int arr[], int size)
{
	int startScan, minIndex, minValue;
		for(startScan = 0; startScan <(size-1); startScan++)
		{
					minIndex = startScan;
					minValue = arr[startScan];
	for(int index = startScan + 1; index < size; index++)
		{
			if (arr[index] < minValue)
			{
					minValue = arr[index];
					minIndex = index;
			}
		}
			arr[minIndex] = arr[startScan];
			arr[startScan] = minValue;
		}
}

void printStat(statsResult mode)
{
	cout << "\nMedian of the array: " << mode.median;
	cout << "\nMax Frequency : " << mode.maxFreq+1;
	cout << "\nNumber of modes: " << mode.nMode;
	cout << "\nMode array: { ";
	for(int i =0;i <mode.nMode;i++)
		cout << mode.mode[i] << " ";
	cout << "}";
	cout << fixed << setprecision(2);
	cout << "\nAverage of the array: " << mode.Avg;
}
