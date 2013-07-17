#include <iostream>
#include <iomanip>
#include "Employee.h"

using namespace std;

Employee::Employee()
{
	this->name = new char[2];
	strcpy(this->name, " ");

	this->department = new char[2];
	strcpy(this->department, " ");

	this->position = new char[2];
	strcpy(this->position, " ");

	this->id = 0;
}

Employee::Employee(char* inName, int inId, char* inDepartment, char* inPosition)
{
	int lenName = strlen(inName);
	int lenDeparnment = strlen(inDepartment);
	int lenPosition = strlen(inPosition);

	this->name = new char[lenName+1];
	strcpy(this->name, inName);

	this->department = new char[lenDeparnment+1];
	strcpy(this->department, inDepartment);

	this->position = new char[lenPosition+1];
	strcpy(this->position, inPosition);

	this->id = inId;
}

Employee::Employee(char* inName, int inId)
{
	int lenName = strlen(inName);
	
	this->name = new char[lenName+1];
	strcpy(this->name, inName);

	this->id = inId;

	this->department = new char[2];
	strcpy(this->department, " ");

	this->position = new char[2];
	strcpy(this->position, " ");
}

void Employee::setName(char* inName)
{
	int lenName = strlen(inName);

	this->name = new char[lenName+1];
	strcpy(this->name, inName);
}

void Employee::setId(int inId)
{
	this->id = inId;
}

void Employee::setDepartment(char* inDepartment)
{
	int lenDeparnment = strlen(inDepartment);
	
	this->department = new char[lenDeparnment+1];
	strcpy(this->department, inDepartment);
}

void Employee::setPosition(char* inPosition)
{
	int lenPosition = strlen(inPosition);

	this->position = new char[lenPosition+1];
	strcpy(this->position, inPosition);
}

char* Employee::getName() const
{
	return this->name;
}

int Employee::getId() const
{
	return this->id;
}

char* Employee::getDepartment() const
{
	return this->department;
}

char* Employee::getPosition() const
{
	return this->position;
}

void Employee::printEmployeeCard()
{
	cout <<  setw(15) << this->name       << "|" <<
		     setw(6)  << this->id         << "|" << 
			 setw(15) << this->department << "|" <<  
			 setw(15) << this->position   << "|" << endl;
}

Employee::~Employee()
{
	delete []this->name;
	this->name = NULL;
	
	delete []this->department;
	this->department = NULL;

	delete []this->position;
	this->position = NULL;
}