#include "String_.h"
#include <iostream>

String_::String_(void)
{
	data=NULL;
	size=0;
}

String_::String_(char * value)
{
	size=strlen(value)+1;
	data=new char [size];
	strcpy(data,value);
}

String_::~String_(void)
{
	if (data!=NULL) // Не треба
	{
		delete [] data;
	}
}

void String_::setData (char * value)
{
	if (data!=NULL) // Не треба
	{
		delete [] data;
	}
	size=strlen(value)+1;
	data=new char [size];
	strcpy(data,value);
}

const char* String_::getData (void)
{
	return data;
}

String_ String_::operator * (String_ comp)
{
	int n=(size>comp.size)? (size + 1): (comp.size + 1);
	char *temp=new char [ n ];
	memset(temp,0,n);
	char *ptr=NULL;
	
	ptr=strpbrk(data,comp.data);
	while(ptr!=NULL)
	{
		temp[strlen(temp)]=ptr[0];
		temp[strlen(temp)]='\0';
		ptr=strpbrk(ptr+1,comp.data);
	}
	
	String_ TEMP(temp);
	delete [] temp;
	return TEMP;
}

String_::String_ (String_ &copy)
{
	size=copy.size;
	//if (data!=NULL)
	//{
	//	delete [] data;
	//}
	data=new char [size+1];
	strcpy(data,copy.data);
}

String_& String_::operator = (String_ source)
{
	if (this!=&source)
	{
		size=source.size;
		if (data!=NULL)
		{
			delete [] data;
		}

		data=new char [size+1];
		strcpy(data,source.data);
	}
	return *this;
}