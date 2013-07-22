#include "String_.h"
#include <iostream>
#pragma warning( disable : 4996 )

String_::String_()
{
	str = NULL;
	len = 0;
}

String_::String_(char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}

String_::String_(const String_& s)
{
	len = s.len;
	str = new char [len + 1];
	strcpy(str, s.str);
}

String_::~String_()
{
	delete [] str;
	str = NULL;
}

const char* String_::getStr() const
{
	return str;
}

void String_::setStr(char* s)
{
	if (str != NULL)
	{
		delete[] str;
	}

	len = strlen(s);

	str = new char[len + 1];
	strcpy(str, s);
}

int String_::getLen() const
{
	return len;
}

String_& String_::operator= (const String_& s)
{
	if( this == &s )
		return *this;

	if ( len != s.len || len == 0 ) 
	{
		delete[] str;

		len = s.len;
		str = new char[len + 1];
	}

	strcpy(str, s.str);

	return *this;
}

String_ String_::operator + (const String_& s)
{
	String_ res;
	res.len = len + s.len;
	res.str = new char[res.len + 1];
	
	strcpy(res.str, str);
 	strcat(res.str, s.str);
	
	return res;
}

String_ String_::operator* (const String_& s)
{
	String_ res;
	char* tmp = NULL;
	bool flag = false;

	for(unsigned int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < s.len; j++)
		{
			if( s.str[j] == str[i] && !flag)
			{
				flag = true;
				if(res.str == NULL)
				{
					res.len++;
					res.str = new char[res.len + 1];
					res.str[res.len - 1] = str[i];
					res.str[res.len] = 0;
				}
				else
				{
					tmp = new char[res.len + 1];
					strcpy(tmp, res.str);

					delete[] res.str;

					res.len++;
					res.str = new char[res.len + 1];
					
					strcpy(res.str, tmp);
					res.str[res.len - 1] = str[i];
					res.str[res.len] = '\0';

					delete[] tmp;
				}
				
			}
		}
		flag = false;
 	}

	return res;
}

char String_::operator [] (const int pos)
{
	if (pos < 0 || pos > len - 1)
	{
		std::cout << "Icorrect position\n";
		return NULL;
	}
	return *(str + pos);
}

#pragma warning( default : 4996 )