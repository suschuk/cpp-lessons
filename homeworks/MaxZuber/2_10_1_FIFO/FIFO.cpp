#include "FIFO.h"
#include <iostream>

void FIFO::push(DataItem* newDataItem)
{
	list.bg_add(newDataItem);
}
DataItem FIFO::pop()
{
	if(list.getSize() == 0)
	{
		std::cout << "\nStack is empty\n";
		return -1;
	}

	list.tail();	
	DataItem tmp = *list.getCurrentData();
	list.end_del();

	return tmp;
}