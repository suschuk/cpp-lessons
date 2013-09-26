#include "Animal.h"
#include "Lion.h"
#include <iostream>

int main ()
{
	Animal* A = new Lion("Lion ","R-R-R-R-R-R-R !!!!");

	delete A;

	return 0;
}
