#include "Queue.h"

void Queue::push(element inData)
{
	_queue.tail();
	_queue.insert(inData);
}
void Queue::pop()
{
	_queue.head();
	_queue.remove();
}
void Queue::print()
{
	_queue.print();
}