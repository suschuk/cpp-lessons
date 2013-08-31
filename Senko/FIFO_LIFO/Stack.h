#ifndef STACK_H
#define STACK_H

#include "../list/List.h"

class Stack
{
public:
	void push(element inData);
	void pop();
	void print();

private:
	List _stack;
};




#endif