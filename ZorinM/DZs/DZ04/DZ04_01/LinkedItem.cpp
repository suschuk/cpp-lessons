#include <iostream>
#include "LinkedItem.h"

template <typename T> class LinkedList;

template <typename T>
ListItem<T>::ListItem(T di)
{
	prev_ = NULL;
	next_ = NULL;
	data_ = new T(di);
}

template <typename T>
ListItem<T>::~ListItem()
{
	delete data_;
	delete next_;
}

template <typename T>
void ListItem<T>::print() const
{
	std::cout << *data_ << " ";
}