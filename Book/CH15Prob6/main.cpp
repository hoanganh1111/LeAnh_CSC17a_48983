/*
 * main.cpp
 *
 *  Created on: Nov 28, 2015, 9:48 PM
 *  Author: Anh Le
 *  Purpose: Essay
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
class Essay
{
	private:
    	float grammar;
    	float spelling;
    	float correctLen;
    	float content;
    	float score;
    	char letterGrade;

public:
    Essay()
	{
    	grammar = 0.0;
    	spelling = 0.0;
    	correctLen = 0.0;
    	content = 0.0;
		score = 0.0;
		letterGrade = ' ';
	}
    //Constructor
    Essay(float g, float sp, float cl, float c, float s, char lg)
    {
    	grammar = g;
    	spelling = sp;
    	correctLen = cl;
    	content = c;
    	score = s;
    	letterGrade = lg;
    }
    //Sets score for each category
    void setScore( float g, float sp, float cl, float c)
    {
    	grammar = g;
    	spelling = sp;
    	correctLen = cl;
    	content = c;
    }
    //Adds scores together
    void addScore()
    {
    	score = grammar + spelling + correctLen + content;
    }
    //Getter function to retrieve the score
    float getScore ()
    {
    	return score;
    }
    //Determines letter grade
    void FindletterGrade()
    {
    	if (score > 89)
            letterGrade = 'A';
        else if (score > 79 && score < 90)
            letterGrade = 'B';
        else if (score > 69 && score < 80)
            letterGrade = 'C';
        else
            letterGrade = 'F';
    }
    //Getter function for letter grade
    char getletterGrade () const
    {
     return letterGrade;
    }
 };

int main(int argc, char** argv)
{
	//Declare variables
	float score1, score2, score3, score4;
	Essay Student;

	//Prompt user for input
	cout << "Please enter up to 30 points for Grammar: ";
	cin >> score1 ;
	cout << "Please enter up to 20 points for Spelling: ";
	cin >> score2 ;
	cout << "Please enter up to 20 points for Correct Length: ";
	cin >> score3 ;
	cout << "Please enter up to 30 points for Content: ";
	cin >> score4;

	//Set the score class member
	Student.setScore(score1, score2, score3, score4);

	//Calculate score
	Student.addScore();

	//Get score from class function
	Student.getScore();

	//Determine letter grade
	Student.FindletterGrade();

	//Output letter grade for essay
	cout << "This student's grade is: " << Student.getletterGrade() << endl;

	return 0;
}
