#ifndef LION_H
#define LION_H

#include "Animal.h"

class Lion : public Animal 
{
public:
	Lion (char* = " ", char* = " ");
	virtual ~Lion ();

private:
	char* voice;
};

#endif