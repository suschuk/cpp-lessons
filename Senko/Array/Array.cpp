#include <iostream>
#include "Array.h"

using std::endl;

Array::Array()
{
	arr = new int;
	*arr = 0;
}

Array::Array(int size)
{
	s = size;
	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

Array::Array(const Array& inArray)
{
	s = inArray.s;

	arr = new int[s];

	for (int i = 0; i < s; i++)
	{
		arr[i] = inArray.arr[i];
	}
}

ostream& operator<<	(ostream& out, const Array& inArray)
{
	for (int i = 0; i < inArray.s; i++)
	{
		out << inArray.arr[i] << " ";
	}
	out << endl;

	return out;
}

Array& Array::operator= (Array& inArray)
{
	if(this == &inArray) 
		return *this;

	if (s != inArray.s)
	{
		this->~Array();
		s = inArray.s;
		arr = new int[inArray.s];
	}

	for (int i = 0; i < s; i++)
	{
		arr[i] = inArray.arr[i];
	}

	return *this;
}

int& Array::operator[] (const int index)
{
	if (index >= 0 && index < s)
	{
		return arr[index];
	}
	else
	{
		throw -1; // out of bounds
	}
}

Array Array::operator+ (const Array& inArray)
{
	Array tmp(s);

	if (s == inArray.s)
	{
		for (int i = 0; i < s; i++)
		{
			tmp.arr[i] = arr[i] + inArray.arr[i];
		}
	}
	else
	{
		throw -1;
	}

	return tmp;
}

Array Array::operator- (const Array& inArray)
{
	Array tmp(s);

	if (s == inArray.s)
	{
		for (int i = 0; i < s; i++)
		{
			tmp.arr[i] = arr[i] - inArray.arr[i];
		}
	}
	else
	{
		throw -1;
	}

	return tmp;
}

Array& Array::operator++ ()
{
	Array tmp;
	
	int nLen = s + 1;
	tmp.s = nLen;
	tmp.arr = new int[nLen];

	for(int i = 0; i < s; i++ )
		tmp.arr[i] = arr[i];
	
	tmp.arr[nLen-1] = 0;

	*this = tmp;

	return *this;
}

Array& Array::operator-- ()
{
	Array tmp;

	int nLen = s - 1;
	tmp.s = nLen;
	tmp.arr = new int[nLen];

	for(int i = 0; i < s-1; i++ )
		tmp.arr[i] = arr[i];

	*this = tmp;

	return *this;
}

Array::~Array()
{
	delete []arr;
}