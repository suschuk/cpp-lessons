#pragma once
#include "LinkedList.h"
class LIFO
{
public:
	void push(DataItem*);
	DataItem pop();
private:
	LinkedList list;
};

