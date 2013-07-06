#include <iostream>
#include <iomanip>
#include "PriorQueue.h"

using namespace std;

int main()
{
	cout << "\tQUEUE with Prioritet TEST\n" << endl;
	PriorQueue queue;
	DataItem* arr[20] = {0};

	for(int i = 0; i < 15; i++)
	queue.push(*(arr[i] = new DataItem(i)), i);

	queue.push(*(arr[15] = new DataItem(500)), 0);
	queue.push(*(arr[16] = new DataItem(501)), 10);
	queue.push(*(arr[17] = new DataItem(502)), 14);
	queue.push(*(arr[18] = new DataItem(503)), 15);
	queue.push(*(arr[19] = new DataItem(504)), 20);


	try
	{
	cout << queue.top() << endl;
	}
	catch (PriorQueue::empty_stack)
	{
	cout << "\nStack is empty\n";
	}


	for(int i = 0; i < 25; i++)
	{
	try
	{
	cout << "Top: " << setw(5) << queue.top() << "    ";
	}
	catch (PriorQueue::empty_stack)
	{
	cout << "\nStack is empty\n";
	}

	try
	{
	cout <<  "Pop: " << setw(5) << queue.pop() << endl;
	}
	catch (PriorQueue::empty_stack)
	{
	cout << "\nStack is empty\n";
	}

	}


//fifo test
	FIFO stack;

	cout << "\n\n\n\n\tFIFO TEST\n" << endl;
	for(int i = 0; i < 20; i++)
		stack.push(arr[i]);


	try
	{
		cout << stack.top() << endl;
	}
	catch (FIFO::empty_stack)
	{
		cout << "\nStack is empty\n";
	}


	for(int i = 0; i < 25; i++)
	{
		try
		{
			cout << "Top: " << setw(5) << stack.top() << "    ";
		}
		catch (FIFO::empty_stack)
		{
			cout << "\nStack is empty\n";
		}

		try
		{
			cout <<  "Pop: " << setw(5) << stack.pop() << endl;
		}
		catch (FIFO::empty_stack)
		{
			cout << "\nStack is empty\n";
		}

	}


	for(int i = 0; i < 20; i++)
	delete arr[i];
	return 0;
}