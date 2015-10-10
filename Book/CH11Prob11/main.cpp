/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 9, 2015, 12:00 PM
 * Purpose: Display report of student budget
 */

//System Libraries
#include <iostream> 				//Input/Output stream Library
#include <iomanip>  				//Format Library
#include <string.h>					//String Library
using namespace std;				//Utilize standard name-space directly

//Declaring structure
struct Budget
 {
	string name;
	float monthly;
	float newMonthly;
	float change;
 };

	//Function Prototyped
	void InputBudget(Budget money[]);
 	void OutputBudget(Budget money[]);

int main()
{
	//Declare variables
	float totalMonthly = 0.00;			//Monthly total money
	float totalExp = 0.00;				//Total expenses
	const int size = 11;				//Size of structure
	Budget money[size] = {
							{"Housing", 500.00, 0, 0 },
							{"Utilities",150.00, 0, 0 },
							{"Household Expenses", 65.00, 0, 0},
							{"Transportation", 50.00, 0, 0 },
							{"Food", 250.00, 0, 0},
							{"Medical", 30.00, 0, 0 },
							{"Insurance", 100.00, 0, 0 },
							{"Entertainment", 150.00, 0, 0 },
							{"Clothing", 75.00, 0, 0 },
							{"Miscellaneous", 50.00, 0, 0}
						 };

	//Prompt user to enter budgets
	InputBudget(money);
 	OutputBudget(money);

 	for(int count= 0; count < size; count ++)
 	{
 		totalMonthly += money[count].monthly;
 		totalExp 	 += money[count].newMonthly;
 	}

 	cout << endl;

 	if(totalExp > totalMonthly)
		cout << "\nMonthly budget went over: $" << (totalExp - totalMonthly);

 	else
		cout << "\nMonthly budget went under: $" << (totalMonthly - totalExp);


	return 0;
}

	//Define function InputBudget
	void InputBudget(Budget money[])
	{
		cout << " 1.Housing         2.Utilities      3.Household Expenses\n";
		cout << " 4.Transportation  5.Food   	    6.Medical\n";
		cout << " 7.Insurance       8.Entertainment  9.Clothing\n";
		cout << "10.Miscellaneous\n";
		cout << "Enter a budget for each category(1-10): \n";
		for(int count = 0; count < 10; count++)
			cin >> money[count].newMonthly;
			cin.ignore();
	}

	//Define function OutputBudget
	void OutputBudget(Budget money[])
	{
		for(int count = 0; count < 10; count++)
		{
			if(money[count].newMonthly > money[count].monthly)
			{
				money[count].change=money[count].newMonthly - money[count].monthly;
				cout<< "\nMonthly expenses of "<<money[count].name<< " went over: "
					 << "$" <<money[count].change;
			}
			else
			{
				money[count].change = money[count].monthly- money[count].newMonthly;
				cout<< "\nMonthly expenses of "<<money[count].name<< " still have: "
					 << "$" << money[count].change;
			}
		}
	}
