/*
 * File:   main.cpp
 * Author: Anh Le
 * Created on October 9, 2015, 9:30 AM
 * Purpose: Display movie data modified
 */

//System Libraries
#include <iostream> 			//Input/Output stream Library
#include <iomanip>  			//Format Library
#include <string.h>				//String Library
using namespace std;			//Utilize standard name-space directly

//Structure movieData
struct movieData
   {
	string title;       		 //movie's title
	string director;		     //movie's director
	string year;				 //movie's year released
	int runTime; 				 //movie's running time
	int production;				 //movie's budget
	int reve;					 //movie's gross
   };

 //Function prototyped
 void inmovieData(movieData&);
 void outmovieData(movieData);

 int main()
 {

	movieData first;			//first movie input
	movieData second;			//second movie input

	inmovieData(first);			//INPUT first movie
	inmovieData(second);		//INPUT second movie

 	//OUTPUT informations in the struct
	cout << endl;
 	cout << setw(5) << "Movie" << setw(21) << "Director"
 		 << setw(15) << "Year" << setw(19) << "RunTime(min)"
 		 << setw(20) << "Budget(millions)" << setw(18)
 		 << "Gross(millions)" << endl;

	outmovieData(first);		//OUTPUT first movie
	outmovieData(second);		//OUTPUT second movie

	return 0;
}

 //Initialized function inmovieData
 void inmovieData(movieData &p)
 {
 	cout << "Enter the movie's title: ";
 	getline(cin, p.title);

 	cout << "\nEnter the movie's director: ";
 	getline(cin, p.director);

 	cout << "\nEnter the movie's year released: ";
 	cin >> p.year;

 	cout << "\nEnter the movie's run time: ";
 	cin >> p.runTime;

 	cout << "\nEnter the movie's production cost: ";
 	cin >> p.production;

 	cout << "\nEnter the movie's first year revenue: ";
 	cin >> p.reve;

 	cin.ignore(265, '\n');
 }

 //Initialized function outmovieData
 void outmovieData(movieData p)
 {
 	cout << setw(5)  << p.title << setw(21) << p.director
 		 << setw(10) << p.year  << setw(10) << p.runTime
 		 << setw(19) << p.production << setw(18) << p.reve << endl;
 }
