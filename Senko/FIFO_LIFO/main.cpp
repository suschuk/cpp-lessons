#include <iostream>
#include "../List/list.h"
#include "Stack.h"
#include "Queue.h"

using std::cout;
using std::endl;

int main()
{
	
	cout << "FIFO Stack pushing... 1..5" << endl;
	Stack A;
	for (int i = 1; i < 6; ++i)
		A.push(i);
	A.print();
	
	cout << "FIFO Stack pop 2 items" << endl;
	A.pop();
	A.pop();
	A.print();

	cout << "LIFO Queue pushing... 10..15" << endl;
	Queue C;
	for (int i = 10; i < 16; ++i)
		C.push(i);
	C.print();
	
	cout << "LIFO Queue pop 2 items" << endl;
	C.pop();
	C.pop();
	C.print();
	
	
}

