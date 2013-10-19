#include "FIFO.h"
#include <iostream>

void FIFO::push(DataItem* newDataItem)
{
	list.bg_add(*newDataItem);
}
DataItem FIFO::pop()
{
	if(list.getSize() == 0)
	{
		throw empty_stack();
		return -1;
	}

	list.tail();	
	DataItem tmp = list.getCurrentData();
	list.del();

	return tmp;
}

DataItem FIFO::top()
{
	if(list.getSize() == 0) 
	{
		throw empty_stack();
		return -1;
	}

	list.tail();
	return list.getCurrentData();
}