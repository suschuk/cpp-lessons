# include <iostream>
# include <string.h>
# include <math.h>
# ifndef CLASSSTRING_H_
# define CLASSSTRING_H_

class String
{
private:
	char* str;
	int len;
public:
	void set_str(char* str);
	void set_len(int len);

	char* get_str();
	int get_len();

	String();
	String(char* tmp);
	String(const String& str);
	
	~String()
	{
		delete[] this->str;
		this->len=0;
	}

	void fill_string();
	void show_string();

	String operator*(String& tmp);
	String& operator=(const String &str);
};

#endif