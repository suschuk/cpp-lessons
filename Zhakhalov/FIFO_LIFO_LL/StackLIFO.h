#pragma once
#include "linkedlist.h"

class StackLIFO
{
public:
	StackLIFO(void);
	~StackLIFO(void);

	DataItem Pop();
	DataItem Pick();

	void Push(DataItem);

private:
	LinkedList linkedList;
};

