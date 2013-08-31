#include "String_.h"


String_::String_(void)
{
	str = NULL;
}

String_::String_(const char* src)
{
	str = new char[strlen(src) + 1];
	strcpy(str,src);
}

String_::String_(const String_ &Src)
{
	String_(Src.str);
}


String_::~String_(void)
{
	delete [] str;
}

char* String_::GetStr() const
{
	return str;
}
