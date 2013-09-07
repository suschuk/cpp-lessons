#pragma once
#include <string>
#include "DataBase.h"

class MenuItem
{
public:
	MenuItem(std::string , void(*_func)(DataBase&));
	~MenuItem(void);

	std::string Caption();
	void Run(DataBase&);
private:
	std::string _caption;
	void(*_func)(DataBase&);
};

