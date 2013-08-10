#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>

using std::cout;
using std::ostream;
using std::cerr;

template <class T>
class Matrix
{
	int rows, cols;
	T** matrix;

public:
	Matrix ();
	Matrix (int, int);
	Matrix(const Matrix&);
	~Matrix();

	void show () const;
	void fill();
	void fill( T );
	void set_rows ( int );
	void set_cols ( int );

	Matrix& operator = (const Matrix& );
	T* Matrix::operator []( int ) const;
	Matrix operator + ( const Matrix& );
	Matrix& operator += ( const Matrix& );
	Matrix operator - ( const Matrix& );
	Matrix& operator -= ( const Matrix& );
	Matrix operator * ( const Matrix& );
	Matrix& operator *= ( const Matrix& );
	Matrix& operator ~ ();

	friend ostream& operator << ( ostream& output, const Matrix& m )
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

};

template <class T>
Matrix<T>::Matrix() : rows(0), cols(0), matrix(0)
{}

template <class T>
Matrix<T>::Matrix (int r, int c)
{
 	rows = r;
 	cols = c;
	
 	matrix = new T* [rows];
 
 	for ( int i = 0; i < rows; i++)
 	{
 		matrix[i] = new T [cols];
 
 		for (int j = 0; j < cols; j++)
 			matrix[i][j] = (T)(rand()%99);

	}
}

template <class T>
Matrix<T>::Matrix(const Matrix& m)
{
	rows = m.rows;
	cols = m.cols;

	matrix = new T* [rows];
	for ( int i = 0; i < rows; i++ )
		matrix[i] = new T [cols];

	for ( int i = 0; i < rows; i++ )
		for ( int j = 0; j < cols; j++ )
			matrix[i][j] = m.matrix[i][j];
}

template <class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete [] matrix [i];

	delete [] matrix;

	rows = 0;
	cols = 0;
}


template <class T>
void Matrix<T>::show () const
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

template <class T>
void Matrix<T>::fill()
{
	for ( int i = 0; i < rows; i ++ )
		for ( int j = 0; j < cols; j++)
			matrix[i][j] = static_cast<T>(rand() % 99);
}

template <class T>
void Matrix<T>::fill( T t)
{
	for ( int i = 0; i < rows; i ++ )
		for ( int j = 0; j < cols; j++)
			matrix[i][j] = t;
}

template <class T>
void Matrix<T>::set_rows ( int r )
{
	for ( int i = 0; i < rows; i++ )
		delete [] matrix [i];
	delete [] matrix;

	rows = r;
	matrix = new T* [rows];

	for ( int i = 0; i < rows; i++)
		matrix [i] = new T [cols];

	this->fill((T)99);
	// this->fill((T)0);
}

template <class T>
void Matrix<T>::set_cols ( int c )
{
	for ( int i = 0; i < rows; i++ )
		delete [] matrix [i];
	delete [] matrix;

	cols = c;

	matrix = new T* [rows];
	for ( int i = 0; i < rows; i++ )
		matrix[i] = new T [cols];

	// this->fill((T)0);
	this->fill((T)99);
}

template <class T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T>& m)
{
	if ( cols != m.cols || rows != m.rows)
	{
		for (int i = 0; i < rows; i++)
			delete [] matrix [i];

		delete [] matrix;

		rows = m.rows;
		cols = m.cols;

		matrix = new T* [rows];
		for (int i = 0; i < rows; i++)
			matrix[i] = new T [cols];
	}		

	for ( int i = 0; i < rows; i++ )
		for ( int j = 0; j < cols; j++ )
			matrix[i][j] = m.matrix[i][j];

	return *this;
}

template <class T>
T* Matrix<T>::operator []( int i ) const
{
	return matrix[i];
}

template <class T>
Matrix<T> Matrix<T>::operator + ( const Matrix<T>& m)
{
	if ( cols != m.cols || rows != m.rows)
	{
		cerr << "ERROR! Columns or rows has different size\n";
		exit (1);
	}

	Matrix res( rows, cols );

	for ( int i = 0; i < rows; i++)
		for ( int j = 0; j < cols; j++ )
			res.matrix[i][j] = matrix[i][j] + m.matrix[i][j];

	return res;

}

template <class T>
Matrix<T>& Matrix<T>::operator += ( const Matrix<T>& m )
{
	if ( cols != m.cols || rows != m.rows)
	{
		cerr << "ERROR! Columns or rows has different size\n";
		exit (1);
	}
	
	for ( int i = 0; i < rows; i++)
		for ( int j = 0; j < cols; j++ )
			matrix[i][j] += m.matrix[i][j];

	return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator - ( const Matrix<T>& m )
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

template <class T>
Matrix<T>& Matrix<T>::operator -= ( const Matrix<T>& m )
{
	if ( cols != m.cols || rows != m.rows)
	{
		cerr << "ERROR! Columns or rows has different size\n";
		exit (1);
	}
	
	for ( int i = 0; i < rows; i++)
		for ( int j = 0; j < cols; j++ )
			matrix[i][j] -= m.matrix[i][j];

	return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator * ( const Matrix<T>& m )
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

	cerr << "ERROR! Rows first matrix doesn't equal Cols of second\n";
	exit (1);	
}

template <class T>
Matrix<T>& Matrix<T>::operator *= ( const Matrix<T>& m )
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

	cerr << "ERROR! Rows first matrix doesn't equal Cols of second\n";
	exit (1);	
	
}

template <class T>
Matrix<T>& Matrix<T>::operator ~ ()
{
	Matrix temp(rows, cols);

	for ( int i = 0; i < rows; i++)
	{
		for ( int j = 0; j < cols; j++)
		{
			temp.matrix[i][j] = matrix[i][j];
			// cout << temp.matrix[i][j] << " ";
		}
		// cout << "\n";
	}

	rows = temp.cols;
	cols = temp.rows;

	matrix = new T* [rows];
	for ( int i = 0; i < rows; i++ )
		matrix[i] = new T [cols];

	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < cols; j++ )
		{
	 		matrix[i][j] = temp.matrix[j][i];
		}
	}

	return *this;

}

#endif
