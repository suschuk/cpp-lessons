#include <iostream>
#include <Windows.h>

using namespace std;


class Foo
{
public:
	Foo();
	~Foo();
};
class Bar: public Foo
{
public:
	Bar();
	~Bar();
};

class Fooo
{
public:
	Fooo();
	virtual ~Fooo();
};
class Baar: public Fooo
{
public:
	Baar();
	~Baar();
};





int main()
{
	SetConsoleTitle(TEXT("Virtual Destructor vs Destructor"));
	COORD c = {30, 33};
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( handle, &csbi );


	/*for(int k = 1; k < 255; k++)
	{
		// pick the colorattribute k you want
		SetConsoleTextAttribute(handle, k);
		cout << k << " I want to be nice today!" << endl;
	}*/
	
	cout << "Stack:" << endl;
	{
		cout << "Normal destructor:" << endl;	
		cout << "Bar:" << endl;
		Bar b;
	}
	SetConsoleTextAttribute( handle, csbi.wAttributes );
	{
		cout << "Foo:" << endl;
		Foo f;	
	}

	SetConsoleTextAttribute( handle, csbi.wAttributes );
	cout << "Virtual destructor" << endl;
	{
		cout << "Baar:" << endl;
		Baar b;
	}

	SetConsoleTextAttribute( handle, csbi.wAttributes );
	{
		cout << "Fooo:" << endl;
		Fooo f;

	}

	SetConsoleTextAttribute( handle, csbi.wAttributes );
	cout << "\nOn Stack it's work good, no problem, but what if we alocate object on heap?" << endl;


	cout << endl << endl << endl;
	cout << "Heap" << endl;
	cout << "Normal destructor" << endl;

	{
		cout << "bar: \t\t\t//Base pointer, point to Derived class" << endl;
		Foo* bar = new Bar;
		delete bar;

	}

	SetConsoleTextAttribute( handle, csbi.wAttributes );
	cout << "\t\t\t//ooup's problem: delete only Base class part, Derived class still in memory" << endl;
	{
		cout << "Foo:" << endl;
		Foo* foo = new Foo;
		delete foo;
	}

	SetConsoleTextAttribute( handle, csbi.wAttributes );
	cout << "Virtual destructor" << endl;
	{
		cout << "Baar:" << endl;
		Fooo* baar = new Baar;
		delete baar;
	}

	SetConsoleTextAttribute( handle, csbi.wAttributes );
	GetConsoleScreenBufferInfo(handle,&csbi);
	c= csbi.dwCursorPosition;
	c.Y--;
	c.X = 27;
	SetConsoleCursorPosition(handle, c);

	cout << "//no problem with virtual destructor, Base and Derived class deleted!" << endl;
	{
		cout <<"Fooo:" << endl;
		Fooo* fooo = new Fooo;
		delete fooo;
	}


	SetConsoleTextAttribute( handle, csbi.wAttributes );
	return 0;
}


Foo::Foo()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "\tFoo()" << endl;
}
Foo::~Foo()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "\t\t~Foo()" << endl;
}

Bar::Bar()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "\tBar()" << endl;
}
Bar::~Bar()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 );
	cout << "\t\t~Bar()" << endl;
}

Fooo::Fooo()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "\tFooo()" << endl;
}
Fooo::~Fooo()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 );
	cout << "\t\t~Fooo()" << endl;
}



Baar::Baar()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "\tBaar()" << endl;
}
Baar::~Baar()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 );
	cout << "\t\t~Baar()" << endl;
}

