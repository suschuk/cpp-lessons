#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "DataBase.h"
#include "MenuItem.h"

class Menu
{
public:
	Menu(std::string, DataBase&);

	void AddBranch(Menu);
	void AddItem(MenuItem);

	DataBase& Data();

	Menu& Branch(int);
	std::string Caption() const;

	void Run(); 
private:

	std::string _caption;
	std::vector<Menu> _branch;
	std::vector<MenuItem> _items;
	bool _isActive;

	DataBase &_dataBase;
};

