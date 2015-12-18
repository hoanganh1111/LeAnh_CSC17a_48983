/*
 * problem1.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: AnhLe
 */
//Include header informations
#include "myheader.h"
#include "problem1.h"

Prob1Random::Prob1Random(const char n ,const char *randseg)
{
	nset = n;
	set = new char[nset];
	freq = new int [nset];

	for(int i = 0; i < nset; i++)
	{
		set[i] = randseg[i];
		freq[i]=0;
	}
	numRand = 0;

	//Set random number seed to time.
	srand(static_cast<unsigned int>(time(0)));
	//For some reason this works here instead of putting it
	//before the random equation in randFromSet
}

Prob1Random::~Prob1Random(void)
{
	delete []set;
	delete [] freq;
	nset = 0;
}

char Prob1Random::randFromSet(void)
{
	char num;

	numRand++;
	num = set[(rand()%nset)];
	  for(int i=0;i<nset;i++)
	  {
	      if(num == set[i])
	        {
	      freq[i]+=1;
	        }
	  }
	  return num;
}

int* Prob1Random::getFreq(void) const
{
	return freq;
}

char* Prob1Random::getSet(void) const
{
	return set;
}

int Prob1Random::getNumRand(void) const
{
	return numRand;
}

