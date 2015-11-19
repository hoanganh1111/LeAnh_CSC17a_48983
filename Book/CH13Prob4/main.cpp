/*

 * File:   main.cpp
 * Author: Anh Le
 * Created on November 18, 2015, 18:40 PM
 * Purpose: Using class to holds data about personal s'informations
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

//Class Declaration
class personalData
{
	private:
		string name;
		string address;
		int age;
		string phoneNum;
	public:
		void setName(string);
		void setAddress(string);
		void setAge(int);
		void setPhoneNum(string);
		string getName() const;
		string getAddress() const;
		int getAge() const;
		string getPhoneNum() const;
};

void personalData::setName(string input)
{
	name = input;
}

void personalData::setAddress(string input)
{
	address = input;
}

void personalData::setAge(int num)
{
	age = num;
}

void personalData::setPhoneNum(string num)
{
	phoneNum = num;
}

string personalData::getName() const
{
	return name;
}

string personalData::getAddress() const
{
	return address;
}

int personalData::getAge() const
{
	return age;
}

string personalData::getPhoneNum() const
{
	return phoneNum;
}

int main(int argc, char** argv)
{
	//Declare objects and variables
	personalData prsnOne;		// Object that holds data for the first person
	personalData prsnTwo;		// Object that holds data for the second person
	personalData prsnThree;		// Object that holds data for the third person
	string prsnName;			// Holds the input name
	string prsnAddress;			// Holds the input address
	int prsnAge;				// Holds the input age
	string prsnNum;				// Holds the input phone number

	//Read in data for person one
	cout << "Enter your name: ";
	getline(cin, prsnName);
	cout << "Enter your address: ";
	getline(cin, prsnAddress);
	cout << "Enter your age: ";
	cin >> prsnAge;
	cin.ignore(100, '\n');
	cout << "Enter your phone number: ";
	getline(cin, prsnNum);
	//Store data for person one
	prsnOne.setName(prsnName);
	prsnOne.setAddress(prsnAddress);
	prsnOne.setAge(prsnAge);
	prsnOne.setPhoneNum(prsnNum);

	//Read in data for person two
	cout << "Enter a friend's or family member's name: ";
	getline(cin, prsnName);
	cout << "Enter a friend's or family member's address: ";
	getline(cin, prsnAddress);
	cout << "Enter a friend's or family member's age: ";
	cin >> prsnAge;
	cin.ignore(100, '\n');
	cout << "Enter a friend's or family member's phone number: ";
	getline(cin, prsnNum);
	//Store data for person two
	prsnTwo.setName(prsnName);
	prsnTwo.setAddress(prsnAddress);
	prsnTwo.setAge(prsnAge);
	prsnTwo.setPhoneNum(prsnNum);

	//Read in data for person three
	cout << "Enter a friend's or family member's name: ";
	getline(cin, prsnName);
	cout << "Enter a friend's or family member's address: ";
	getline(cin, prsnAddress);
	cout << "Enter a friend's or family member's age: ";
	cin >> prsnAge;
	cin.ignore(100, '\n');
	cout << "Enter a friend's or family member's phone number: ";
	getline(cin, prsnNum);
	cout << endl;
	//Store data for person three
	prsnThree.setName(prsnName);
	prsnThree.setAddress(prsnAddress);
	prsnThree.setAge(prsnAge);
	prsnThree.setPhoneNum(prsnNum);

	//Output all the data
	cout << "Person One:" << endl;
	cout << "\tName: " << prsnOne.getName() << endl;
	cout << "\tAddress: " << prsnOne.getAddress() << endl;
	cout << "\tAge: " << prsnOne.getAge() << endl;
	cout << "\tPhone number: " << prsnOne.getPhoneNum() << endl;
	cout << "Person Two:" << endl;
	cout << "\tName: " << prsnTwo.getName() << endl;
	cout << "\tAddress: " << prsnTwo.getAddress() << endl;
	cout << "\tAge: " << prsnTwo.getAge() << endl;
	cout << "\tPhone number: " << prsnTwo.getPhoneNum() << endl;
	cout << "Person Three:" << endl;
	cout << "\tName: " << prsnThree.getName() << endl;
	cout << "\tAddress: " << prsnThree.getAddress() << endl;
	cout << "\tAge: " << prsnThree.getAge() << endl;
	cout << "\tPhone number: " << prsnThree.getPhoneNum() << endl;

	return 0;						//End code
}
