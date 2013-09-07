#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

class Object
{
public: 
	Object()
	{ cout << "Object::CONstructor" << endl; }
	~Object()
	{ cout << "Object::DEstructor" << endl; }
};

class Base
{
public:
	Base()
	{ cout << "Base::CONstructor" << endl; }
	virtual ~Base()
	{ cout << "Base::DEstructor" << endl; }
};

class Derived : public Base
{
public:
	Derived()
	{ cout << "Derived::CONstructor" << endl; }
	~Derived()
	{ cout << "Derived::DEstructor" << endl; }
	Object obj;
};


int main()
{
	Base* p = new Derived;
	delete p;

	cout << "\n\n";
	return 0;
}