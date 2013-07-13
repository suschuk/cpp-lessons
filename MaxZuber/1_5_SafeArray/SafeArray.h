#pragma once

typedef int Data;

class SafeArray
{
public:
	SafeArray():arr_(0), size_(0) {};
	SafeArray(int size);
	SafeArray(const SafeArray&);
	~SafeArray();

	SafeArray& operator=(SafeArray&);
	Data& operator[](int indx);
private:
	 Data* arr_;
	int size_;
};

