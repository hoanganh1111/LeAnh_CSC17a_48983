/*
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 6, 2015, 11:18 AM
 * Purpose : create a utility of a structure referenced to a database sort
 * Hmwrk: convert structure notation to the . operator
 *        and the array notation to pointer notation
 */

//System libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User's Library
#include "IndexedColumn.h"



//Global constants

//Function prototypes
IndxCol *fill(int);
void prntStr(IndxCol *, int);
void prntAry(int*,int, int);
void mrkSort(IndxCol *);

int main(int argc, char** argv) {
    //Call random number generate seed function
    srand(static_cast<unsigned int>(time(0)));

    //Allocate the memory
    int n= 100, col=10;
    IndxCol *str=fill(n);

    //Print the structure
    cout << "The original index array" << endl;
    prntAry(str->indx,str->size,col);
    cout << "The original data array" << endl;
    prntAry(str->array,str->size,col);
    cout << "The original data array using indexed array" << endl;
    prntStr(str,col);

    //Sort the data using an index, hence data base sort
    mrkSort(str);

    //Print the structure
    cout << "The index array after sorting" << endl;
    prntAry(str->indx,str->size,col);
    cout << "The data array after sorting" << endl;
    prntAry(str->array,str->size,col);
    cout << "The data array using indexed array after sorting" << endl;
    prntStr(str,col);
    //Exit stage right
    return 0;
}

void mrkSort(IndxCol *a)
{
    //Picking a position
    for(int pos=0;pos<a->size-1;pos++)
    {              //(*a).size-1)
        //Sort a list by the position
        for(int lst= pos+1;lst<a->size;lst++)
        {
            if(a->array[a->indx[pos]]>a->array[a->indx[lst]])
            {
                int temp=a->indx[pos];
                a->indx[pos]=a->indx[lst];
                a->indx[lst]= temp;
            }
        }
    }
}
void prntAry(IndxCol *a,int size, int perLine)
{
    cout << endl;
    for(int i=0; i<size; i++)
    {
        cout<<a[i] << " ";
        if(i%perLine==(perLine-1))cout<< endl;
    }
    cout << endl;
}

void prntStr(IndxCol *a, int perLine)
{
    cout << endl;
    for(int i=0; i<a->size; i++)
    {
        cout << a->array[a->indx[i]] << " ";
        if(i%perLine==(perLine-1)) cout<< endl;
    }
    cout << endl;
}

IndxCol *fill(int n)
{
    //Allocate Memory
    IndxCol *col = new IndxCol;
    col->size=n;
    if(n<=1)n=2;
            col->size=n;
            col->array=new int[n];
            col->indx =new int[n];
            //Fill the array
            for(int i=0; i<n; i++)
            {
                col->indx[i]=i;
                col->array[i]=rand()%90+10;
            }
            //Return the allocated and filled structures
            return col;
}
