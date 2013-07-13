#include "SafeArray.h"
#include <exception>

SafeArray::~SafeArray()
{
	delete [] arr_;
}
SafeArray::SafeArray(int size)
{
	arr_ = new Data[size];  // you should clean your memory
	size_ = size;
}
SafeArray::SafeArray(const SafeArray&  sa)
{
	arr_ = new Data[sa.size_];
	size_ = sa.size_;

	for(int i = 0; i < size_; i++)
	{
		arr_[i] = sa.arr_[i];
	}
}


SafeArray& SafeArray::operator=(SafeArray& sa)
{
	if(this == &sa)
	{
		return *this;
	}


	if(size_ > 0)
	{
		delete [] arr_;
	}

	
	size_ = sa.size_;
	arr_ = new Data[size_];

	for(int i = 0; i < size_; i++)
	{
		arr_[i] = sa.arr_[i];
	}

	return *this;

}
Data& SafeArray::operator[](int indx)
{
	if(indx >= 0 && indx < size_)
	{
		return arr_[indx];
	}
	else 
		throw 1;
}
