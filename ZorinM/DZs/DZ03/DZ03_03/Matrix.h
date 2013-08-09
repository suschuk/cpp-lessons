#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
using std::cout;
using std::ostream;

template <class T>
class Matrix
{
	int rows, cols;
	T** matrix;

public:
	Matrix (int r, int c)
	{
 		rows = r;
 		cols = c;
 
 		matrix = new T* [rows];
 
 		for ( int i = 0; i < rows; i++)
 		{
 			matrix[i] = new T [cols];
 
 			for (int j = 0; j < cols; j++)
 				matrix[i][j] = (T)j;

		}
	}
	void show () const;
};

template <class T>
void Matrix<T>::show () const
{
	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < cols; j++)
		{
			cout << matrix[i][j];
			cout << std::setw(7) << matrix[i][j];
		}
		cout << "\n";
	}
}


#endif
