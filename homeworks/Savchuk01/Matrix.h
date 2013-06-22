#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>

class Matrix
{
public:
	int** matrix;
	Matrix();
	Matrix(int row, int column);
	~Matrix();
	void fill();
	void print() const;
	void setColumn(int & column);
	void setRow(int & row);
	int getColumn() const; 
	int getRow() const; 
	
private:
	int column;
	int row;
};

#endif