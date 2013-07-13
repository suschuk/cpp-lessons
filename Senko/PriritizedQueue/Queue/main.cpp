#include <iostream>
#include "../List/list.h"
#include "Queue.h"

using std::cout;
using std::endl;

int main()
{
	cout << "Prioritized Queue pushing... 10..15" << endl;
	Queue C;
	for (int i = 10; i <= 15; ++i)
		C.push(i,i);

	cout << "Pushing value 0, but with priority 1000... must be 1st..." << endl;
	C.push(0, 1000);

	C.print();
	
	cout << "LIFO Queue pop 2 items" << endl;
	C.pop();
	C.pop();
	C.print();
	
	
}

