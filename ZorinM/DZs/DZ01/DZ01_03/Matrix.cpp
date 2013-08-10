#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <process.h>

using std::ostream;
using std::cout;

Matrix::Matrix () : rows(0), cols(0), matrix(0)
{}

Matrix::Matrix (int r, int c)
{
	rows = r;
	cols = c;

	matrix = new int* [rows];

	for ( int i = 0; i < rows; i++)
	{
		matrix[i] = new int [cols];

		for (int j = 0; j < cols; j++)
			matrix[i][j] = 0;
	}
}

Matrix::Matrix ( const Matrix& m )
{
	rows = m.rows;
	cols = m.cols;

	matrix = new int* [rows];
	for ( int i = 0; i < rows; i++ )
		matrix[i] = new int [cols];

	for ( int i = 0; i < rows; i++ )
		for ( int j = 0; j < cols; j++ )
			matrix[i][j] = m.matrix[i][j];
}

Matrix::~Matrix ()
{
	for (int i = 0; i < rows; i++)
		delete [] matrix [i];

	delete [] matrix;

	rows = 0;
	cols = 0;
}

void Matrix::show () const
{
	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < cols; j++)
		{
			cout << std::setw(7) << matrix[i][j];
		}
		cout << "\n";
	}
}

void Matrix::fill ()
{
	for ( int i = 0; i < rows; i ++ )
		for ( int j = 0; j < cols; j++)
			matrix[i][j] = rand() % 100;
}

void Matrix::fill ( int d )
{
	for ( int i = 0; i < rows; i ++ )
		for ( int j = 0; j < cols; j++)
			matrix[i][j] = d;
}

void Matrix::set_cols ( int c )
{
	for ( int i = 0; i < rows; i++ )
		delete [] matrix [i];
	delete [] matrix;

	cols = c;

	matrix = new int* [rows];
	for ( int i = 0; i < rows; i++ )
		matrix[i] = new int [cols];

	this->fill(0);
}

void Matrix::set_rows ( int r )
{
	for ( int i = 0; i < rows; i++ )
		delete [] matrix [i];
	delete [] matrix;

	rows = r;
	matrix = new int* [rows];

	for ( int i = 0; i < rows; i++)
		matrix [i] = new int [cols];

	this->fill(0);
}

Matrix& Matrix::operator = (const Matrix& m)
{
	if ( cols != m.cols || rows != m.rows)
	{
		for (int i = 0; i < rows; i++)
			delete [] matrix [i];

		delete [] matrix;

		rows = m.rows;
		cols = m.cols;

		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			matrix[i] = new int [cols];
	}		

	for ( int i = 0; i < rows; i++ )
		for ( int j = 0; j < cols; j++ )
			matrix[i][j] = m.matrix[i][j];

	return *this;
}

int* Matrix::operator []( int i ) const
{
	return matrix[i];
}

Matrix Matrix::operator + ( const Matrix& m)
{
	if ( cols != m.cols || rows != m.rows)
	{
		cout << "ERROR! Columns or rows has different size\n";
		exit (1);
	}

	Matrix res( rows, cols );

	for ( int i = 0; i < rows; i++)
		for ( int j = 0; j < cols; j++ )
			res.matrix[i][j] = matrix[i][j] + m.matrix[i][j];

	return res;
}

Matrix& Matrix::operator += ( const Matrix& m )
{
	if ( cols != m.cols || rows != m.rows)
	{
		cout << "ERROR! Columns or rows has different size\n";
		exit (1);
	}
	
	for ( int i = 0; i < rows; i++)
		for ( int j = 0; j < cols; j++ )
			matrix[i][j] += m.matrix[i][j];

	return *this;
}

Matrix Matrix::operator - ( const Matrix& m)
{
	if ( cols != m.cols || rows != m.rows)
	{
		cout << "ERROR! Columns or rows has different size\n";
		exit (1);
	}

	Matrix res( rows, cols );

	for ( int i = 0; i < rows; i++)
		for ( int j = 0; j < cols; j++ )
			res.matrix[i][j] = matrix[i][j] - m.matrix[i][j];

	return res;
}

Matrix& Matrix::operator -= ( const Matrix& m )
{
	if ( cols != m.cols || rows != m.rows)
	{
		cout << "ERROR! Columns or rows has different size\n";
		exit (1);
	}
	
	for ( int i = 0; i < rows; i++)
		for ( int j = 0; j < cols; j++ )
			matrix[i][j] -= m.matrix[i][j];

	return *this;
}

Matrix Matrix::operator * ( const Matrix& m )
{
	if(cols == m.rows)
	{
		Matrix res(rows, m.cols);
		for(int i = 0; i < res.rows; i++)
		{
			for (int j = 0; j < res.cols; j++)
			{
				res.matrix[i][j] = 0;
				for(int x = 0; x < cols; x++)
				{
					res.matrix[i][j] += matrix[i][x] * m.matrix[x][j];
				}
			}
		}
		return res;
	}

	cout << "ERROR! Rows first matrix doesn't equal Cols of second\n";
	exit (1);	
}

Matrix& Matrix::operator *= ( const Matrix& m )
{
	if(cols == m.rows)
	{
		Matrix res(rows, m.cols);
		for(int i = 0; i < res.rows; i++)
		{
			for (int j = 0; j < res.cols; j++)
			{
				res.matrix[i][j] = 0;
				for(int x = 0; x < cols; x++)
				{
					res.matrix[i][j] += matrix[i][x] * m.matrix[x][j];
				}
			}
		}
		return (*this = res);
	}

	cout << "ERROR! Rows first matrix doesn't equal Cols of second\n";
	exit (1);	
}

ostream& operator << ( ostream& output, const Matrix& m)
{
	for ( int i = 0; i < m.rows; i++)
	{
		for ( int j = 0; j < m.cols; j++)
		{
			output.fill(' ');
			output.width(7);
			output << m.matrix[i][j];
		}
		output << "\n";
	}

	return output;
}

Matrix& Matrix::operator ~ () //	
{
	Matrix temp(rows, cols);

	for ( int i = 0; i < rows; i++)
	{
		for ( int j = 0; j < cols; j++)
		{
			temp.matrix[i][j] = matrix[i][j];
			cout << temp.matrix[i][j] << " ";
		}
		cout << "\n";
	}

	rows = temp.cols;
	cols = temp.rows;

	cout << "\n\nrows = "	<< rows << "\n";
	cout << "rows = "		<< cols << "\n\n";

	matrix = new int* [rows];
	for ( int i = 0; i < rows; i++ )
		matrix[i] = new int [cols];

	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < cols; j++ )
		{
	 		matrix[i][j] = temp.matrix[j][i];
		}
	}

	return *this;
}
