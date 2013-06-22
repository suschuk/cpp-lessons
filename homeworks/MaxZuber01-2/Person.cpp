#include <iostream>
#include <cstdlib>
#include "Person.h"

using namespace std;

Person::Person(char* name, int id, char* dep, char* posit)
{
	strcpy(this->name_, name);
	this->Id_ = id;
	strcpy(this->department_, dep);
	strcpy(this->position_, posit);
}
Person::Person(char* name, int id)
{
	strcpy(this->name_, name);
	this->Id_ = id;
	strcpy(this->department_, "");
	strcpy(this->position_, "");
}
Person::Person()
{
	strcpy(this->name_, "");
	this->Id_ = 0;
	strcpy(this->department_, "");
	strcpy(this->position_, "");
}

void Person::setName()
{
	fflush(stdin);
	cout << "\nEnter person name: ";
	gets_s(this->name_, 16);
}
void Person::setID()
{
	fflush(stdin);
	cout << "\nEnter " << name_ << ", ID: ";
	cin >> Id_;
}
void Person::setDepartment()
{
	fflush(stdin);
	cout << "\nEnter " << name_ << ", department: ";
	gets_s(this->department_, 20); 
}
void Person::setPosition()
{
	fflush(stdin);
	cout << "\nEnter " << name_ << ", position: ";
	gets_s(this->position_, 20);
}

const char* Person::getName() const
{
	return this->name_;
}
int Person::getID() const
{
	return this->Id_;
}
const char* Person::getDepartment() const
{
	return this->department_;
}
const char* Person::getPosition() const
{
	return this->position_;
}