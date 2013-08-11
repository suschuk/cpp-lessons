#include <iostream>
#include "smartPtr.h"
using namespace std;

class Person
{
	int age;
	char* pName;
public:
	Person() : age(0), pName(0)
	{}
	Person(char* n, int a) : age(a), pName(n)
	{}
	~Person()
	{
		age = 0;
		pName = NULL;
	}

	void show() const
	{
		cout << "Name = " << pName << "; Age = " << age << endl;
	}
};

int main()
{
	smartPtr<Person> p(new Person("Mickey", 39));
	p->show();
	cout << "Reffs Count = " << p.getRefCount() << endl;
	{
		smartPtr<Person> p2 = p;
		p2->show();
		cout << "Reffs Count = " << p.getRefCount() << endl;
	}
	p->show();
	cout << "Reffs Count = " << p.getRefCount() << endl;

	return 0;
}


// source: http://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c