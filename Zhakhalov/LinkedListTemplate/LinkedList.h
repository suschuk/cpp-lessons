#pragma once
#include "ListItem.h"
#include <iostream>

template <typename T> 
class LinkedList
{
public:
	LinkedList(void);
	~LinkedList(void);

	ListItem<T>* Next();
	ListItem<T>* Prev();
	ListItem<T>* Head();
	ListItem<T>* Tail();

	void Add(T);
	void Add(T, int);
	void Insert(T, int);
	void Insert(T);
	void Priority(int);
	void Remove();		

	T GetItem() const;

	int Count() const;
	int Priority() const;

private:

	ListItem<T>* _head;
	ListItem<T>* _tail;
	ListItem<T>* _curr;
	int _size;
};

template <typename T>
LinkedList<T>::LinkedList(void): _head(0), _tail(0), _curr(0), _size(0){}


template <typename T>
LinkedList<T>::~LinkedList(void)
{
	delete _head;
}

template <typename T>
ListItem<T>* LinkedList<T>::Next()
{
	if(_curr->_next)
	{
		_curr = _curr->_next;
	}
	return _curr;
}

template <typename T>
ListItem<T>* LinkedList<T>::Prev()
{
	if(_curr->_prev)
	{
		_curr = _curr->_prev;
	}
	return _curr;
}

template <typename T>
ListItem<T>* LinkedList<T>::Head()
{
	return _curr = _head;
}

template <typename T>
ListItem<T>* LinkedList<T>::Tail()
{
	return _curr = _tail;
}

template <typename T> 
void LinkedList<T>::Add(T newDataItem)
{
	Tail();
	Insert(newDataItem);
}

template <typename T> 
void LinkedList<T>::Add(T newDataItem, int priority)
{
	Tail();
	Insert(newDataItem,priority);
}

template <typename T> 
void LinkedList<T>::Insert(T newDataItem, int priority)
{
	ListItem *newListItem = new ListItem(newDataItem,priority);

	if(!_curr)
	{
		_head = _tail = _curr = newListItem;
		size++;
	}
	else
	{
		newListItem->_next = _curr->_next;
		if(_curr->_next)
		{
			_curr->_next->_prev = newListItem;
		}
		else 
		{
			_tail = newListItem;
		}

		newListItem->_prev = _curr;
		_curr->_next = newListItem;
		Next();

		size++;
	}
}

template <typename T>
void LinkedList<T>::Insert(T newDataItem)
{
	ListItem<T> *newListItem = new ListItem<T>(newDataItem);

	if(!_curr)
	{
		_head = _tail = _curr = newListItem;
		_size++;
	}
	else
	{
		newListItem->_next = _curr->_next;
		if(_curr->_next)
		{
			_curr->_next->_prev = newListItem;
		}
		else 
		{
			_tail = newListItem;
		}

		newListItem->_prev = _curr;
		_curr->_next = newListItem;
		Next();

		_size++;
	}
}

template <typename T>
void LinkedList<T>::Priority(int priority)
{
	if(!_curr)return;
	_curr->_priority = priority;
}

template <typename T>
void LinkedList<T>::Remove()
{
	if(!_curr)return; // or exeption

	if(_curr->_next)
	{
		if(_curr->_prev)
			_curr->_prev->_next = _curr->_next;
	}
	else // curr = tail
	{
		_tail = _curr->_prev;
		_curr->_prev->_next = 0;
	}

	if(_curr->_prev)
	{
		if(_curr->_next)
			_curr->_next->_prev = _curr->_prev;		
	}
	else // curr = head
	{
		_head = _curr->_next;
		_curr->_next->_prev = 0;
	}

	delete _curr->_data;

	if(_curr->_next) 
		_curr = _curr->_next;
	else 
		_curr = _curr->_prev;
	_size--;
}

template <typename T>
T LinkedList<T>::GetItem() const
{
	if(!_curr) throw std::runtime_error("Current item not exist");	

	return *(_curr->_data);	 
}

template <typename T>
int LinkedList<T>::Priority() const
{
	try
	{
		if(!_curr) throw "Current item not exist";			
	}
	catch(char* s)
	{
		std::cout << s;
		return 0;
	}
	return _curr->_priority;
}

template <typename T>
int LinkedList<T>::Count() const
{
	return _size;
}


