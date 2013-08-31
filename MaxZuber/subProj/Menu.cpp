#include "Menu.h"
#include <exception>


void Menu::operator+=(MenuItem& mi )
{
	lst.push_back(mi);
}


void Menu::operator[](const short& num) const throw(std::length_error())
{
	if(num >= lst.size() || num < 0)
		throw std::length_error("Wrong index of menu");
	lst[num].cmd();
}



std::ostream& operator << (std::ostream& out, Menu& m)
{
	auto it = m.lst.begin();

	while(it != m.lst.end())
	{
		out << *it << std::endl;
		++it;
	}
	return out;
}
