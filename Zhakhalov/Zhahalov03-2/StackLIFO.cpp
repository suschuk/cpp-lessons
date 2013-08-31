#include "StackLIFO.h"


StackLIFO::StackLIFO(void){}
StackLIFO::~StackLIFO(void){}

DataItem StackLIFO::Get()
{
	Tail();
	DataItem retDataItem = GetItem();
	Remove();

	return retDataItem;
}

void StackLIFO::Add(DataItem newDataItem)
{
	Tail();
	Insert(newDataItem);
}

