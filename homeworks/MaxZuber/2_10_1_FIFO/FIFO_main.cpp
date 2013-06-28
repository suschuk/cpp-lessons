#include <iostream>

#include "LinkedList.h"
#include "FIFO.h"

using namespace std;

int main()
{
	FIFO stack;
	DataItem* arr[20] = {0};
	
	for(int i = 0; i < 20; i++)
		stack.push(arr[i] = new DataItem(i));

	for(int i = 0; i < 25; i++)
		cout << stack.pop() << endl;

	for(int i = 0; i < 20; i++)
		delete arr[i];

	return 0;
}