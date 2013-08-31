#ifndef QUEUE_H
#define QUEUE_H

#include "../list/List.h"

class Queue
{
public:
	void push(element inData);
	void pop();
	void print();

private:
	List _queue;
};




#endif