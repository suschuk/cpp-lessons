#include<iostream>
#include "Menu.h"

void Menu::Print()
{
	std::cout << text_ << std::endl;
}

void Menu::Work_function()
{
	function_();
}
