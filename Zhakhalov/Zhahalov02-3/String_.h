#pragma once

#include <cstring>

class String_
{
private:
	char* str;

public:
	String_(void);
	String_(const String_ &Src);
	String_(const char* src);	
	~String_(void);

	char* GetStr() const;

	String_ operator*(const String_ &Src) 
	{
		char* result  = new char[strlen(str) + 1];
		char* carrier = result;

		int len1 = strlen(str);
		int len2 = strlen(Src.str);

		for(int i = 0; i < len1; ++i)
		{
			for(int j = 0; j < len2; ++j)
			{
				if( (str[i] == Src.str[j]) && !strchr(result,str[i]))
				{
					*(carrier) = str[i];
					carrier++;
				}
			}
		}

		*(carrier) = '\0';

		return String_(result);
	}

};

