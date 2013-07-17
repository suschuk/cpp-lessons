#include <iostream>
#include "list.h"

using std::cout;
using std::endl;

int main()
{
	List list;
	
	cout << "Linked list filling ..." << endl;

	for(int i = 100; i <= 105; ++i)
		list.insert(i);

	list.print();

	cout << "Tail element setting ..." << endl;
	list.setData(555);
	
	cout << "New value of list tail ..." << endl;
	cout << list.getData() << endl;
	
	cout << "Head item removing ..." << endl;

	list.head();
	list.remove();
	list.print();


	cout << "Tail item removing..." << endl;

	list.tail();
	list.remove();
	list.print();


	cout << "Second item removing..." << endl;

	list.head();
	list.next();
	list.remove();
	list.print();

	cout << "List clearing..." << endl;
	list.clear();
	cout << "Empty list printing..." << endl;
	list.print();

}

