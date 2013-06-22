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
	for(int i = 200; i <= 301; ++i)
		list.insert(new ListItem(i));
	

	list.print();

	
}

