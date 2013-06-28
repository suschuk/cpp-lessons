#include <iostream>

#include "LinkedList.h"

#include <ctime>

using std::cout;
using std::endl;


int main()
{
	srand((unsigned)time(0));
	cout << "Hi, all" << std::endl;

	LinkedList list;
	DataItem di = 2;

	DataItem* ptr[300] = {0};
	
	list.insert(ptr[0] = new DataItem(100));
	list.insert(ptr[1] = new DataItem(101));
	for(int i = 2; i <= 60; ++i)
		list.insert(ptr[i] = new DataItem(rand() % 10));
	
	list.pos_add_aft(ptr[201] = new DataItem(-1), 2);

	list.pos_del(5);

	if(list.search(di))
	{
		cout << "\nItem '" << di << "', found\n" << endl;
	}
	else
	{
		cout << "\nItem '" << di << "', not found\n" << endl;
	}
	cout << "\nUnsorted Linked list:\n";
	list.print();

	list.sort();


	cout << "\nSorted Linked list:" << endl;
	list.print();	


	for(int i = 0; i <= 201; ++i)
		delete ptr[i];

	return 0;
}

