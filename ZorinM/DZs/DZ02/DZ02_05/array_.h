#ifndef ARRAY_H
#define ARRAY_H

using std::ostream;

class array_
{
private:
	int* arr;
	int size;

public:
	array_() : arr(0), size(0)
	{}
	array_( int );
	array_( const array_& );
	~array_();

	friend ostream& operator << ( ostream&, const array_& );
	int& operator [] ( const int );
	array_& operator = ( const array_& );
	array_ operator + ( const array_& );
	array_ operator + ( const int );
	array_& operator += ( const array_& );
	array_ operator - ( const array_& );
	array_ operator - ( const int );
	array_& operator -= ( const array_& );

	int get_size () const
	{	return size; }
};


#endif