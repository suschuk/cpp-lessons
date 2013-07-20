#pragma once

template <typename T> 
class ListItem
{
template <typename T> friend class LinkedList;

public:
	ListItem(T);
	ListItem(T, int);
	~ListItem(void);
private:

	int _priority;
	ListItem<T>* _prev;
	ListItem<T>* _next;
	T* _data;
};

template <typename T> 
ListItem<T>::ListItem(T item, int priority)
{
	_priority = priority;
	_next = 0;
	_prev = 0;
	_data = new DataItem(item);
}

template <typename T> 
ListItem<T>::ListItem(T item)
{
	_priority = 0;
	_next = 0;
	_prev = 0;
	_data = new T(item);
}

template <typename T> 
ListItem<T>::~ListItem(void)
{
	delete _data;
	delete _next;
}


