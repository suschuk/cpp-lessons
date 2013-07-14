#include "Queue.h"

Queue::Queue(void){}
Queue::~Queue(void){}

DataItem Queue::Pop()
{
	linkedList.Head();
	DataItem retDataItem = linkedList.GetItem();
	linkedList.Remove();

	return retDataItem;
}

DataItem Queue::Pick()
{
	linkedList.Head();
	return linkedList.GetItem();
}

void Queue::Push(DataItem newDataItem, int priority)
{
	if(linkedList.List())
	{
		linkedList.Head();
		if(linkedList.Priority() < priority) //head.priority < new.priority ----> insert newItem before head
		{
			linkedList.Head();
			linkedList.Insert(linkedList.GetItem(),linkedList.Priority());

			linkedList.Head();
			linkedList.Insert(newDataItem,priority);

			linkedList.Head();
			linkedList.Remove();
			//head = newItem._curr 
		}
		else
		{
			int i = linkedList.List();
			while( linkedList.Priority() > priority && (--i) )linkedList.Next();
			linkedList.Insert(newDataItem,priority);
		}
	}
	else
		linkedList.Insert(newDataItem,priority);
}
