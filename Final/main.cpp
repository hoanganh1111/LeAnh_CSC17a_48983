/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on December 14, 2015, 11:30 AM
 * Purpose: Final
 */

#include "myheader.h"
#include "problem1.h"
#include "problem2.h"
#include "problem3.h"
#include "problem4.h"
#include "problem5.h"

//Prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

int main(int argc, char** argv)
{
	int inN;					//User's input selection

		do
		{
			menuDisplay();			//Display main menu using menuDisplay function
			inN = getN();			//Get user input using getN function

			switch(inN)				//Checking user's input
			{
			case 1:					//Choice is 1
				problem1();			//Run problem 1 function
				break;				//break
			case 2:					//Choice is 2
				problem2();			//Run problem 2 function
				break;				//break
			case 3:					//Choice is 3
				problem3();			//Run problem 3 function
				break;				//break
			case 4:					//Choice is 4
				problem4();			//Run problem 4 function
				break;				//break
			case 5:					//Choice is 5
				problem5();			//Run problem 5 function
				break;				//break
			case 6: 				//run problem 6
				break;
			default:				//Any other input
				def(inN);			//Exit code
				break;
			}
			//While the uer's input is between 1 and 6
		}while(inN >= 1 && inN <= 6);

		//Return 0, exit code
		return 0;
}

void problem1()
{
	char n=5;
	char rndseq[]={16,34,57,79,127};
	int ntimes=100000;

	Prob1Random a(n,rndseq);

	for(int i=1;i<=ntimes;i++)
	{
		a.randFromSet();
	}

	int *x=a.getFreq();
	char *y=a.getSet();
	for(int i=0;i<n;i++)
	{
		cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
	}
	cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

void problem2()
{
	cout<<"The start of Problem 2, the sorting problem"<<endl;
		Prob2Sort<char> rc;
		bool ascending=true;
		ifstream infile;
		infile.open("Problem2.txt",ios::in);
		char *ch2=new char[10*16];
		char *ch2p=ch2;
		while(infile.get(*ch2)){cout<<*ch2;ch2++;}
		infile.close();
		cout<<endl;


		cout<<"Sorting on which column"<<endl;
		int column;
		cin>>column;
		char *zc=rc.sortArray(ch2p,10,16,column,ascending);
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<16;j++)
			{
				cout<<zc[i*16+j];
			}
		}
		delete []zc;
		cout<<endl;
}

void problem3()
{
	cout<<"Entering problem number 3"<<endl;
	int rows=5;
	int cols=6;
	Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
	const int *naugT=tab.getTable();
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<naugT[i*cols+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	const int *augT=tab.getAugTable();
	for(int i=0;i<=rows;i++)
	{
		for(int j=0;j<=cols;j++)
		{
			cout<<augT[i*(cols+1)+j]<<" ";
		}
		cout<<endl;
	}
}

void problem4()
{
	SavingsAccount mine(-300);

		//Set random number seed to time.
		srand(static_cast<unsigned int>(time(0)));

		for(int i=1;i<=10;i++)
		{
			mine.Transaction((float)(rand()%500)*(rand()%3-1));
		}
		mine.toString();
		cout<<"Balance after 7 years given 10% interest = "
				<<mine.Total((float)(0.10),7)<<endl;
		cout<<"Balance after 7 years given 10% interest = "
				<<mine.TotalRecursive((float)(0.10),7)
				<<" Recursive Calculation "<<endl;
}

void problem5()
{
	Employee Mark("Mark","Boss",215.50);
	Mark.setHoursWorked(-3);
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(20.0), Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(40.0),
	Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(60.0), Mark.setHoursWorked(25));
	Mark.toString();

	Employee Mary("Mary","VP",50.0);
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(40));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(50));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(60));
	Mary.toString();
}

void problem6()
{

}
