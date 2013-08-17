#include <iostream>
#include "LinkedList.h"

using std::cout;

class Queue
{
protected:
	LinkedList list;
public:
	void push(ListItem*);
	void pop();
	DataItem getCurrent(int pos) const;
	void show() 
	{ list.print();	}
};

class Stack : Queue
{
public:
	void push(ListItem* newListItem)
	{
		Queue::push(newListItem);
	}
	
	void pop()
	{
		// stack
		Queue::list.head();	
		Queue::list.DelHead();
	
	}

	void show() 
	{ Queue::show(); }

};

void Queue::push(ListItem* newListItem)
{
	list.insert(newListItem);
}

void Queue::pop()
{
	if(list.GetSize() == 0)
	{
		std::cout << "\nQueue is empty\n";
	}

	// queue
	list.tail();	
	list.DelTail();
}

DataItem Queue::getCurrent(int pos) const
{
	return list.GetDataItem(pos);
}

int main()
{
	Queue qu;
	for (int i = 0; i < 15; i++)
	{
		qu.push( new ListItem(i + 1) );
	}
	qu.show();
	cout << "\n";
	
	qu.pop();
	qu.pop();
	qu.show();

	cout << "\n\n";
	
	Stack st;
	for (int i = 0; i < 15; i++)
	{
		st.push( new ListItem(i + 1) );
	}

	st.show();
	cout << "\n";
	
	st.pop();
	st.pop();
	st.show();

	cout << "\n\n";

	return 0;
}