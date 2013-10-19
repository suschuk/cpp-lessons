#include <iostream>
#include "String.h"

using namespace std;

Str::Str()						//default constructor
{
	this->s = NULL;
	this->len = 0;
}
Str::Str(char* c)				//constructor with 1 parameter
{
	this->len = strlen(c) + 1;
	this->s = new char[this->len];
	strcpy(this->s, c);
}
Str::Str(const Str& c)			//constuructor copy
{
	this->len = c.len;
	this->s = new char [this->len];
	strcpy(this->s, c.s);
}
Str::~Str()						//destructor
{
	delete [] this->s;
}

void Str::showStr() const
{
	cout << "\nString: " << this->s << endl;
}

Str Str::operator*(const Str& c)
{
	Str temp;
	char buff[128];
	int lenTmp = strlen(c.s);
	char* tmp = NULL;
	
	
	for(int i = 0; i < lenTmp; i++)
	{
		tmp = strchr(this->s, c.s[i]);
		
		if(tmp != NULL)
		{
			buff[temp.len++] = *tmp;
			buff[temp.len] = '\0';
		}
	}

	
	temp.s = new char [++temp.len];			//memory for new 'str' with finded symbols
	strcpy(temp.s, buff);						//copy finded symbols to 'str'
	return temp;
}