/*
 * main.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: AnhLe
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

//Structures declares

//Function prototypes

//Class declaration
class Employee
{
private:
	string name;
	int idNumber;
	string department;
	string position;
public:
	Employee()
	{
		name = " ";
		idNumber = 0;
		department = " ";
		position = " ";
	}
	Employee(string newName, int newID, string newDepart, string newPos)
	{
		name = newName;
		idNumber = newID;
		department = newDepart;
		position = newPos;
	}

	string getName()
	{
		return name;
	}
	int getID()
	{
		return idNumber;
	}
	string getDepart()
	{
		return department;
	}
	string getPos()
	{
		return position;
	}

};

int main(int argc, char** argv)
{
	string name;			//name of the employee
	int idNumber;			//Id numbers
	string position;		//Their position
	string department;		//Their department

	//Prompt and input 1st employee's information
	cout << "-1st Employee-\n";
	cout << "Enter employee's name: ";
	getline(cin, name);

	cout << "Enter employee's ID number: ";
	cin >> idNumber;
	cin.ignore();

	cout << "Enter employee's department: ";
	getline(cin, department);

	cout << "Enter employee's position: ";
	getline(cin, position);

	//Setting the data into the class
	Employee first(name, idNumber, department, position);

	//Prompt and input 2nd employee's information
	cout << "\n-2nd Employee-";
	cout << "\nEnter employee's name: ";
	getline(cin, name);

	cout << "Enter employee's ID number: ";
	cin >> idNumber;
	cin.ignore();

	cout << "Enter employee's department: ";
	getline(cin, department);

	cout << "Enter employee's position: ";
	getline(cin, position);

	//Setting the information into the class
	Employee second(name, idNumber, department, position);

	//Prompt and input 3rd employee's information
	cout << "\n-3rd Employee-";
	cout << "\nEnter employee's name: ";
	getline(cin, name);

	cout << "Enter employee's ID number: ";
	cin >> idNumber;
	cin.ignore();

	cout << "Enter employee's department: ";
	getline(cin, department);

	cout << "Enter employee's position: ";
	getline(cin, position);

	//Setting the information into the class
	Employee third(name, idNumber, department, position);

	//Output the table that contain all 3 employee's
	cout << endl;
	cout <<"_______________________________________________________" << endl;
	cout << "Name             " << "    ID Number   " << "  Department      " << "          Position" << endl;
	cout <<"-------------------------------------------------------" << endl;
	cout << first.getName()  << "         " << first.getID() << "         " << first.getDepart() << "         " << first.getPos() << endl;
	cout << second.getName() << "           " << second.getID()<< "         " << second.getDepart()<< "                  " << second.getPos()<< endl;
	cout << third.getName()  << "           " << third.getID() << "         " << third.getDepart() << "        " << third.getPos() << endl;

	return 0;				//End code
}
