/*
 * File: main.cpp
 * Created on: October 5, 2015
 * Author: Anh Le
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct CompanyData
	{
		string dvsnName;
		int qrtrOne, qrtrTwo, qrtrThree, qrtrFour;
	};

void writeToFile(CompanyData, CompanyData, CompanyData, CompanyData);

int main()
{
// Declare variables
	CompanyData north, south, east, west;

// Read in user input
	// North
	cout << "Enter the division name: ";
	cin >> north.dvsnName;
	cout << "Enter quarter 1 sales amount: ";
	cin >> north.qrtrOne;
	cout << "Enter quarter 2 sales amount: ";
	cin >> north.qrtrTwo;
	cout << "Enter quarter 3 sales amount: ";
	cin >> north.qrtrThree;
	cout << "Enter quarter 4 sales amount: ";
	cin >> north.qrtrFour;

	// South
	cout << "Enter the division name: ";
	cin >> south.dvsnName;
	cout << "Enter quarter 1 sales amount: ";
	cin >> south.qrtrOne;
	cout << "Enter quarter 2 sales amount: ";
	cin >> south.qrtrTwo;
	cout << "Enter quarter 3 sales amount: ";
	cin >> south.qrtrThree;
	cout << "Enter quarter 4 sales amount: ";
	cin >> south.qrtrFour;

	// West
	cout << "Enter the division name: ";
	cin >> west.dvsnName;
	cout << "Enter quarter 1 sales amount: ";
	cin >> west.qrtrOne;
	cout << "Enter quarter 2 sales amount: ";
	cin >> west.qrtrTwo;
	cout << "Enter quarter 3 sales amount: ";
	cin >> west.qrtrThree;
	cout << "Enter quarter 4 sales amount: ";
	cin >> west.qrtrFour;

	// East
	cout << "Enter the division name: ";
	cin >> east.dvsnName;
	cout << "Enter quarter 1 sales amount: ";
	cin >> east.qrtrOne;
	cout << "Enter quarter 2 sales amount: ";
	cin >> east.qrtrTwo;
	cout << "Enter quarter 3 sales amount: ";
	cin >> east.qrtrThree;
	cout << "Enter quarter 4 sales amount: ";
	cin >> east.qrtrFour;

// Output results to file
	writeToFile(north, south, east, west);
	return 0;
}

void writeToFile(CompanyData North, CompanyData South, CompanyData East, CompanyData West)
{
	ofstream outFile;
	outFile.open("myFile.txt");
	outFile << North.dvsnName << setw(35) << South.dvsnName << setw(28) << East.dvsnName
			<< setw(30) << West.dvsnName << endl;

	outFile << "Quarter 1 sales: " << North.qrtrOne << setw(25) << "Quarter 1 sales: " << South.qrtrOne << setw(25)
			<< "Quarter 1 sales: " << West.qrtrOne  << setw(25) << "Quarter 1 sales: " << East.qrtrOne << endl;

	outFile << "Quarter 2 sales: " << North.qrtrTwo << setw(25) << "Quarter 2 sales: " << South.qrtrTwo << setw(25)
			<< "Quarter 2 sales: " << West.qrtrTwo  << setw(25) << "Quarter 2 sales: " << East.qrtrTwo << endl;

	outFile << "Quarter 3 sales: " << North.qrtrThree << setw(25) << "Quarter 3 sales: " << South.qrtrThree<< setw(25)
			<< "Quarter 3 sales: " << West.qrtrThree  << setw(25) << "Quarter 3 sales: " << East.qrtrThree<< endl;

	outFile << "Quarter 4 sales: " << North.qrtrFour << setw(25) << "Quarter 4 sales: " << South.qrtrFour<< setw(25)
			<< "Quarter 4 sales: " << West.qrtrFour  << setw(25) << "Quarter 4 sales: " << East.qrtrFour<< endl;
}
