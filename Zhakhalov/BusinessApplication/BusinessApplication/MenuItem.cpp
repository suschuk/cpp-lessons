#include "MenuItem.h"


MenuItem::MenuItem(std::string caption, void(*func)(DataBase&)) : _func(func) , _caption(caption){}


MenuItem::~MenuItem(void)
{
}

std::string MenuItem::Caption()
{
	return _caption;
}

void MenuItem::Run(DataBase& dataBase)
{
	return _func(dataBase);
}
