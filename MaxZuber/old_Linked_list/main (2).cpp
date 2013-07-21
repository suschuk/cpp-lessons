#include <iostream>

#include "LinkedList.h"

#include <ctime>

using std::cout;
using std::endl;


int main()
{
	srand(time(0));
	cout << "Hi, all" << std::endl;

	LinkedList list;
	DataItem di = 2;
	
	list.insert(new ListItem(100));
	list.insert(new ListItem(101));
	for(int i = 0; i <= 200; ++i)
		list.insert(new ListItem(rand() % 10));
	
	list.pos_add_aft(new ListItem(-1), 2);

	list.pos_del(5);

	if(list.search(di))
	{
		cout << "\nItem found\n" << endl;
	}
	else
	{
		cout << "\nItem not found\n" << endl;
	}

	list.print();

	list.sort();


	cout << endl;
	list.print();	
}

