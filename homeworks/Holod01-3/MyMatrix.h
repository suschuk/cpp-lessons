#pragma once
class MyMatrix
{
public:
	int** matrix;
	int col;
	int row;

	MyMatrix(int row = 5, int col = 5);
	~MyMatrix(void);
	MyMatrix(MyMatrix& matrix);
	MyMatrix operator= (const MyMatrix& matrixObj);
	MyMatrix operator+ (MyMatrix& matrixObj);
	MyMatrix operator* (MyMatrix& matrixObj);
	MyMatrix operator* (double x);
	int* operator[] (int i);

	void showMatrix();
	void init();
	MyMatrix add(MyMatrix& matrixObj);
	MyMatrix mult(MyMatrix& matrixObj);

	void setCol(int col);
	void setRow(int row);
	int getCol();
	int getRow();
};

