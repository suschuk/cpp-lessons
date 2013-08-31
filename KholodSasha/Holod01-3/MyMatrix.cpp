#include "MyMatrix.h"
#include <iostream>
#include <ctime>
#include <iomanip>

MyMatrix::MyMatrix(int row, int col)
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


MyMatrix::~MyMatrix(void)
{
	for(int i = 0; i < row; ++i)
		delete[] matrix[i];
	delete[] matrix;
	matrix = NULL;
}

void MyMatrix::showMatrix()
{
	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
			std::cout << std::setw(3) << matrix[i][j];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

MyMatrix::MyMatrix(MyMatrix& matrixObj)
{
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
}

MyMatrix MyMatrix::operator=(const MyMatrix& matrixObj)
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

MyMatrix MyMatrix::operator+(MyMatrix& matrixObj)
{
	return this->add(matrixObj);
}

MyMatrix MyMatrix::operator*(MyMatrix& matrixObj)
{
	return this->mult(matrixObj);
}

MyMatrix MyMatrix::operator*(double x)
{
	MyMatrix newMatrixObj(row, col);
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			newMatrixObj.matrix[i][j] = matrix[i][j] * x;
	return newMatrixObj;
}

int* MyMatrix::operator[] (int i)
{
	return matrix[i];
}

MyMatrix MyMatrix::add(MyMatrix& matrixObj)
{
	if(col != matrixObj.col || row != matrixObj.row)
	{
		std::cerr << "Error! Count of colomns and rows must be the same\n";
		return 0;
	}
	MyMatrix newMatrixObj(row, col);
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

MyMatrix MyMatrix::mult(MyMatrix& matrixObj)
{
	if(col != matrixObj.row)
	{
		std::cerr << "Error! Count of colomns and rows must be the same\n";
		return 0;
	}
	MyMatrix newMatrixObj(row, matrixObj.col);
	newMatrixObj.matrix = new int* [newMatrixObj.row];
	int res;
	for(int i = 0; i < newMatrixObj.row; ++i)
	{
		newMatrixObj.matrix[i] = new int [newMatrixObj.col];
		for(int j = 0; j < newMatrixObj.col; ++j)
		{
			res = 0;
			for(int k = 0; k < col; ++k)
			{
				res += matrix[i][k] * matrixObj.matrix[k][j];
			}
			newMatrixObj.matrix[i][j] = res;
		}
	}
	return newMatrixObj;
}

void MyMatrix::init()
{
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			matrix[i][j] = rand() % 7;
}
void MyMatrix::setCol(int col)
{
	for(int i = 0; i < row; ++i)
		delete[] matrix[i];
	delete[] matrix;

	this->col = col;

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
void MyMatrix::setRow(int row)
{
	for(int i = 0; i < this->row; ++i)
		delete[] matrix[i];
	delete[] matrix;

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
int MyMatrix::getCol()
{
	return col;
}
int MyMatrix::getRow()
{
	return row;
}