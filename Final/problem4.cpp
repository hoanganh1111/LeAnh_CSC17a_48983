/*
 * problem4.cpp
 *
 *  Created on: Dec 16, 2015
 *      Author: AnhLe
 */
#include "problem4.h"

SavingsAccount::SavingsAccount(float balance)
{
    if(balance>0)
    	Balance = balance;
    else
    	Balance=0;

    FreqWithDraw = 0;
    FreqDeposit = 0;
}

SavingsAccount::~SavingsAccount()
{
    Balance = 0;
    FreqWithDraw = 0;
    FreqDeposit = 0;
}

void SavingsAccount::Transaction(float trans)
{
    if(trans>0)
    {
    	FreqDeposit++;
    	Balance+=trans;
    }
    else if(trans == 0)
    	Balance -= 0.00;
    else
    {
        if(Balance > trans)
        {
            FreqWithDraw++;
            Balance-=trans;
        }
        else
            cout<<"Withdraw not Allowed! You exceeds your current balance!\n";
    }
}

float SavingsAccount::Total(float savint,int time)
{
    float total = Balance;
    float total2 = (1+savint);

    for(int i=1;i<time;i++)
        total2*=(1+savint);

    total*=total2;

    return total;
}

float SavingsAccount::TotalRecursive(float savint,int time)
{
    float total=Balance;
    float total2=(1+savint);

    for(int i=1;i<time;i++)
        total2*=(1+savint);

    total*=total2;
    return total;
}

void SavingsAccount::toString()
{
    cout<<"Your current balance is: $"<<Balance
        <<"\nYou have "<<FreqWithDraw<<" withdraws.\n"
        <<"You have "<<FreqDeposit<<" deposits.\n";
}
