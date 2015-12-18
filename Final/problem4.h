/*
 * problem4.h
 *
 *  Created on: Dec 16, 2015
 *      Author: AnhLe
 */

#ifndef PROBLEM4_H_
#define PROBLEM4_H_

#include "myheader.h"

//Class declaration
class SavingsAccount
{
public:
	SavingsAccount(float);               //Constructor
	void  Transaction(float);            //Procedure
	float Total(float=0,int=0);	         //Savings Procedure
	float TotalRecursive(float=0,int=0);
	void  toString();                    //Output Properties
	~SavingsAccount();
private:
	float Withdraw(float);               //Utility Procedure
	float Deposit(float);                //Utility Procedure
	float Balance;                       //Property
	int   FreqWithDraw;                  //Property
	int   FreqDeposit;                   //Property
};

#endif /* PROBLEM4_H_ */
