#include "MyVector.h"
#include <iostream>

MyVector::MyVector(int row, int col)
{
	this->col = col;
	this->row = row;
	matrix = new int* [row];
	for(int i = 0; i < row; ++i)
	{
		matrix[i] = new int [col];
		for(int j = 0; j < col; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}

MyVector::~MyVector(void)
{
}

MyVector MyVector::operator=(const MyVector& matrixObj)
{
	if(this == &matrixObj)
		return *this;

	for(int i = 0; i < row; ++i)
		delete[] matrix[i];
	delete[] matrix;

	col = matrixObj.col;
	row = matrixObj.row;

	matrix = new int* [row];
	for(int i = 0; i < row; ++i)
	{
		matrix[i] = new int [col];
		for(int j = 0; j < col; ++j)
		{
			matrix[i][j] = matrixObj.matrix[i][j];
		}
	}
	return *this;
}

MyVector MyVector::operator+(MyVector& matrixObj)
{
	MyVector newMatrixObj(row, col);
	newMatrixObj.matrix = new int* [row];
	for(int i = 0; i < row; ++i)
	{
		newMatrixObj.matrix[i] = new int [col];
		for(int j = 0; j < col; ++j)
		{
			newMatrixObj.matrix[i][j] = matrix[i][j] + matrixObj.matrix[i][j];
		}
	}
	return newMatrixObj;
}

MyMatrix MyVector::operator*(MyVector& matrixObj)
{
	MyMatrix newMatrixObj(3, 3);
	for(int i = 0; i < 3; ++i)
		newMatrixObj.matrix[0][i] = 1;
	for(int i = 0; i < 3; ++i)
		newMatrixObj.matrix[1][i] = this->matrix[i][0];
	for(int i = 0; i < 3; ++i)
		newMatrixObj.matrix[2][i] = matrixObj.matrix[i][0];
	return newMatrixObj;
}

MyVector MyVector::operator*(double x)
{
	MyVector newMatrixObj(row, col);
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			newMatrixObj.matrix[i][j] = matrix[i][j] * x;
	return newMatrixObj;
}

int* MyVector::operator[] (int i)
{
	return matrix[i];
}