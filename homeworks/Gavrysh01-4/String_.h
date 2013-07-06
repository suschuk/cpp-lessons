#pragma once
class String_
{
public:
	String_(void);
	String_(char * value);
	~String_(void);
	void setData (char * value);
	const char* getData (void);
	String_ operator * (String_ comp);
	String_ (String_ &copy);
	String_& operator = (String_ source);
private:
	char *data;
	size_t size;
};

