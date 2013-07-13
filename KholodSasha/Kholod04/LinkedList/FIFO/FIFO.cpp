#include "FIFO.h"

void FIFO::push(DataItem dataItem)
{
	list.tail();
	list.insert(dataItem);
}

void FIFO::pop()
{
	list.head();
	list.remove();
}

const DataItem* FIFO::front()
{
	list.head();
	return list.getCurrData();
}

const DataItem* FIFO::back()
{
	list.tail();
	return list.getCurrData();
}

bool FIFO::isEmpty()
{
	return (! list.getSize());
}

unsigned FIFO::getSize()
{
	return list.getSize();
}

#ifdef _DEBUG

void FIFO::print()
{
	list.print();
}

#endif // _DEBUG