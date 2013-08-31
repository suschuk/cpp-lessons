#include "Menu.h"
#include <iostream>

Menu::Menu(MenuItem* menuItem, ...)
{
	MenuItem** pMI = &menuItem;
	while(*pMI)
	{
		menu.push_back(**pMI);
		pMI++;
	}
}

void Menu::show()
{
	for(int i = 0; i < menu.size(); ++i)
	{
		std::cout << i + 1<< ". ";
		menu[i].show();
	}
}
MenuItem* Menu::operator[] (int i)
{
	return &menu[i];
}
int Menu::size()
{
	return menu.size();
}
