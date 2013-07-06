#include "FIFO.h"
#include <iostream>
using namespace std;

int main()
{
	FIFO queue;
	cout << queue.isEmpty() << endl;
	queue.push(10);
	cout << queue.isEmpty() << endl;
	queue.push(11);
	queue.push(12);
	queue.push(13);
	queue.print();
	cout << endl;

	const DataItem* a = queue.back();
	cout << *a << endl;
	a  = queue.front();
	cout << *a << endl;

	queue.pop();
	cout << endl;
	queue.print();

	cout << endl;
	cout << queue.getSize() << endl;

	return 0;
}