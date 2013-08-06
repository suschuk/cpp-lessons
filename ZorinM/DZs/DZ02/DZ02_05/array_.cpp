#include <iostream>
#include "array_.h"

using std::cout;
using std::endl;

array_::array_( int s )
{
	size = s;
	arr = new int[size];
	
	for ( int i = 0; i < size; i++ )
		arr[i] = 0;
}

array_::array_( const array_& src )
{
	size = src.size;
	arr = new int [size];

	for( int i = 0; i < size; i++)
		arr[i] = src.arr[i];
}

array_::~array_ ()
{
	size = 0;
	delete [] arr;
	arr = 0;
}

ostream& operator << ( ostream& out, const array_& src )
{
	for( int i = 0; i < src.size; i++ )
	{
		out << src.arr[i] << " ";
	}
	
	out << endl;

	return out;
}

int& array_::operator [] ( const int i )
{
	if ( i < 0 || i > size - 1 )
		exit (1);

	return arr[i];
}

array_& array_::operator = ( const array_& src )
{
	if ( &src == this )
		return *this;
	
	if ( size != src.size )
	{
		this->~array_();
		size = src.size;
		arr = new int[size];
	}

	for ( int i = 0; i < size; i++)
		arr[i] = src.arr[i];

	return *this;
}

array_ array_::operator + ( const array_& src )
{
	if ( size != src.size )
		exit(1);

	array_ tmp(size); 

	for( int i = 0; i < size; i++)
	{
		tmp.arr[i] = arr[i] + src.arr[i];
	}
	
	return tmp;
}

array_ array_::operator + ( const int in )
{
	array_ tmp(size);
	for ( int i = 0; i < size; i++ )
		tmp.arr[i] = arr[i] + in;

	return tmp;
}

array_& array_::operator += ( const array_& src )
{
	if ( size != src.size )
		exit(1);

	for ( int i = 0; i < size; i++ )
		arr[i] += src.arr[i];

	return *this;
}

array_ array_::operator - ( const array_& src )
{
	if ( size != src.size )
		exit (1);

	array_ tmp(size);

	for ( int i = 0; i < size; i++)
		tmp.arr[i] = arr[i] - src.arr[i];

	return tmp;
}

array_ array_::operator - ( const int in )
{
	array_ tmp(size);
	for ( int i = 0; i < size; i++ )
		tmp.arr[i] = arr[i] - in;

	return tmp;
}

array_& array_::operator -= ( const array_& src )
{
	if (size != src.size)
		exit(1);

	for ( int i = 0; i < size; i++)
		arr[i] -= src.arr[i];

	return *this;
}

