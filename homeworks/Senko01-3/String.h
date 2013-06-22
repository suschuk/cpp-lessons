/* * String class * */

#ifndef STRING_H
#define STRING_H

class String {
public:
	String();
	String(char* inStr);
	String(const String& inStr);

	void setString(char* inStr);
	char* getString() const;

	void setLength(int inLen);
	int getLength() const;


	void inputString();
	void printString() const;

	String operator+(const String& inStr);
	String& operator=(const String& inStr);
	String operator*(const String& inStr);

	~String();

private:
	char* str;
	int len;
};

#endif 