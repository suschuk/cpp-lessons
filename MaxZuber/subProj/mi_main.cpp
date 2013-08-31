#include "MenuItem.h"
#include <iostream>
#include <string>
#include "Menu.h"
using namespace std;

void func1()
{
	cout << "Run command1\n";
}
void func2()
{
	cout << "Run command2\n";
}
void func3()
{
	cout << "Run command3\n";
}

int main()
{
	MenuItem mi(std::string("1 - Add new Client"), func1);
	Menu m;
	m += mi;
	m += MenuItem(std::string("2 - Remove Client"), func2);
	m += MenuItem(std::string("3 - Review"), func3);

	cout << m << endl;


	short choice = 0;

	cout << "Menu number: ";
	cin >> choice;

	try
	{
		m[choice];
	}
	catch(length_error& le)
	{

		cout << le.what() << endl;
	}

	return 0;
}