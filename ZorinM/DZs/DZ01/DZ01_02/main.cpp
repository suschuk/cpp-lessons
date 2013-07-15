/*
4. Write a class named Employee that has the following member variables:
 - name. A string that holds the employee's name. 
 - idNumber. An int variable that holds the employee's ID number. 
 - department. A string that holds the name of the department where the employee works. 
 - position. A string that holds the employee's job title.

 The class should have the following constructors:
 - A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: employee's name, employee's ID number, department, and position. 
 - A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: employee's name and ID number. The department and position fields should be assigned an empty string (""). 
 - A default constructor that assigns empty strings ("") to the name, department, and position member variables, and 0 to the idNumber member variable.
Write appropriate mutator functions that store values in these member variables and accessor functions that return the values in these member variables. Once you have written the class, write a separate program that creates three Employee objects to hold the following data.
Name 	ID 	Number 	Department 	Position 
------------------------------------------------
Susan 	Meyers  47899 	Accounting 	Vice President 
Mark 	Jones   39119 	IT 		Programmer 
Joy 	Rogers  81774 	Manufacturing 	Engineer
The program should store this data in the three objects and then display the data for each employee on the screen.

// Tony Gaddis, p.791
*/
#include "Employee.h"
#include <iostream>
#include <iomanip>
using namespace std;

void main()
{
	const int AMOUNT = 3;
	Employee employees[AMOUNT] = { Employee(), 
								   Employee("Mark Jones", 39119), 
								   Employee("Joy Rogers", 81774, "Manufacturing", "Engineer")};

	employees[0].setName("Susan Meyers");
	employees[0].setIdNumber(47899);
	employees[0].setDepartment("Accounting");
	employees[0].setPosition("Vice President");

	employees[1].setDepartment("IT");
	employees[1].setPosition("Programmer");
	
	cout << left << setw(14) << "Name";
	cout << left << setw(12) << "ID Number";
	cout << left << setw(15) << "Department";
	cout << left << setw(15) << "Position";
	cout << endl;
	cout << right << setw(56) << setfill('-') << " " << endl << setfill(' ');

	for(int i = 0; i < AMOUNT; i++)
	{
		cout << left << setw(14) << employees[i].getName();
		cout << left << setw(12) << employees[i].getIdNumber();
		cout << left << setw(15) << employees[i].getDepartment();
		cout << left << setw(15) << employees[i].getPosition();
		cout << endl;
	}
}