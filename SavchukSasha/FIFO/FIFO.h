#pragma once
#include "LinkedList.h"

class FIFO
{
public:
	void push(DataItem*);
	DataItem pop();
private:
	LinkedList list;
};

