#include "PriorityQueue.h"

void PriorityQueue::pop()
{
	if(! list.getSize())
		return;
	list.head();
	list.remove();
}
void PriorityQueue::push(DataItem dataItem)
{
	if(! list.getSize())
	{
		list.insert(dataItem);
		return;
	}
	list.head();
	if(*list.getCurrData() < dataItem)
	{
		list.insert(*list.getCurrData());
		list.head();
		list.insert(dataItem);
		list.head();
		list.remove();
		return;
	}
	unsigned i;
	for(i = 0; i < list.getSize(); ++i)
	{
		list.next();
		if(*list.getCurrData() < dataItem)
			break;
	}
	if(i != list.getSize())
		list.prev();
	list.insert(dataItem);
}
const DataItem* PriorityQueue::top()
{
	list.head();
	return list.getCurrData();
}
unsigned PriorityQueue::getSize()
{
	return list.getSize();
}
bool PriorityQueue::isEmpty()
{
	return (! list.getSize());
}

#ifdef _DEBUG
void PriorityQueue::print()
{
	list.print();
}
#endif // _DEBUG