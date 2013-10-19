#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>

struct Person
{
	std::string fName;
	std::string sName;
	std::string lName;

	Person(): fName(0), sName(0), lName(0) {} ;
	Person(std::string& f, std::string& s, std::string& l) : fName(f), sName(s), lName(l) {} ;
	bool operator ==(const Person& p)
	{
		return (fName == p.fName && sName == p.sName && lName == p.lName) ? true : false;
	}
	friend std::ostream& operator<<(std::ostream&, Person&);
};
#endif