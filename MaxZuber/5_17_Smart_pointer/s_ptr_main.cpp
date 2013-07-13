#include <iostream>
#include "s_ptr.h"

using namespace std;

class Foo
{
public:
	int ret_var()
	{
		return var;
	}
	Foo(int f = 5) : var(f) {};

private:
	int var;
};

int main()
{

	s_ptr<Foo> ptr1 =new Foo(1);
	s_ptr<Foo> ptr2 =new Foo(2);
	s_ptr<Foo> ptr3 =new Foo(3);


	cout << ptr1->ret_var() << endl;

	ptr1 = ptr2;
	cout << ptr1->ret_var() << endl;
	ptr2 = ptr3;
	cout << endl;
	cout << ptr1->ret_var() << endl;
	cout << ptr2->ret_var() << endl;
	cout << ptr3->ret_var() << endl;



	return 0;
}