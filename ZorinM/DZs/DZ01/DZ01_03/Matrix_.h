#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix_
{
	int Rows;
	int Cols;
	int** matrix;

public:
	Matrix_();
	Matrix_(int, int);
	Matrix_(const Matrix_&);
	~Matrix_();

	void showMtrx() const;
	void delMtrx();
	int getMax();
	int getMin();
	int* operator [](int) const;
	Matrix_ operator + (const  Matrix_&);
	Matrix_ operator * (const  Matrix_&);
	friend ostream& operator << (ostream&, const Matrix_&);
	Matrix_& operator = (const Matrix_&);
	Matrix_& operator -- (); // matrix transpose

};

#endif