#include "MenuItem.h"
#include <iostream>

MenuItem::MenuItem(std::string itemName, PFUNC pFunc) : itemName_(itemName), pFunc_(pFunc)
{
}


void MenuItem::show()
{
	std::cout << itemName_ << std::endl;
}

bool MenuItem::run()
{
	return pFunc_();
}
