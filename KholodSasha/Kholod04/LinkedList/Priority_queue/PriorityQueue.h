#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include "../LinkedList/LinkedList.h"

class PriorityQueue
{
public:
	void pop();
	void push(DataItem);
	const DataItem* top();
	unsigned getSize();
	bool isEmpty();

#ifdef _DEBUG
	void print();
#endif // _DEBUG

private:
	LinkedList list;
};

#endif //_PRIORITY_QUEUE_H_