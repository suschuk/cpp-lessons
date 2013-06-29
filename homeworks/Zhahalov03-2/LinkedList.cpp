#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList(void): _head(0), _tail(0), _curr(0), size(0){}


LinkedList::~LinkedList(void)
{
	delete _head;
}

ListItem* LinkedList::Next()
{
	if(_curr->_next)
	{
		_curr = _curr->_next;
	}
	return _curr;
}

ListItem* LinkedList::Prev()
{
	if(_curr->_prev)
	{
		_curr = _curr->_prev;
	}
	return _curr;
}

ListItem* LinkedList::Head()
{
	return _curr = _head;
}

ListItem* LinkedList::Tail()
{
	return _curr = _tail;
}

void LinkedList::Add(DataItem newDataItem)
{
	Tail();
	Insert(newDataItem);
}

void LinkedList::Insert(DataItem newDataItem)
{
	ListItem *newListItem = new ListItem(newDataItem);

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

void LinkedList::Remove()
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
	size--;
}

DataItem LinkedList::GetItem() const
{
	try
	{
		if(!_curr) throw "No data to return";   // 
			return *(_curr->_data);	 
	}
	catch(...)
	{
		std::cout << "No data to return\r\n";  // ??????????????????????????????????????
	}
}

int LinkedList::List() const
{
	return size;
}

