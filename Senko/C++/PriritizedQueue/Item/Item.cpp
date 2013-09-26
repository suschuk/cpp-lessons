#include <iostream>
#include "item.h"


Item::Item(element d) 
{
	_prev = 0;
	_next = 0;
	_data = new element(d);
	_priority = 0;
}

Item::~Item() 
{
	delete _data;
	delete _next;
}

void Item::print() const
{
	std::cout << *_data << " - " <<_priority << std::endl;
}
unsigned int Item::getPriority()
{
	return _priority;
}

void Item::setPriority(unsigned int p)
{
	_priority = p;
}

