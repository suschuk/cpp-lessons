#include "Employee.h"
#include <cstring>

#pragma warning( disable : 4996 )

Employee::Employee()
{
	name = new char[1];
	strcpy(name, "");
	idNumber = 0;
	department = new char[1];
	strcpy(department, "");
	position = new char[1];
	strcpy(position, "");
}

Employee::Employee(char* n, int id)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	idNumber = id;
	department = new char[1];
	strcpy(department, "");
	position = new char[1];
	strcpy(position, "");
}

Employee::Employee(char* n, int id, char* dep, char* pos)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	idNumber = id;
	department = new char[strlen(dep) + 1];
	strcpy(department, dep);
	position = new char[strlen(pos) + 1];
	strcpy(position, pos);
}

Employee::~Employee()
{
	delete[] name;
	name = NULL;
	delete[] department;
	department = NULL;
	delete[] position;
	position = NULL;
}

// mutator functions
void Employee::setName(char* n)
{
	// якщо строка не пуста - очистити
	if(name != NULL)
		delete[] name;

	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

void Employee::setIdNumber(int id)
{
	idNumber = id;
}

void Employee::setDepartment(char* dep)
{
	// якщо строка не пуста - очистити
	if(department != NULL)
		delete[] department;

	department = new char[strlen(dep) + 1];
	strcpy(department, dep);
}

void Employee::setPosition(char* pos)
{
	// якщо строка не пуста - очистити
	if(position != NULL)
		delete[] position;

	position = new char[strlen(pos) + 1];
	strcpy(position, pos);
}

#pragma warning( default : 4996 )