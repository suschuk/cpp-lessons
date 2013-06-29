//1. –азработать класс Date дл€ представлени€ даты (день, мес€ц, год). 
//–еализовать методы дл€ доступа к пол€м (с контролем допустимости аргументов!). ќпределить конструктор с параметрами дл€ удобного пользовани€ классом, методы считывани€ даты с клавиатуры и печати ее на экране. 
//2. ƒоработать разработанный ранее класс Date, определив в нем конструктор по умолчанию, создающий Ђдату по умолчаниюї (например, 1970/01/01).
//
//3. Design a class called Date. The class should store a date in three integers: month, day, and year. There should be member functions to print the date in the following forms:
//12/25/2012 December 25, 2012 25 December 2012
//Demonstrate the class by writing a complete program implementing it.
//Input Validation: Do not accept values for the day greater than 31 or less than 1. Do not accept values for the month greater than 12 or less than 1. 
//
//4. Write a class named Employee that has the following member variables:
// - name. A string that holds the employee's name. 
// - idNumber. An int variable that holds the employee's ID number. 
// - department. A string that holds the name of the department where the employee works. 
// - position. A string that holds the employee's job title.
//The class should have the following constructors:
// - A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: employee's name, employee's ID number, department, and position. 
// - A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: employee's name and ID number. The department and position fields should be assigned an empty string (""). 
// - A default constructor that assigns empty strings ("") to the name, department, and position member variables, and 0 to the idNumber member variable.
//Write appropriate mutator functions that store values in these member variables and accessor functions that return the values in these member variables. Once you have written the class, write a separate program that creates three Employee objects to hold the following data.
//Name 	ID 	Number 	Department 	Position 
//------------------------------------------------
//Susan 	Meyers  47899 	Accounting 	Vice President 
//Mark 	Jones   39119 	IT 		Programmer 
//Joy 	Rogers  81774 	Manufacturing 	Engineer
//The program should store this data in the three objects and then display the data for each employee on the screen.

// Tony Gaddis, p.791



#include <iostream>
#include <iomanip>
#include "date.h"
#include "Employee.h"

using namespace std;

int main()
{
	date currentdate(6,6,2013);
	currentdate.printDate(" / ");
    currentdate.setDate();

	Employee Susan;
	Employee Mark("Mark Jones",39119, "IT", "Programmer");
	Employee Joy("Joy Rogers", 81774, "Manufacturing", "Engineer");

	Susan.setEmployee("Susan Meyers", 47899, "Accounting", "Vice President");

	cout << setw(20) << left << "Name" << setw(20) << left << "ID Number";
	cout << setw(20) << left << "Department" << setw(20) << left << "Position"; 

	cout << setw(20) << left << Susan.getName();
	cout << setw(20) << left << Susan.getIdNumber();
	cout << setw(20) << left << Susan.getDepartment();
	cout << setw(20) << left << Susan.getPosition();

	cout << setw(20) << left << Mark.getName();
	cout << setw(20) << left << Mark.getIdNumber();
	cout << setw(20) << left << Mark.getDepartment();
	cout << setw(20) << left << Mark.getPosition();

	cout << setw(20) << left << Joy.getName();
	cout << setw(20) << left << Joy.getIdNumber();
	cout << setw(20) << left << Joy.getDepartment();
	cout << setw(20) << left << Joy.getPosition();

	system("pause");
	return 0;
}