#include "StackFIFO.h"


StackFIFO::StackFIFO(void){}


StackFIFO::~StackFIFO(void){}

DataItem StackFIFO::Get()
{
	Head();
	DataItem retDataItem = GetItem();
	Remove();

	return retDataItem;
}

void StackFIFO::Add(DataItem newDataItem)
{
	Tail();
	Insert(newDataItem);
}
