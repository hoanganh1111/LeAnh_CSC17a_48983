/*
 * problem5.h
 *
 *  Created on: Dec 16, 2015
 *      Author: AnhLe
 */

#ifndef PROBLEM5_H_
#define PROBLEM5_H_

#include "myheader.h"

class Employee
{
public:
		Employee(char[],char[],float);  //Constructor
		float  CalculatePay(float,int); //Procedure
		float  getGrossPay(float,int);  //Procedure
		float  getNetPay(float);        //Procedure
		void   toString();              //Procedure
		int    setHoursWorked(int);     //Procedure
		float  setHourlyRate(float);    //Procedure
	private:
		double Tax(float);      //Utility Procedure
		char   MyName[20];      //Property
		char   JobTitle[20];    //Property
		float  HourlyRate;      //Property
		int    HoursWorked;     //Property
		float  GrossPay;        //Property
		float  NetPay;          //Property
};

#endif /* PROBLEM5_H_ */
