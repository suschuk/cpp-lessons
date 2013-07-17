#include "list.h"
#include <iostream>

template <typename T>
List<T>::List() : _head(0), _tail(0), _curr(0), _size(0)
{}

template <typename T>
List<T>::~List()
{
	delete _head;
}

template <typename T>
int List<T>::getSize()
{
	return _size;
}

template <typename T>
Item<T>* List<T>::next()
{
	if(_curr->_next) 
		_curr=_curr->_next;
	return _curr;
}

template <typename T>
Item<T>* List<T>::prev() 
{
	if(_curr->_prev) 
		_curr=_curr->_prev;
	return _curr;
}

template <typename T>
Item<T>* List<T>::head() 
{
	return _curr = _head;
}

template <typename T>
Item<T>* List<T>::tail() 
{
	return _curr = _tail;
}

template <typename T>
Item<T>* List<T>::insert(T inData) 
{
	Item<T>* inItem = new Item<T>;
	*(inItem->_data) = inData;
	
	if( _curr == 0 ) 
	{
		_head = _tail = _curr = inItem;
	} 
	else 
	{
		inItem->_next = _curr->_next;

		if(_curr->_next)
		{
			_curr->_next->_prev = inItem;
		} 
		else 
		{
			_tail = inItem;
		}

		inItem->_prev = _curr;
		_curr->_next = inItem;
		next();
	}

	_size++;

	return _curr;
}

template <typename T>
void List<T>::remove()
{
	if(_size >= 1)
	{	

		if(_size == 1)
		{
			delete _curr;
			_head =  _tail = _curr = 0;
		}
		else
			if(_curr == _head)
			{
				_curr->_next->_prev = 0;
				_head = _curr->_next;
				_curr = _curr->_next;
			}
			else 
				if(_curr == _tail)
				{
					_tail = _curr->_prev;
					_curr = _curr->_prev;
				}
				else
				{
					_curr->_prev->_next = _curr->_next;
					_curr->_next->_prev = _curr->_prev;
					_curr = _curr->_next;			
				}

				_size--;
	}

}

template <typename T>
void List<T>::clear()
{
	head();
	
	if(!_curr)
		return;

	while(_curr) 
	{
		this->remove();
	}

}

template <typename T>
void List<T>::print() 
{
	Item<T>* saved = _curr;
	head();

	int i = 0;
	while(i < _size) 
	{
		_curr -> print();
		next();
		i++;
	}

	_curr = saved;
}

template <typename T>
T List<T>::getData()
{
	return *(_curr->_data);
}

template <typename T>
void List<T>::setData(T inData)
{
	*(_curr->_data) = inData;
}
