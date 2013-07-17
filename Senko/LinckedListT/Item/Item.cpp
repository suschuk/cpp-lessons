#include <iostream>
#include "item.h"

template <typename T> class List;

template <typename T>
Item<T>::Item(T d) 
{
	_prev = 0;
	_next = 0;
	_data = new T(d);
}

template <typename T>
Item<T>::~Item() 
{
	delete _data;
	delete _next;
}

template <typename T>
void Item<T>::print() const
{
	std::cout << *_data << std::endl;
}

