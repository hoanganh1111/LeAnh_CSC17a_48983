/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 9, 2015, 12:00 PM
 * Purpose: Soda machine simulator
 */

//System Libraries
#include <iostream> 				//Input/Output stream Library
#include <iomanip>  				//Format Library
#include <string.h>					//String Library
using namespace std;				//Utilize standard name-space directly

//Declaring struture
struct sodaMachine
   {
	string name;
	float cost;
	int quantity;
   };

int main()
{
	const int size = 5;				//const size of the array

	//Inizialize The array struct
		sodaMachine soda[size] = {
									{"Cola",       .75, 20},
									{"Root Beer",  .75, 20},
									{"Lemon Lime", .75, 20},
									{"Grape Soda", .80, 20},
									{"Cream Soda", .80, 20}
								 };

	//Declaring variables
	int choice;				//INPUT soda choice
	float money;			//INPUT the amount of money
	float change;			//OUTPUT change
	float total = 0;		//OUTPUT total the money the machine made

	//Prompt for inputing soda choice
menuDisplay:
{
	cout << "\nEnter the soda according to the number: " << endl;
	cout << "1-Cola" 		<< endl;
	cout << "2-Root Beer" 	<< endl;
	cout << "3-Lemon Lime" 	<< endl;
	cout << "4-Grape Soda" 	<< endl;
	cout << "5-Cream Soda" 	<< endl;
	cout << "6-Quit"        << endl;

	cin >> choice;
	cin.ignore();
}
	while(choice != 6)
	{
		cout << fixed << setprecision(2);
		cout << soda[choice-1].name << endl;
		cout << "Cost: " << "$" << soda[choice-1].cost;
		cout << endl;

		//Input soda choice
		cout << "Input your money: \n";
		cin >> money;
		cin.ignore();

		//Asking for money or not
		if(money > soda[choice-1].cost)
			{
				soda[choice-1].quantity -= 1;
				change = money - soda[choice-1].cost;
				//goto menuDisplay;
				//Accumulating the total
				total += (money - change);
			}
		else
			cout << "\nYou need " << (soda[choice-1].cost - money) << " dollars more";


			//Cout change back
			cout << "\nYour change back: $" << change << endl;
			goto menuDisplay;
		}
			//cout the amount of money the machine just made after
			cout << "\nThe machine made $" << total;

		return 0;
}
