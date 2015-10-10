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
	float totalMonthly;			//Monthly total money
	float totalExp;				//Total expenses
	const int size = 11;		//Size of structure
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
		cout << "Enter a budget for each category: " << endl;
		for(int count = 0; count < 10; count++)
			cin >> money[count].newMonthly;
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
