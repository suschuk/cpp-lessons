#include <iostream>
#include "item.h"


Item::Item(element d) 
{
	_prev = 0;
	_next = 0;
	_data = new element(d);
}

Item::~Item() 
{
	delete _data;
	delete _next;
}

void Item::print() const
{
	std::cout << *_data << std::endl;
}

