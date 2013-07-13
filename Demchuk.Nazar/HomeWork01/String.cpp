# include "ClassString.h"

using namespace std;

void String::set_str(char* tmp)
{
	int i=sizeof(tmp);
	this->str=new char[i+1];
	strcpy(this->str, tmp);
}
void String::set_len(int len)
{
	this->len=len;
}

char* String::get_str()
{
	return this->str;
}
int String::get_len()
{
	return this->len;
}

String::String()
{
	this->str=NULL;
	this->len=0;
}
String::String(char* tmp)
{
	this->len=sizeof(tmp);
	this->str=new char[this->len+1];
	strcpy(this->str, tmp);
}
String::String(const String& str)
{
	this->len=str.len;
	this->str=new char[this->len+1];
	strcpy(this->str, str.str);
}

void String::fill_string()
{
	if(this->str!=NULL)
	{
		delete[]this->str;
	}
	cout<<"Enter your string: ";
	char a[256]; 
	gets(a); 

	this->len=strlen(a)+1;
	this->str = new char[len];
	strcpy(this->str,a); 

}
void String::show_string()
{
	puts(this->str);
}

String String::operator*(String& tmp)
{
	String res;
	res.len=sizeof(this->str)+sizeof(tmp.str)+2;
	res.str=new char[res.len/2];

	for (int i=0, t=0; i<sizeof(this->str); i++)
	{
		for (int j=0; j<sizeof(tmp.str); j++)
		{
			if (this->str[i]==tmp.str[j])
			{
				res.str[t]=this->str[i];
				t++;
			}
		}
	}

	return res;
}

//String& String::operator=(const String &tmp)
//{                                                       
//	if(this == &tmp)
//	{
//		return *this;
//	}
//
//	if(this->len != tmp.len || this->len == 0)
//	{
//		delete [] this->str;
//		this->len = tmp.len;
//		this->str = new char[this->len + 1];  
//	}
//
//	strcpy(this->str, tmp.str);
//
//	return *this;               
//}
