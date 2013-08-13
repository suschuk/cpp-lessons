#include "Animal.h"
#include "Lion.h"
#include <iostream>

Lion::Lion (char* n, char* v) : Animal(n)
{
	int len = strlen(v);
	voice = new char[len+1];
	strcpy_s(voice, len+1, v);

	std::cout << "Lion constructor ..." << std::endl;
}
Lion::~Lion ()
{
	std::cout << "Lion destructor  ..." << std::endl;

	delete []voice;
}
