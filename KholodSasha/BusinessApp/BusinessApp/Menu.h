#pragma once
#include "MenuItem.h"
#include <vector>
class Menu
{
public:
	Menu(MenuItem* menuItem, ...);
	void show();
	MenuItem* operator[] (int i);
	int size();
private:
	std::vector<MenuItem> menu;
};