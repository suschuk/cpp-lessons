#include <exception>

#include "ZString.h"


#pragma warning( disable : 4996 ) 

ZString::ZString(char* pc)
{
	_str = new char[strlen(pc) + 1];
	strcpy(_str, pc);
}
ZString::ZString(const ZString& origin)
{
	_str = new char[strlen(origin._str) + 1];
	strcpy(_str, origin._str);
}

ZString::~ZString()
{
	delete [] _str;
}

// operations
ZString ZString::operator+(const ZString& rhs) const
{
	char* p = new char [length() + rhs.length() + 1];
	strcpy(p, _str);
	strcpy(p + length(), rhs._str); 
	return p;
}
char& ZString::operator[](const int idx)
{
	if(idx < 0 || idx >= length()) throw std::runtime_error("Out of array bounds");

	return _str[idx];
}

ZString& ZString::operator=(const ZString& rhs)
{
	if (&rhs == this) 
		return *this;

	delete [] _str;
	_str = new char[rhs.length() + 1];
	strcpy(_str, rhs._str);
	return *this;
}

bool ZString::operator==(const ZString& rhs) const
{
	return 0 == strcmp(_str, rhs._str);
}

int ZString::length() const
{
	return strlen(_str);
}

std::ostream& operator<<(std::ostream& out, const ZString& rhs)
{
	return out << rhs._str;
}

std::istream& operator>>(std::istream& in, ZString& rhs)
{
	char buffer[128] = {0};
	in >> buffer;
	buffer[127] = 0;
	rhs = ZString(buffer);
	return in;
}


bool ZString::empty() const	
{
	return !strlen(_str);
}

int ZString::copy(char* buffer, int bg, int end)
{
	int i = 0;
	for(int j = bg; j <  end; j++, i++)
	{
		buffer[i] = _str[j];
	}
	buffer[i] = 0;
	return i;
}

int ZString::find(char* srch ) const
{
	char *tmp =  strstr(_str, srch);
	return tmp - _str;
}


#pragma warning( default : 4996 )
#pragma message( "messagestring" )