/*
 * problem3.h
 *
 *  Created on: Dec 16, 2015
 *      Author: AnhLe
 */

#ifndef PROBLEM3_H_
#define PROBLEM3_H_

#include "myheader.h"

//Class declaration
template<class T>
class Prob3Table
{
protected:
    int rows;                                 //Number of rows in the table
    int cols;                                 //Number of cols in the table
    T *rowSum;                                //RowSum array
    T *colSum;                                //ColSum array
    T *table;                                 //Table array
    T grandTotal;                             //Grand total
    void calcTable(void);                     //Calculate all the sums
public:
    Prob3Table(char [],int,int);              //Constructor then Destructor
    ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
    const T *getTable(void){return table;};
    const T *getRowSum(void){return rowSum;};
    const T *getColSum(void){return colSum;};
    T getGrandTotal(void){return grandTotal;};
};

template<class T>
Prob3Table<T>::Prob3Table(char filename[], int row, int col)
{
    if(row > 0)
        rows = row;

    else
        rows = 0;

    if(col > 0)
        cols = col;

    else
        cols = 0;

    T cursor;
    table=new T[rows*cols];
    ifstream file( filename );

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            file >> cursor;
            table[i * cols + j] = cursor;
        }
    }
    file.close();
}

template <class T>
void Prob3Table<T>::calcTable(void)
{
    T sum = 0;;
    colSum = new T[cols];
    rowSum = new T[rows];

    for(int i = 0; i < rows; i++)
    {
        rowSum[i] = 0;
        for(int j = 0; j < cols; j++)
            sum += table[i*cols + j];

        rowSum[i] = sum;
        sum = 0;
    }

    for(int i = 0; i < cols; i++)
    {
        colSum[i] = 0;
        for(int j = 0; j < rows; j++)
            sum += table[j*cols + i];

        colSum[i] = sum;
        sum = 0;
    }

    grandTotal = 0;

    for(int i = 0; i < cols; i++)
        grandTotal += colSum[i];
}

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
protected:
    T *augTable;                                  //Augmented Table with sums
public:
    Prob3TableInherited(char [], int ,int);       //Constructor
    ~Prob3TableInherited(){delete [] augTable;};  //Destructor
    const T *getAugTable(void){return augTable;};
};

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char filename[], int row, int col) : Prob3Table<T>( filename, row, col)
{
    this->calcTable();
    augTable = new T[(row + 1) * (col + 1)];

    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
            augTable[r * (col+ 1) + c] = this->table[r * col + c];
    }

    for(int r = 0; r < row; r++)
        augTable[r * (col + 1) + col] = this->rowSum[r];


    for(int c = 0; c < col; c++)
        augTable[row * (col + 1) + c] = this->colSum[c];

    augTable[(row + 1) * (col + 1) - 1] = this->grandTotal;
}

#endif /* PROBLEM3_H_ */
