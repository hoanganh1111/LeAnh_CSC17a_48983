/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 7, 2015, 05:30 PM
 * Purpose: Buereu's Speakers
 */

//System Libraries
#include <iostream> 	//Input/Output stream Library
#include <iomanip>  	//Format Library
#include <string.h>		//String Library
using namespace std;	//Utilize standard name-space directly

//Structure
struct speaker
{
	string name;
	int phone;
	string topic;
	float fee;
};

//Function prototyped
void menuDisplay();
void changeInforms(speaker**, int);
void inputInforms(speaker**, int);
void outputInforms(speaker**, int);
void outputAll(speaker **, int);

int main(int argc, char** argv)
{
	int size;
	char selection;

	cout << "How many speakers are you reserving: ";
	cin >> size;
	cout << endl;
	cin.ignore();

	speaker *ptr = new speaker[size];

	menuDisplay();

	while(selection != 'E' || selection != 'e')
	{
		switch (selection)
		{
			case 'A': case 'a':
			{
				inputInforms(&ptr, size);
				break;
			}
		case 'B': case 'b':
			{
				//changeInforms(speaker, size)
				break;
			}
		case 'C': case 'c':
			{
				//outputInforms(speaker, size)
				break;
			}
		case 'E': case 'e':
			{
				//outputInforms(speaker, size)
				break;
			}
		default:
			{
				cout << "Invalid selection, please re-enter the selection: \n";
				cin >> selection;
				cin.ignore();
				break;
			}
		}
	}

	return 0;
}

void menuDisplay()
{
	cout << "A. Enter a speaker's informations.\n";
	cout << "B. Change informations of a speaker.\n";
	cout << "C. Outputting informations of a speaker.\n";
	cout << "D. Outputting informations of a speaker.\n";
	cout << "E. Exit\n";
}

void inputInforms(speaker **ptr, int size)
{
	int speakerI;
	cout << "Enter the speakers you want to input(1 - " << size << ")";
	cin >> speakerI;
	cin.ignore();
	if(speakerI <= size && speakerI > 0)
		{
			cout << "Enter the speaker's name: \n";
			getline(cin, ptr[speakerI-1].name);

			cout << "Enter the speaker's phone number: \n";
			cin >> ptr[speakerI-1].phone;
			cin.ignore();

			cout << "Enter the speaker's topic: \n";
			getline(cin, ptr[speakerI-1].topic);

			cout << "Enter the speaker's fee required: \n";
			cin >> ptr[*speakerI-1].fee;
			cin.ignore();
		}
}

void changeInforms(speaker **ptr, int size)
{
	int speakerC;
	int select;
	cout << "Enter the speakers you want to change(1 - " << size << ")";
	cin >> speakerC;
	cin.ignore();
	while(speakerC <= size && speakerC >= 0)
	{
		cout << "1. Change the speaker's name.\n";
		cout << "2. Change the speaker's phone number.\n";
		cout << "3. Change the speaker's topic.\n";
		cout << "4. Change the speaker's fee required.\n";
		cin >> select;
		cin.ignore();
		switch(select)
		{
			case 1:
			{
				cout << "Enter the speaker's name: \n";
				getline(cin, ptr[speakerC-1].name);
				break;
			}
			case 2:
			{
				cout << "Enter the speaker's phone number: \n";
				cin >> ptr[speakerC-1].phone;
				cin.ignore();
				break;
			}
			case 3:
			{
				cout << "Enter the speaker's topic: \n";
				getline(cin, ptr[speakerC-1].topic);
				break;
			}
			case 4:
			{
				cout << "Enter the speaker's fee required: \n";
				cin >> ptr[speakerC-1].fee;
				cin.ignore();
				break;
			}
			default:
			{
				cout << "Invalid selection, please re-enter: \n";
				cin >> select;
				cin.ignore();
				break;
			}
		}
	}
}

void outputInforms(speaker **ptr, int size)
{
	int speakerO;
	cout << "Enter the speakers you want to output(1 - " << size << ")";
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

void outputAll(speaker **ptr, int size)
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
