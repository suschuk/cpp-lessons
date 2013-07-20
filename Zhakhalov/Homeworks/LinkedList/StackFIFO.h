#pragma once
#include "linkedlist.h"

class StackFIFO
{
public:
	StackFIFO(void);
	~StackFIFO(void);

	DataItem Pop();
	DataItem Pick();

	void Push(DataItem);

private:
	LinkedList linkedList;
};

