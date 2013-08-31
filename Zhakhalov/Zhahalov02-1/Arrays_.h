#pragma once

class Arrays_
{
private:
	unsigned Length;
	float* Arr;

public:
	Arrays_(void);
	Arrays_(unsigned length);
	Arrays_(const Arrays_ &A);
	~Arrays_(void);

	void AddItem(unsigned nItem);
	void RemoveItem(unsigned nItem);
	unsigned List() const;

	Arrays_ operator+(const Arrays_ &A)
	{
		Arrays_ R = Arrays_(Length + A.Length);

		for(unsigned i = 0; i < Length; ++i)
		{
			R.Arr[i] = Arr[i];
		}

		for(unsigned i = 0; i < A.Length; ++i)
		{
			R.Arr[i + Length] = A.Arr[i];
		}

		return R;
	}

	Arrays_& operator=(Arrays_ A)
	{
		if(Arr)
		{
			delete [] Arr;
		}

		Length = A.Length;

		Arr = new float[Length];

		for(unsigned i = 0; i < Length; ++i)
		{
			Arr[i] = A.Arr[i];
		}

		return *this;
	}

	float operator[](unsigned i)
	{
		if(i >= Length) 
		{
			return 0;//or exeption
		}

		return Arr[i];
	}

	Arrays_ operator--()
	{
		RemoveItem(1);

		return *this;
	}

	Arrays_ operator++()
	{
		AddItem(1);

		return *this;
	}

};

