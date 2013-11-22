#include <iostream>
#include "LinkedListOnTemplates.h"
using namespace std;

class My_int
{
public:
	My_int(int x) : k(x) {};
	operator int() { return k; };
private:
	int k;
};
int main()
{
	LinkedList<int> list;
	for(int i = 0; i < 10; ++i)
	{
		list.insert(i);
	}
	list.print();

	LinkedList<My_int> myList;
	My_int a(100);
	My_int b(200);
	myList.insert(a);
	myList.insert(b);
	myList.print();

	return 0;
}