#include "Employee.h"

using namespace std;

Employee::Employee(void)
{
	Name = "";
	ID = 0;
	Department = "";
	Position = "";
}

Employee::Employee(const char* name, const int &id)
{
	this->Name = new char[strlen(name) + 1];
	strcpy(this->Name, name);

	this->ID = id;

	Department = "";
	Position = "";
}

Employee::Employee(const char* name, const int &id, const char* department, char* position)
{
	this->Name = new char[strlen(name) + 1];
	strcpy(this->Name, name);

	this->ID = id;

	this->Department = new char[strlen(department) + 1];
	strcpy(this->Department, department);

	this->Position = new char[strlen(position) + 1];
	strcpy(this->Position, position);
}


Employee::~Employee(void)
{
delete [] this->Name;
this->Name = NULL;

delete [] this->Department;
this->Department = NULL;

delete [] this->Position;
this->Position = NULL;
}

void Employee::setName(char* name){

	this->Name = new char[strlen(name) + 1];
	strcpy(this->Name, name);

}

void Employee::setID(int id){

	this->ID = id;
}

void Employee::setDepartment(char* department){

	this->Department = new char[strlen(department) + 1];
	strcpy(this->Department, department);

}
void Employee::setPosition(char* position){

	this->Position = new char[strlen(position) + 1];
	strcpy(this->Position, position);

}

char* Employee::getName(){
	
	return this->Name;
}

int	  Employee::getID(){

	return this->ID;
}

char* Employee::getDepartment(){

	return this->Department;
}

char* Employee::getPosition(){

	return this->Position;
}

void Employee::showEmployee(){

	cout.setf(ios_base::right);
	cout << setw(7) << this->ID;

	cout.setf(ios_base::left);
	cout << setw(10) << this->Name << setw(10) << this->Department <<  setw(10) << this-> Position << endl;
}

