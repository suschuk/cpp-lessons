#include "list.h"
#include <iostream>

List::List() : _head(0), _tail(0), _curr(0), _size(0)
{}

List::~List()
{
	delete _head;
}

int List::getSize()
{
	return _size;
}

Item* List::next()
{
	if(_curr->_next) 
		_curr=_curr->_next;
	return _curr;
}

Item* List::prev() 
{
	if(_curr->_prev) 
		_curr=_curr->_prev;
	return _curr;
}

Item* List::head() 
{
	return _curr = _head;
}

Item* List::tail() 
{
	return _curr = _tail;
}

Item* List::insert(element inData) 
{
	Item* inItem = new Item;
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

void List::remove()
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

void List::clear()
{
	head();
	
	if(!_curr)
		return;

	while(_curr) 
	{
		this->remove();
	}

}

void List::print() 
{
	Item* saved = _curr;
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

element List::getData()
{
	return *(_curr->_data);
}

void List::setData(element inData)
{
	*(_curr->_data) = inData;
}
