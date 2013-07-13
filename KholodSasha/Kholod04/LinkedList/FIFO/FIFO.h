#ifndef _FIFO_H_
#define _FIFO_H_

#include "../LinkedList/LinkedList.h"

class FIFO
{
public:
	void push(DataItem);
	void pop();
	const DataItem* front();
	const DataItem* back();
	bool isEmpty();
	unsigned getSize();

#ifdef _DEBUG
	void print();
#endif // _DEBUG

private:
	LinkedList list;
};

#endif //_FIFO_H_