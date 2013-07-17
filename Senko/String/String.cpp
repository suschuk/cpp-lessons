#include <iostream>
#include "String.h"

using namespace std;

String::String()
{
	this->str = new char[2];
	strcpy(this->str, " ");

	this->len = 2;
}

String::String(char* inStr)
{
	this->len = strlen(inStr);
	
	this->str = new char[len+1];
	strcpy(this->str, inStr);
}

String::String(const String& inStr)
{
	this->len = strlen(inStr.str);

	this->str = new char[len+1];
	strcpy(this->str, inStr.str);
}

void String::setString(char* inStr)
{
	if (this->str != NULL)
	{
		delete []str;
	}

	this->len = strlen(inStr);

	this->str = new char[len+1];
	strcpy(this->str, inStr);
}

char* String::getString() const
{
	return this->str;
}

void String::setLength(int inLen)
{
	this->len = inLen;
}

int String::getLength() const
{
	return this->len;
}

void String::inputString()
{
	char tmp[300];
	cin.getline(tmp, 300);

	if (this->str != NULL)
	{
		delete []str;
	}

	this->len = strlen(tmp);

	this->str = new char[len+1];
	strcpy(this->str, tmp);
}

void String::printString() const
{
	cout << this->str << endl;
}

String String::operator+(const String& inStr)
{
	String tmpStr;

	tmpStr.len = this->len + inStr.len;
	tmpStr.str = new char[tmpStr.len+1];

	strcpy(tmpStr.str, this->str);
	strcat(tmpStr.str, inStr.str);

	return tmpStr;
}

String& String::operator=(const String& inStr)
{
	if (this == &inStr)
	{
		return *this;
	}
	
	delete []this->str;
	this->len = inStr.len;
	this->str = new char[this->len + 1];
	
	strcpy(this->str, inStr.str);
	
	return *this;
}

String String::operator*(const String& inStr)
{
	String tmpStr;

	char* tmpArr;

	int identChars = 0;
	int k = 0;
	
	for (int i = 0; i < this->len; i++)
	{
		for (int j = 0; j < inStr.len; j++)
		{
			if (this->str[i] == inStr.str[j])
			{
				identChars++;
				break;
			}
		}
	}

	tmpStr.len = identChars;
	tmpStr.str = new char[tmpStr.len+1];
	tmpArr = new char[identChars+1];

	for (int i = 0; i < this->len; i++)
	{
		for (int j = 0; j < inStr.len; j++)
		{
			if (this->str[i] == inStr.str[j])
			{
				tmpArr[k] = inStr.str[j];
				k++;
				break;
			}
		}
	}
	tmpArr[k] = '\0';

	strcpy(tmpStr.str, tmpArr);
	
	return tmpStr;
}

String::~String()
{
	delete []this->str;
	this->str = NULL;
}