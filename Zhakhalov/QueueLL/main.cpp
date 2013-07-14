#include "Queue.h"

void main()
{
	Queue queue;

	queue.Push(Point(99,55),0);
	queue.Push(Point(88,55),1);
	queue.Push(Point(77,55),2);
	queue.Push(Point(66,55),1);
	queue.Push(Point(55,55),2);
	queue.Push(Point(44,55),4);
	queue.Push(Point(33,55),3);

	Point p = queue.Pop();
	p = queue.Pick();

	queue.Push(Point(22,55),5);

	p = queue.Pick();
	p = queue.Pop();
	p = queue.Pop();
	p = queue.Pop();
	p = queue.Pop();
	p = queue.Pop();
	p = queue.Pop();

}