#include <iostream>
#include "Person.h"
using namespace std;

int main()
{
	Person p[3];
	Person pers1("boris", 3542, "Market", "Rusha");
	Person pers2("Lola", 13666);

	for(int i = 0; i < 3; i++)
	{
		p[i].setName();
		p[i].setID();
		p[i].setDepartment();
		p[i].setPosition();
	}

	for(int i = 0; i < 3; i++)
	{
		cout << endl;
		cout << p[i].getName() << endl;
		cout << p[i].getID() << endl;
		cout << p[i].getDepartment() << endl;
		cout << p[i].getPosition() << endl;
	}

	cout << "\nName: " << pers1.getName();
	cout << "\nID: " << pers1.getID();
	cout << "\nDepartment: " << pers1.getDepartment();
	cout << "\nPosition: " << pers1.getPosition();

	cout << "\nName: " << pers2.getName();
	cout << "\nID: " << pers2.getID();
	cout << "\nDepartment: " << pers2.getDepartment();
	cout << "\nPosition: " << pers2.getPosition();

	return 0;
}