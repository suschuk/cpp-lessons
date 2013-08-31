#pragma once
#include "linkedlist.h"
class StackFIFO : public LinkedList
{
public:
	StackFIFO(void);
	~StackFIFO(void);

	DataItem Get();

	void Add(DataItem);
};

