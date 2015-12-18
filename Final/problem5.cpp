/*
 * problem5.cpp
 *
 *  Created on: Dec 16, 2015
 *      Author: AnhLe
 */
#include "problem5.h"

Employee::Employee(char a[],char b[],float c)
{
    int Namesize = 20;

    for(int i=0;i < Namesize; i++)
        MyName[i]=a[i];

    for(int i=0;i<Namesize;i++)
        JobTitle[i]=b[i];

    HourlyRate = c;
    HoursWorked=0;
    GrossPay = 0;
    NetPay = 0;
}

float Employee::CalculatePay(float a,int b)
{
    return (getGrossPay(setHourlyRate(a), setHoursWorked(b)));
}

float Employee::getGrossPay(float a,int b)
{
    if(b <= 40)
    {
        GrossPay = (b*a);
        return GrossPay;
    }
    if(b > 40 && b < 50)
    {
        b = b-40;
        GrossPay += (b*(a*1.5));
        return GrossPay;
    }
    if(b >= 50)
    {
        GrossPay = (40*a);
        GrossPay += (10*(a*1.5));
        b = b-50;
        GrossPay += (b*(a*2));
        return GrossPay;
    }
    else
    {
        cout<<"Error!";
        return GrossPay;
    }
}

float Employee::getNetPay(float a)
{
    if(a<=0)
    	NetPay = 0;

    else
    	NetPay = getGrossPay(a, HoursWorked)- Tax(GrossPay);

    return NetPay;
}

void Employee::toString()
{
    cout<< "Name = "<< MyName <<"  Job Title = " << JobTitle
        << "\n Hourly Rate = " << HourlyRate << " Hours Worked = "
        << HoursWorked << " Gross Pay = " << GrossPay <<" Net Pay = "
        << getNetPay(HourlyRate) << endl;
}

int Employee::setHoursWorked(int a){
    if(a > 0 && a <= 84)
    	HoursWorked = a;

    else if(a <= 0)
    {
    	cout << "incorrect hours!\n";
    	HoursWorked = 0;
    }
    return HoursWorked;
}

float Employee::setHourlyRate(float a)
{
    if(a > 0 || a <= 200.00)
    	HourlyRate = a;

    else if (a <= 0)
    {
    	cout << "incorrect pay rate!\n";
    	HourlyRate = 0;
    }
    return HourlyRate;
}

double Employee::Tax(float a)
{
    if(a <= 500 && a > 0)
        return (a*.1);

    else if(a <= 1000 && a > 500)
        return (a*.15);

    else if(a <= 1500 && a > 1000)
        return (a*.2);

    else if(a <= 2000 && a > 1500)
        return (a*.225);

    else if(a <= 3000 && a > 2000)
        return (a*.24545454545);

    else if(a > 3000)
        return (a*.26);

    else
        return (a*0);
}
