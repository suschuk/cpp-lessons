#ifndef STRING_H
#define STRING_H

class String_
{
private:
	char* str;
	int len;

public:
	String_();
	String_(char* s);
	String_(const String_& s);
	~String_();
	
	const char* getStr() const;
	void setStr(char* s);
	String_  operator* (const String_&);
	String_& operator= (const String_&);
};

#endif