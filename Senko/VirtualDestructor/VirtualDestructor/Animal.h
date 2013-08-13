#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
public:
	Animal (char* = " ");
	virtual ~Animal()=0;

protected:
	char* name;
};

#endif