#include <iostream>
#include <iomanip>
#include "matrix.h"

using namespace std;

void Matrix::allocMatrix ()
{
	matrix_ = new int*[m];

	for (int i=0; i < m; i++)
	{
		matrix_[i] = new int[n];
	}
}

Matrix::Matrix()
{
	m = n = 2;

	allocMatrix();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] = 0;
		}
	}
}

Matrix::Matrix(int dimention, int number)
{
	m = n = dimention;

	allocMatrix();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] = number;
		}
	}
}

Matrix::Matrix(int r, int c, int number)
{
	m = r;
	n = c;

	allocMatrix();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] = number;
		}
	}
}

Matrix::Matrix(const Matrix& inMatrix)
{
	allocMatrix();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] = inMatrix.matrix_[i][j];
		}
	}
}

void Matrix::setRows(int rows)
{
	m = rows;
}

void Matrix::setCols(int cols)
{
	n = cols;
}

int Matrix::getRows() const
{
	return m;
}

int Matrix::getCols() const
{
	return n;
}

void Matrix::transp()
{
	Matrix tmp(n, m, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp.matrix_[i][j] = matrix_[j][i];
		}
	}

	*this = tmp;
}

ostream& operator<<	(ostream& out, const Matrix& inMatrix)
{
	
	size_t maxWidth = 0;
	char* buff = new char[300];

	for (int i = 0; i < inMatrix.m; i++) 
	{
		for (int j = 0; j < inMatrix.n; j++)
		{
			_itoa_s(inMatrix.matrix_[i][j],buff,300, 10);
			size_t tmp = strlen(buff);
			if (tmp > maxWidth)
			{
				maxWidth = tmp;
			}
		}		
	}

	for (int i = 0; i < inMatrix.m; i++) 
	{
		for (int j = 0; j < inMatrix.n; j++)
		{
			out << setw(maxWidth) << inMatrix.matrix_[i][j] << " ";
		}
		out << endl;
	}

	delete []buff;

	return out;
}

int& Matrix::operator() (const int r, const int c)
{
	if ( (r >= 0 && r < m) && (c >= 0 && c < n) )
	{
		return matrix_[r][c];
	}
	else
	{
		throw -1; // out of bounds
	}
	
}

Matrix& Matrix::operator= (const Matrix& inMatrix)
{
	if(this == &inMatrix) 
		return *this;

	if (m != inMatrix.m || n != inMatrix.n)
	{
		this->~Matrix();
		m = inMatrix.m;
		n = inMatrix.n;

		allocMatrix();
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] = inMatrix.matrix_[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator+=(const Matrix& inMatrix)
{
	if (m == inMatrix.m && n == inMatrix.n)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix_[i][j] += inMatrix.matrix_[i][j];
			}
		}
	}
	else
	{
		throw -1; // dimensions doesn't match
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& inMatrix)
{
	if (m == inMatrix.m && n == inMatrix.n)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix_[i][j] -= inMatrix.matrix_[i][j];
			}
		}
	}
	else
	{
		throw -1; // dimensions doesn't match
	}

	return *this;
}

Matrix& Matrix::operator*= (const Matrix& inMatrix)
{
	Matrix tmp(m, inMatrix.n, 0);

	if (n == inMatrix.m)
	{
		for (int i=0; i < tmp.m; i++) 
		{
			for (int j=0; j < tmp.n; ++j) 
			{
				for (int k=0; k < this->n; ++k) 
				{
					tmp.matrix_[i][j] += (this->matrix_[i][k]*inMatrix.matrix_[k][j]);
				}
			}
		}
	}
	else
	{
		throw -1; // rows&cols doesn't match
	}
	return (*this = tmp);
}

Matrix Matrix::operator+ (const Matrix& inMatrix)
{
	Matrix tmp;
	tmp = *this;
	tmp += inMatrix;
	return tmp;
}

Matrix Matrix::operator- (const Matrix& inMatrix)
{
	Matrix tmp;
	tmp = *this;
	tmp -= inMatrix;
	return tmp;
}

Matrix Matrix::operator* (const Matrix& inMatrix)
{
	Matrix tmp;
	tmp = *this;
	tmp *= inMatrix;
	return tmp;
}

Matrix& Matrix::operator* (const int& k)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] *= k;
		}
	}

	return *this;
}

Matrix::~Matrix()
{
	for (int i=0; i < m; i++)
	{
		delete[] matrix_[i];
	}

	delete []matrix_;
	matrix_= NULL;
}