#include "Employee.h"


Employee::Employee(void)
{
	this->name=new char [1];
	strcpy(this->name,"");
	this->idNumber=0;
	this->department=new char [1];
	strcpy(this->department,"");
	this->position=new char [1];
	strcpy(this->position,"");
}


Employee::~Employee(void)
{
	delete [] this->name;
	delete [] this->department;
	delete [] this->position;
}


Employee::Employee(char *name, int idNumber, char *department, char *position)
{
	this->name=new char [strlen(name)+1];
	strcpy(this->name,name);
	this->idNumber=idNumber;
	this->department=new char [strlen(department)+1];
	strcpy(this->department,department);
	this->position=new char [strlen(position)+1];
	strcpy(this->position,position);
}


Employee::Employee(char *name, int idNumber)
{
	this->name=new char [strlen(name)+1];
	strcpy(this->name,name);
	this->idNumber=idNumber;
	this->department=new char [1];
	strcpy(this->department,"");
	this->position=new char [1];
	strcpy(this->position,"");
}


void Employee::setEmployee(char *name, int idNumber, char *department, char *position)
{
	Employee::~Employee();
	this->name=new char [strlen(name)+1];
	strcpy(this->name,name);
	this->idNumber=idNumber;
	this->department=new char [strlen(department)+1];
	strcpy(this->department,department);
	this->position=new char [strlen(position)+1];
	strcpy(this->position,position);
}


char* Employee::getName ()
{
	return this->name;
}


int Employee::getIdNumber ()
{
	return this->idNumber;
}


char* Employee::getDepartment ()
{
	return this->department;
}


char* Employee::getPosition()
{
	return this->position;
}