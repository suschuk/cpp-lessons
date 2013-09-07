#include "Clients.h"
#include <iostream>
#include <algorithm>
using namespace std;


ostream& operator << (ostream& out, Person& p)
{

	out << p.fName << " " << p.sName << " " << p.lName;
	return out;
}

ostream& operator<<(ostream& out, Clients& c)
{
	auto it = c.clients.begin();

	while(it != c.clients.end())
	{
		out << *it << endl;
		++it;
	}

	return out;
}

void Clients::cons_add()
{

	string f, s, l;
	cout << "::Adding new Client::" << endl;
	cin.sync();
	cout << "Enter first name: ";
	getline(cin, f);
	cout << "Enter second name: ";
	cin.sync();
	getline(cin , s);
	cout << "Enter last name: ";
	cin.sync();
	getline(cin, l);
	add(f, s, l);
}

void Clients::add(std::string& f, std::string& s, std::string& l)
{
	clients.push_back(Person(f, s, l));
}
void Clients::cons_find()
{
	string f, s, l;
	cout << "Enter first name: ";
	cin.sync();
	getline(cin, f);
	cout << "Enter second name: ";
	cin.sync();
	getline(cin , s);
	cout << "Enter last name: ";
	cin.sync();
	getline(cin, l);
	std::list<Person>::iterator it;
	it = _find(f, s, l);

	if(it != clients.end())
	{
		cout << "Client: " << *it << " found." << endl;
	}
	else
	{
		cout << "Client: " << Person(f, s, l) << ", not found." << endl;
	}
	
}

list<Person>::iterator Clients::_find(std::string& f, std::string& s, std::string& l)
{
	Person p(f, s, l);

	auto it = clients.begin();

	it = find(it, clients.end(), p);
	return it;
}


void Clients::cons_remove()
{
	string f, s, l;
	cout << "Enter first name: ";
	cin.sync();
	getline(cin, f);
	cout << "Enter second name: ";
	cin.sync();
	getline(cin , s);
	cout << "Enter last name: ";
	cin.sync();
	getline(cin, l);
	auto it = _find(f, s, l);

	if(it != clients.end())
	{
		char ans = 0;
		cout << "Remove " << *it << " ? y/n ";
		cin >> ans;
		if(ans == 'y')
		{
			remove(it);
		}
		else
		{
			cout << "Remove cancel" << endl;
		}
	}
	else
	{
		cout << "No client with such name: " << Person(f, s, l) << endl;
	}

}

void Clients::remove(list<Person>::iterator& it)
{
	clients.erase(it);
}
