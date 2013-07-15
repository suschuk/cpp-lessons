#include "Matrix_.h"
#include <iostream>
using namespace std;

Matrix_::Matrix_()
{
	Rows = 0;
	Cols = 0;
	matrix = NULL;
}

Matrix_::Matrix_(int r, int c)
{
	Rows = r;
	Cols = c;

	matrix = new int* [Rows];

	for (int i = 0; i < Rows; i++)
	{
		matrix[i] = new int [Cols];
		for(int j = 0; j < Cols; j++)
		{
			matrix[i][j] = i * Cols + j + 1; 
		}
	}
}

Matrix_::Matrix_(const Matrix_& m)
{
	Rows = m.Rows;
	Cols = m.Cols;
	
	matrix = new int* [Rows];
	for (int i = 0; i < Rows; i++)
		matrix[i] = new int [Cols];
	
	for(int i = 0; i < Rows; i++)
	{
		for(int j = 0; j < Cols; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
}

Matrix_::~Matrix_()
{
	Rows = 0;
	Cols = 0;

	for(int i = 0; i < Rows; i++)
		delete[i] matrix;

	delete[] matrix;

	//cout << "\n\tdectructor done\n";
}

void Matrix_::showMtrx() const
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << right << setw(3) << setfill(' ');
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void Matrix_::delMtrx()
{
	for (int i = 0; i < Rows; i++)
		delete[i] matrix;
	delete[] matrix;	

	matrix = NULL;
	Rows = 0;
	Cols = 0;
}

int Matrix_::getMax()
{
	int res = matrix[0][0];
	for(int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (res < matrix[i][j])
				res = matrix[i][j];
		}
	}
	return res;
}

int Matrix_::getMin()
{
	int res = matrix[0][0];
	for(int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (res > matrix[i][j])
				res = matrix[i][j];
		}
	}
	return res;
}

int* Matrix_::operator [](int i) const
{
	return matrix[i];
}

Matrix_ Matrix_::operator + (const  Matrix_& m)
{
	if (Rows == m.Rows && Cols == m.Cols)
	{
		Matrix_ res(Rows, Cols);

		for(int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				res[i][j] = matrix[i][j] + m.matrix[i][j];
			}
		}
		return res;
	}
	else
	{
		cout << "ERROR! Columns or rows are different\n";
		Matrix_ res;
		return res;
	}
	
}

Matrix_ Matrix_::operator * (const  Matrix_& m)
{
	if(Cols == m.Rows)
	{
		Matrix_ res(Rows, m.Cols);
		for(int i = 0; i < res.Rows; i++)
		{
			for (int j = 0; j < res.Cols; j++)
			{
				res.matrix[i][j] = 0;
				for(int x = 0; x < Cols; x++)
				{
					res.matrix[i][j] += matrix[i][x] * m.matrix[x][j];
				}
			}
		}
		return res;
	}
	
	cout << "ERROR! Rows first matrix doesn't equal Cols of second\n";
	Matrix_ res(0, 0);
	
	return res;
}

ostream& operator << (ostream& output, const Matrix_& m)
{
	//output << "Overloaded operator << \n";
	for (int i = 0; i < m.Rows; i++)
	{
		for (int j = 0; j < m.Cols; j++)
		{
			output.fill(' ');
			output.width(4);
			output << m.matrix[i][j];
		}
		output << endl;
	}
	
	return output;
}

Matrix_& Matrix_::operator = (const Matrix_& m)
{
	if (Cols != m.Cols || Rows != m.Rows)
	{
		delMtrx();
		Rows = m.Rows;
		Cols = m.Cols;
	
		matrix = new int* [Rows];
		for (int i = 0; i < Rows; i++)
			matrix[i] = new int [Cols];
	}
	
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Cols; j++)
			matrix[i][j] = m.matrix[i][j];

	return *this;
}

Matrix_& Matrix_::operator -- () // matrix transpose
{
	Matrix_ tmp (Cols, Rows);

	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Cols; j++)
			tmp.matrix[j][i] = matrix[i][j];

	Rows = tmp.Rows;
	Cols = tmp.Cols;

	matrix = new int* [Rows];
	for(int i = 0; i < Rows; i++)
		matrix[i] = new int [Cols];

	for(int i = 0; i < Rows; i++)
		for(int j = 0; j < Cols; j++)
			matrix[i][j] = tmp.matrix[i][j];

	return *this;
}

