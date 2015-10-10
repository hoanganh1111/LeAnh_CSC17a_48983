/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 7, 2015, 05:30 PM
 * Purpose: Buereu's Speakers
 */

//System Libraries
#include <iostream> 		//Input/Output stream Library
#include <iomanip>  		//Format Library
#include <string.h>			//String Library
using namespace std;		//Utilize standard name-space directly

//Structure declaration
struct speaker
{
	string name;			//Name of the speaker
	int phone;				//Phone number
	string topic;			//The speaker's topic
	float fee;				//Speaker's fee required
};

//Function prototypes
void menuDisplay();
void inputInforms(speaker**, int);
void changeInforms(speaker**, int);
void outputInforms(speaker*, int);
void outputAll(speaker *, int);

int main(int argc, char** argv)
{
	//Declaring variables
	int size;											//Numbers of speakers
	char selection;										//Selection of menu

	//Prompt for user's input of how many speakers
	cout << "How many speakers are you reserving: ";
	cin >> size;										//INPUT the number of speakers
	cout << endl;
	cin.ignore();

	//Dynamic allocate the structure speaker
	speaker *ptr = new speaker[size];

	//goto userInput
userInput:
{
	menuDisplay();										//Calling menuDisplay function

	cout << "Enter a selection menu: ";					//Prompt for selection menu choice
	cin >> selection;									//INPUT selection of menu
	cin.ignore();
}

	while(selection != 'E' || selection != 'e')			//While choice of selection is not e or E
	{
		if(selection == 'a' || selection == 'A')		//If selection is A or a
			{
				inputInforms(&ptr, size);				//Calling inputInforms function
				goto userInput;							//Back to menuDisplay and input selection
			}
		else if(selection == 'b' || selection == 'B')	//If selection is B or b
			{
				changeInforms(&ptr, size);				//Calling changeInforms function
				goto userInput;							//Back to menuDisplay and input selection
			}
		else if(selection == 'c' || selection == 'C')	//If selection is C or c
			{
				outputInforms(ptr, size);				//Calling outputInforms function
				goto userInput;							//Back to menuDisplay and input selection
			}
		else if(selection == 'd' || selection == 'D')	//If selection is D or d
			{
				outputAll(ptr, size);					//Calling outputAll function
				goto userInput;							//Back to menuDisplay and input selection
			}
		else											//If selection is anything else
			{
				cout << "Invalid selection, please"
						" re-enter the selection: \n";	//OUTPUT invalid selection
				goto userInput;							//Back to menuDisplay and input selection
			}
	}

	delete ptr;
	return 0;
}

//Initialize function menuDisplay
void menuDisplay()
{
	//OUTPUT menu
	cout << "A. Enter a speaker's informations.\n";
	cout << "B. Change informations of a speaker.\n";
	cout << "C. Outputting informations of a speaker.\n";
	cout << "D. Outputting informations of all speaker.\n";
	cout << "E. Exit\n";
}

//Initializing function inputInforms
void inputInforms(speaker **ptr, int size)
{
	//Declaring variables
	int speakerI;				//The speaker's in the structure array

	//Prompt for asking which speaker
	cout << "Enter the speakers you want to input(1 - " << size << "): ";
	cin >> speakerI;			//INPUT the speaker number
	cin.ignore();

	//If the input is right which < number of speakers
	if(speakerI <= size && speakerI >= 0)
		{
			cout << "Enter the speaker's name: \n";			//Asking for entering speaker's name
			getline(cin, (ptr[speakerI-1])->name);			//Get line of the speaker's name

			cout << "Enter the speaker's phone number: \n";	//Asking for entering speaker's phone number
			cin >> (ptr[speakerI-1])->phone;				//Input the speaker's phone number
			cin.ignore();

			cout << "Enter the speaker's topic: \n";		//Asking for entering speaker's topic
			getline(cin, (ptr[speakerI-1])->topic);			//Get line of the speaker's name

			cout << "Enter the speaker's fee required: \n";	//Asking for speaker's fee required
			cin >> (ptr[speakerI-1])->fee;					//Input the speaker's fee required
			cin.ignore();
		}
}

//Initialize function changeInforms
void changeInforms(speaker **ptr, int size)
{
	//Declaring variables
	int speakerC;				//The speaker's in the structure array
	int select;					//Selection of menu

	//Prompt for asking which speaker
	cout << "Enter the speakers you want to change(1 - " << size << "): ";
	cin >> speakerC;			//Input the speake's position
	cin.ignore();

	//If the input is right which < number of speakers
	if(speakerC <= size && speakerC >= 0)
	{
		//OUTPUT the menu
		cout << "1. Change the speaker's name.\n";
		cout << "2. Change the speaker's phone number.\n";
		cout << "3. Change the speaker's topic.\n";
		cout << "4. Change the speaker's fee required.\n";
		cout << "5. Nothing's changed.\n";
		cin >> select;
		cin.ignore();
		switch(select)
		{
			case 1:												//Change the speaker's name
			{
				cout << "Enter the speaker's name: \n";			//Asking for speaker's name
				getline(cin, (ptr[speakerC-1])->name);			//Get line speaker's name
				break;											//Break out of the loop
			}
			case 2:												//Change the speaker's phone number
			{
				cout << "Enter the speaker's phone number: \n";	//Asking for speaker's phone number
				cin >> (ptr[speakerC-1])->phone;				//Input the speaker's phone number
				cin.ignore();
				break;											//Break out of the loop
			}
			case 3:												//Change the speaker's topic
			{
				cout << "Enter the speaker's topic: \n";		//Asking for speaker's topic
				getline(cin, (ptr[speakerC-1])->topic);			//Get line speaker's topic
				break;											//Break out of the loop
			}
			case 4:												//Change the speaker's fee required
			{
				cout << "Enter the speaker's fee required: \n";	//Asking for speaker's fee required
				cin >> (ptr[speakerC-1])->fee;					//Input the speaker's fee required
				cin.ignore();
				break;											//Break out of the loop
			}
			default:											//Invalid selection of menu
			{
				cout << "Invalid selection, please re-enter: \n";
				cin >> select;									//Input the selection again
				cin.ignore();
				break;											//Break out of the loop
			}
		}
	}
}

void outputInforms(speaker *ptr, int size)
{
	int speakerO;
	cout << "Enter the speakers you want to output(1 - " << size << "): ";
	cin >> speakerO;
	cin.ignore();
	if(speakerO <= size && speakerO >= 0)
	{
		cout << "Name : " << ptr[speakerO-1].name  << endl;
		cout << "Phone: " << ptr[speakerO-1].phone << endl;
		cout << "Topic: " << ptr[speakerO-1].topic << endl;
		cout << "Fee  : " << ptr[speakerO-1].fee   << endl;
		cout << endl;
	}
}

void outputAll(speaker *ptr, int size)
{
	for(int count = 0; count < size; count++)
	{
		cout << "Name : " << ptr[count].name  << endl;
		cout << "Phone: " << ptr[count].phone << endl;
		cout << "Topic: " << ptr[count].topic << endl;
		cout << "Fee  : " << ptr[count].fee   << endl;
		cout << endl;
	}
}
