#include <iostream>

#include "LinkedList.h"

using std::cout;
using std::endl;


int main()
{
	cout << "Hi, all" << std::endl;

	LinkedList list;
	
	list.insert(new ListItem(100));
	list.insert(new ListItem(101));
	for(int i = 200; i <= 220; ++i)
		list.insert(new ListItem(i));
	
	list.tail();
	list.remove();
	list.print();
	cout << "Size is: " << list.getSize() << endl;
	list[5]->print();
	list.removeAll();
	list.print();	
}

