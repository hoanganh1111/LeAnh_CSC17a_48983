/*

 * File:   main.cpp
 * Author: Anh Le
 * Created on November 18, 2015, 7:30 PM
 * Purpose: Using class to holds data about items
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


//Class declaration
class Inventory
{
private:
	int itemNumber;				//Item's description
	int quantity;				//Item's quantities
	float cost;					//Item price
	float totalCost;
public:
	//Set all members variables to 0
	Inventory()
	{
		itemNumber = 0;
		quantity = 0;
		cost = 0;
		totalCost = 0;
	}
	//Constructor #2 copy values to members variables
	Inventory(int newItem, int newQuantity, float newCost)
	{
		itemNumber = newItem;
		quantity = newQuantity;
		cost = newCost;
		setTotalCost(quantity, cost);
	}

	//Setting item's information
	void setItem(int newItem)
	{
		itemNumber = newItem;
	}
	void setQuantity(int newQuan)
	{
		quantity = newQuan;
	}
	void setCost(float newCost)
	{
		cost = newCost;
	}
	void setTotalCost(int, float)
	{
		totalCost = quantity * cost;
	}

	//Getting item's information
	int getItemNumber()
	{
		return itemNumber;		//Return the description
	}
	int getQuantity()
	{
		return quantity;		//Return the quantity
	}
	float getCost()
	{
		return cost;			//Return price
	}
	float getTotalCost()
	{
		return totalCost;		//REturn total Cost
	}
};


int main(int argc, char** argv)
{
	int itemNumber;				//Item's description
	int quantity;				//Item's quantity
	float cost;					//Item's price
	float totalCost;

	//Inputing first item's information
	cout << "Enter the item's number: ";	 	//Prompt for user's input
	cin >>	itemNumber;							//Input the description
	cin.ignore();
	while (itemNumber < 0)						//Validating input item only
	{											//accepting positive number
		cout << "Invalid! Please re-enter: ";
		cin >> itemNumber;
	}

	cout << "Enter the item's quantity: ";		//Prompt for user's input
	cin >> quantity;							//Input quantities
	cin.ignore();
	while (quantity < 0)						//Validating input quantity only
	{											//accepting positive number
		cout << "Invalid! Please re-enter: ";
		cin >> quantity;
	}

	cout << "Enter the item's cost: ";			//Prompt for user's input
	cin >> cost;								//Input the cost
	cin.ignore();
	while (itemNumber < 0)						//Validating input cost only
	{											//accepting positive number
		cout << "Invalid! Please re-enter: ";
		cin >> cost;
	}

	//Setting the information into the first class
	Inventory information(itemNumber, quantity, cost);

	totalCost  = information.getTotalCost();		//Getting total cost
	itemNumber = information.getItemNumber();		//Return the description
	quantity   = information.getQuantity();			//Return the quantity
	cost       = information.getCost();				//Return the price

	//Output the item number, quantity, cost and the total cost
	cout << "\nItem Number : " << itemNumber;
	cout << "\nQuantity    : " << quantity;
	cout << fixed << setprecision(2);
	cout << "\nCost        : $" << cost;
	cout << "\nTotal cost  : $" << totalCost;

	return 0;										//End code
}
