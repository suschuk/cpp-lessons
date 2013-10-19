#ifndef CLIENTS_H_
#define CLIENTS_H_
#include <string>
#include <list>

#include "Person.h"


class Clients
{

	friend std::ostream& operator<<(std::ostream&, Clients&);
public:
	Clients(): clients() {};
	Clients(std::string& f, std::string& s, std::string& l)
	{
		clients.push_back(Person(f, s, l));
	};

	//console method
#ifdef _DEBUG
	void cons_add();
	void cons_remove();
	void cons_find();
#endif

	void add(std::string& f, std::string& s, std::string& l);
	void remove(std::list<Person>::iterator&);
	std::list<Person>::iterator _find(std::string& f, std::string& s, std::string& l); // first of
	std::list<Person>::iterator last_in_list() 
	{
		return clients.end();
	}
private:

	std::list<Person> clients;
};

#endif