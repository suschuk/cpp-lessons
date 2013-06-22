#include "Matrix.h"
#include <ctime>
#include <iomanip>

using namespace std;

//	Matrix::Matrix();
Matrix::Matrix(int row, int column)
{
	this->column = column;
	this->row = row;
	matrix = new int* [row];
	for (int i = 0; i < row; ++i)
	{
		matrix[i] = new int [column];
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < row; ++i)
	{
		delete [] matrix[i];
	}
	delete [] matrix;
}

void Matrix::fill()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			matrix[i][j] = rand() % 10;;
		}
	}
}

void Matrix::print()  const
{
	if (matrix == NULL)
	{
		cout << "Matrix not faund!!!" << endl;
		return;
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << setw(3) << left << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::setColumn(int & column)
{
	this->column = column;
}

void Matrix::setRow(int & row)
{
	this->row = row;
}

int Matrix::getColumn() const
{
	return this->column;
}

int Matrix::getRow() const
{
	return this->row;
}
