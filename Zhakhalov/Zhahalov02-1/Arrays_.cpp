#include "Arrays_.h"


Arrays_::Arrays_(void)
{
	Arr = 0;//NULL
	Length = 0;
}

Arrays_::Arrays_(unsigned length)
{
	Length = length;
	Arr = new float[Length];
}

Arrays_::Arrays_(const Arrays_ &A)
{
	Length = A.Length;

	Arr = new float[Length];

	for(unsigned i = 0; i < Length; ++i)
	{
		Arr[i] = A.Arr[i];
	}
}


Arrays_::~Arrays_(void)
{
	if(Arr)
	{
		delete [] Arr;
	}
}

void Arrays_::AddItem(unsigned nItem)
{
	float *newArr = new float[Length+nItem];

	for(unsigned i = 0; i < Length; ++i)
	{
		newArr[i] = Arr[i];
	}

	newArr[Length] = 0.0f;
	Length += nItem;

	delete [] Arr;

	Arr = newArr;
}

void Arrays_::RemoveItem(unsigned nItem)
{
	float *newArr = new float[Length-nItem];

	for(unsigned i = 0; i < Length-nItem; ++i)
	{
		newArr[i] = Arr[i];
	}

	newArr[Length] = 0.0f;
	Length -= nItem;

	delete [] Arr;

	Arr = newArr;
}

unsigned Arrays_::List() const
{
	return Length;
}
