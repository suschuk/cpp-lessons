#pragma once
#include "linkedlist.h"
class StackLIFO :
	public LinkedList
{
public:
	StackLIFO(void);
	~StackLIFO(void);

	DataItem Get();

	void Add(DataItem);
};

