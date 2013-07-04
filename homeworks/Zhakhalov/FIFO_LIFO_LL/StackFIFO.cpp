#include "StackFIFO.h"


StackFIFO::StackFIFO(void){}


StackFIFO::~StackFIFO(void){}

DataItem StackFIFO::Pop()
{
	linkedList.Head();
	DataItem retDataItem = linkedList.GetItem();
	linkedList.Remove();

	return retDataItem;
}

DataItem StackFIFO::Pick()
{
	linkedList.Head();
	return linkedList.GetItem();
}

void StackFIFO::Push(DataItem newDataItem)
{
	linkedList.Tail();
	linkedList.Insert(newDataItem);
}
