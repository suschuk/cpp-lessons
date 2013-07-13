#pragma once


template <typename T>
class s_ptr
{
public:
	s_ptr(T* obj_ = 0) : obj(obj_), count(new unsigned(1)) {};
	~s_ptr(void) 
	{ 
		if(*count == 1)
		{
			delete obj; 
			delete count;
		}
		else 
			*count--;
	}

	T* operator ->()
	{
		return obj;
	}
	T& operator *()
	{
		return *obj;
	}

	s_ptr<T>& operator=(s_ptr<T>& rhs)
	{
		if(*count == 1)
		{
			delete obj;
			delete count;
		}
		else 
		{
			*count--;
		}
		obj = rhs.obj;
		count = rhs.count;
		(*count)++;

		return *this;
	}
	s_ptr<T>(const s_ptr<T>& rhs)
	{
		if(*cout == 1)
		{
			delete obj;
			delete count;
		}
		else
		{
			*count--;
		}

		obj = rhs.obj;
		count = rhs.count;
		(*count)++;
	}

private:
	T* obj;
	unsigned* count;
};

