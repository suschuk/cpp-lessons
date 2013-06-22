#pragma once
#include "MyMatrix.h"
class MyVector : public MyMatrix
{
public:
	MyVector(int row = 3, int col = 1);
	~MyVector(void);

	MyVector operator= (const MyVector& matrixObj);
	MyVector operator+ (MyVector& matrixObj);
	MyMatrix operator* (MyVector& matrixObj);
	MyVector operator* (double x);
	int* operator[] (int i);

private:
	void setCol(int col);
	void setRow(int row);
	int getCol();
	int getRow();
};

