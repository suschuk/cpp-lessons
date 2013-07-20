#pragma once
#include "linkedlist.h"

class Queue
{
public:
	Queue(void);
	~Queue(void);

	DataItem Pop();
	DataItem Pick();

	void Push(DataItem);

private:
	LinkedList linkedList;
};

