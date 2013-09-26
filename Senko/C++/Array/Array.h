#ifndef ARRAY_H
#define ARRAY_H

using std::ostream;

class Array
{
public:
	Array();
	Array(int size);
	Array(const Array& inArray);
	friend ostream& operator<<	(ostream& out, const Array& inArray); 

	Array& operator= (Array& inArray);
	int& operator[] (const int index);
	Array operator+ (const Array& inArray);
	Array operator- (const Array& inArray);
	Array& operator++ ();
	Array& operator-- ();

	~Array();
private:
	int s;
	int* arr;
};

#endif
