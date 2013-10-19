#include "LIFO.h"
#include <iostream>

void LIFO::push(DataItem* newDataItem)
{
	list.bg_add(newDataItem);
}
DataItem LIFO::pop()
{
	if(list.getSize() == 0)
	{
		std::cout << "\nStack is empty\n";
		return -1;
	}

	list.head();	
	DataItem tmp = *list.getCurrentData();
	list.bg_del();
	
	return tmp;
}
