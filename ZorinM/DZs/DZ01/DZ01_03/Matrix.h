#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using std::ostream;

class Matrix
{
	int rows;
	int cols;
	int** matrix;

public:
	Matrix ();	
	Matrix (int r, int c);
	Matrix ( const Matrix& );
	~Matrix ();
	void show () const;
	void fill ();
	void fill ( int );
	void set_cols ( int );
	void set_rows ( int );
	Matrix& operator = (const Matrix& );
	int* operator []( int ) const;
	Matrix operator + ( const Matrix& );
	Matrix& operator += ( const Matrix& );
	Matrix operator - ( const Matrix& );
	Matrix& operator -= ( const Matrix& );
	Matrix operator * ( const Matrix& );
	Matrix& operator *= ( const Matrix& );
	friend ostream& operator << ( ostream&, const Matrix& );
	Matrix& operator ~ (); 
};


#endif
