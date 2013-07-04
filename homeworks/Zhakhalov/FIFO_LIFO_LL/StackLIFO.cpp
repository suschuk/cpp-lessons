#include "StackLIFO.h"


StackLIFO::StackLIFO(void){}
StackLIFO::~StackLIFO(void){}

DataItem StackLIFO::Pop()
{
	linkedList.Tail();
	DataItem retDataItem = linkedList.GetItem();
	linkedList.Remove();

	return retDataItem;
}

DataItem StackLIFO::Pick()
{
	linkedList.Tail();
	return linkedList.GetItem();
}

void StackLIFO::Push(DataItem newDataItem)
{
	linkedList.Tail();
	linkedList.Insert(newDataItem);
}

