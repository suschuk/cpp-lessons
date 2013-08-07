#ifndef SMART_POINTER_H
#define SMART_POINTER_H

template <typename T>
class SmartPointer
{
public:
	SmartPointer(T* p = NULL);
	SmartPointer(const SmartPointer<T>& inObj);
	SmartPointer operator=(const SmartPointer<T>&);
	T* operator->();
	~SmartPointer();

private:
	T* _ptr;
	int _count;
};

template <typename T>
SmartPointer<T>::SmartPointer(T* p)
{
	_ptr = p;
	_count = 0;
}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& inObj)
{
	_ptr = inObj._ptr;
	_count++;
}

template <typename T>
SmartPointer<T> SmartPointer<T>::operator=(const SmartPointer<T>& inObj)
{
	_ptr = inObj._ptr;
	_count++;
	
	return *this;
}

template <typename T>
T* SmartPointer<T>::operator->()
{
	return _ptr;
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
	if(_count == 0)
			delete[]_ptr;
		else
			_count--;
}

#endif 