/*
 * ZString declarion
 */
#include <iostream>

class ZString
{
friend std::ostream& operator<<(std::ostream&, const ZString&);
friend std::istream& operator>>(std::istream&, ZString&);

public:
	ZString(char* = "");
	ZString(const ZString&);
	~ZString();

	// operations
	ZString operator+(const ZString&) const;
	char& operator[](const int);
	ZString& operator=(const ZString&);
	bool operator==(const ZString&) const;

	// 
	int length() const;
	bool empty() const; //check for empty string, true if empty
	int copy(char*, int bg, int end); //copy to buffer from bg to end
	int find(char* ) const;


private:
	char* _str;
};