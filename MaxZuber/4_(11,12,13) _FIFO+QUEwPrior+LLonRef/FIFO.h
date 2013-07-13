#pragma once
#include "LinkedList.h"

class FIFO
{
public:
	void push(DataItem*);
	DataItem pop();
	DataItem top();
	class empty_stack {};
protected:
	LinkedList list;
};

