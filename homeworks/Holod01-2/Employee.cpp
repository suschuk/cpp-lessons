#include "Employee.h"


Employee::Employee(void)
{
	name = new char[1];
	strcpy(this->name, "\0");
	idNumber = 0;
	department = new char[1];
	strcpy(this->department, "\0");
	position = new char[1];
	strcpy(this->position, "\0");
}
Employee::Employee(char* name, int idNumber)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->idNumber = idNumber;
	department = new char[1];
	strcpy(this->department, "\0");
	position = new char[1];
	strcpy(this->position, "\0");
}
Employee::Employee(char* name, int idNumber, char* department, char* position)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->idNumber = idNumber;

	this->department = new char[strlen(department) + 1];
	strcpy(this->department, department);

	this->position = new char[strlen(position) + 1];
	strcpy(this->position, position);
}

Employee::~Employee(void)
{
	delete name;
	name = NULL;
	delete department;
	department = NULL;
	delete position;
	position = NULL;
}

void Employee::setName(char* name)
{
	delete this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void  Employee::setIdNumber(int idNumber)
{
	this->idNumber = idNumber;
}
void  Employee::setDepartment(char* department)
{
	delete this->department;
	this->department = new char[strlen(department) + 1];
	strcpy(this->department, department);
}
void  Employee::setPosition(char* position)
{
	delete this->position;
	this->position = new char[strlen(position) + 1];
	strcpy(this->position, position);
}
char* Employee::getName()
{
	return name;
}
int Employee::getIdNumber()
{
	return idNumber;
}
char* Employee::getDepartment()
{
	return department;
}
char* Employee::getPosition()
{
	return position;
}
void Employee::showInfo()
{
	cout << setw(16) << name << " ";
	cout << setw(16) << idNumber << " ";
	cout << setw(16) << department << " ";
	cout << setw(16) << position << endl;
}
