#include<iostream>
#include"Employee.h"
using namespace std;

int main()
{
	Employee empl_1;
	empl_1.setName("Susan Meyers");
	empl_1.setIdNumber(47899);
	empl_1.setDepartment("Accounting");
	empl_1.setPosition("Vice President");

	Employee empl_2("Mark Jones", 39119);
	empl_2.setDepartment("IT");
	empl_2.setPosition("Programmer");

	Employee empl_3("Joy Rogers", 81774, "Manufacturing", "Engineer");

	cout << setw(16) << "Name" << " ";
	cout << setw(16) << "Id Number" << " ";
	cout << setw(16) << "Department" << " ";
	cout << setw(16) << "Position" << endl;
	cout << "-----------------------------------------------------------------------------"<< endl;
	empl_1.showInfo();
	empl_2.showInfo();
	empl_3.showInfo();

	return 0;
}