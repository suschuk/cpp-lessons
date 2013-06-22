#include <iostream>
#include "Employee.h"

using namespace std;

int main()
{
	Employee Susan("Susan Meyers", 47899, "Accounting", "Vice President");
	Employee Mark("Mark Jones", 39119, "IT", "Programmer");
	Employee Joy ("Joy Rogers", 81774, "Manufacturing", "Engineer");

	Susan.printEmployeeCard();
	Mark.printEmployeeCard();
	Joy.printEmployeeCard();

	return 0;
}