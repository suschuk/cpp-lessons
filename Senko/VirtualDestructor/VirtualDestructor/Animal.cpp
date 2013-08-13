#include "Animal.h"
#include <iostream>

Animal::Animal (char* n)
{
	int len = strlen(n);
	name = new char[len+1];
	strcpy_s(name, len+1, n);

	std::cout << "Animal constructor ..." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor  ..." << std::endl;

	delete []name;
}