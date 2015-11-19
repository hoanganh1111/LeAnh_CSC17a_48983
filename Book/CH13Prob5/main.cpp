/*

 * File:   main.cpp
 * Author: Anh Le
 * Created on November 18, 2015, 10:30 AM
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
class RetailItem
{
private:
	string description;				//Item's description
	int quantity;					//Item's quantities
	float price;					//Item price
public:
	//Parameter constructor
	RetailItem(string newDescription, int newQuantity, float newPrice)
	{
		description = newDescription;
		quantity = newQuantity;
		price = newPrice;
	}

	//Setting item's information
//	void setItem(string item)
//	{
//		description = item;
//	}
//	void setQuan(int number)
//	{
//		quantity = number;
//	}
//	void setPrice(float cost)
//	{
//		price = cost;
//	}

	//Getting item's information
	string getDesc()
	{
		return description;		//Return the description
	}
	int getQuan()
	{
		return quantity;		//Return the quantity
	}
	float getPrice()
	{
		return price;			//Return price
	}
};


int main(int argc, char** argv)
{
	string description;				//Item's description
	int quantity;					//Item's quantity
	float price;					//Item's price

	//Inputing first item's information
	cout << "Enter the item's description: ";	//Prompt for user's input
	getline(cin, description);					//Input the description

	cout << "Enter the item's quantity: ";
	cin >> quantity;							//Input quantities
	cin.ignore();

	cout << "Enter the item's price: ";
	cin >> price;								//Input the price
	cin.ignore();

	//Setting the information into the first class
	RetailItem information1(description, quantity, price);

	description = information1.getDesc();		//Return the description
	quantity = information1.getQuan();			//Return the quantity
	price = information1.getPrice();			//Return the price

	//Output the first item's informations
	cout << "\n-Item #1-";
	cout << "\nDescription: " << description << endl;
	cout << "Quantity   : " << quantity << endl;
	cout << "Price      : " << price << endl;

	//Inputing second item's information
	cout << "\nEnter the item's description: ";	//Prompt for user's input
	getline(cin, description);					//Input the description

	cout << "Enter the item's quantity: ";
	cin >> quantity;							//Input quantities
	cin.ignore();

	cout << "Enter the item's price: ";			//Input the price
	cin >> price;
	cin.ignore();

	//Setting the information into the second class
	RetailItem information2(description, quantity, price);

	description = information2.getDesc();		//Return the description
	quantity = information2.getQuan();			//Return the quantity
	price = information2.getPrice();			//Return the price

	//Output the second item's informations
	cout << "\n-Item #2-";
	cout << "\nDescription: " << description << endl;
	cout << "Quantity   : " << quantity << endl;
	cout << "Price      : " << price << endl;

	//Inputing third item's information
	cout << "\nEnter the item's description: ";	//Prompt for user's input
	getline(cin, description);					//Input the description

	cout << "Enter the item's quantity: ";
	cin >> quantity;							//Input quantities
	cin.ignore();

	cout << "Enter the item's price: ";
	cin >> price;								//Input the price
	cin.ignore();

	//Setting the information into the third class
	RetailItem information3(description, quantity, price);

	description = information3.getDesc();		//Return the description
	quantity = information3.getQuan();			//Return the quantity
	price = information3.getPrice();			//Return the price

	//Output the third item's informations
	cout << "\n-Item #3-\n";
	cout << "Description: " << description << endl;
	cout << "Quantity   : " << quantity << endl;
	cout << "Price      : " << price << endl;

	return 0;									//End code
}
