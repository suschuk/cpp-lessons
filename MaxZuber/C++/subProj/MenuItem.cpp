#include "MenuItem.h"
#include <iostream>

MenuItem::MenuItem(std::string& s, void(*f)(void))
{
	name_ = s;
	command = f;
}
void MenuItem::print() const
{
	std::cout << name_ << std::endl;
}
void MenuItem::cmd() const
{
	command();
}

std::ostream& operator << (std::ostream& out, const MenuItem& mi) 
{
	out << mi.name_ << std::endl;
	return out;
}