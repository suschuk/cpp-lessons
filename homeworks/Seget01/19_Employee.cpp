#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
//#include <ctime>
//#include <cmath>
//#include <fstream>
//#include <Windows.h>
using namespace std;
#include "19_Date.h"
#include "19_Employee.h"
//----------------------------------------------------------------------------------------------
// Member functions	(Методы класса): Employee
//----------------------------------------------------------------------------------------------
// contructors					(конструкторы)
//----------------------------------------------------------
// default constructor			(конструктор по умолчанию)
Employee::Employee()
{
	cout << "default constructor" << endl;
	name = "";
	id_number = 0;
	department = "";
	position = "";
}
// 1 overloaded constructor		(перегруженный конструктор)
Employee::Employee( string name, int id_number, string department, string position )
{
	cout << "1 overloaded constructor" << endl;
	this->name = name;
	this->id_number = id_number;
	this->department = department;
	this->position = position;
}
// 2 overloaded constructor		(перегруженный конструктор)
Employee::Employee( string name, int id_number )
{
	cout << "2 overloaded constructor" << endl;
	this->name = name;
	this->id_number = id_number;
	this->department = "";
	this->position = "";
}
//----------------------------------------------------------
// setters						(mutator functions)
//----------------------------------------------------------
void Employee::setName( string name )
{
	this->name = name;
}
void Employee::setId_number( int id_number )
{
	this->id_number = id_number;
}
void Employee::setDepartment( string department )
{
	this->department = department;
}
void Employee::setPosition( string position )
{
	this->position = position;
}
void Employee::setEmployee( string name, int id_number, string department, string position )
{
	this->name = name;
	this->id_number = id_number;
	this->department = department;
	this->position = position;
}
//----------------------------------------------------------
// getters						(accessor functions)
//----------------------------------------------------------
string Employee::getName()
{
	return this->name;
}
int Employee::getId_number()
{
	return this->id_number;
}
string Employee::getDepartment()
{
	return this->department;
}
string Employee::getPosition()
{
	return this->position;
}
//----------------------------------------------------------
// user functions				(функции пользователя)
//----------------------------------------------------------
void Employee::showEmployees( Employee *employeeDB, int size )
{
	cout << setfill(' ');
	cout << setw(5)  << left << "#";
	cout << setw(15) << left << "Name";
	cout << setw(10) << left << "ID Number";
	cout << setw(15) << left << "Department";
	cout << setw(15) << left << "Position" << endl;
	cout << setfill('-') << setw(60) << "" << endl;
	cout << setfill(' ');

	for ( int i=0; i<size; i++ ) {
		if ( employeeDB[i].id_number > 0 ) {	// Проверяем на наличие данных (Если есть инф. ПЕЧАТАЕМ)
			cout << setw(5)  << left << i+1;
			cout << setw(15) << left << employeeDB[i].name;
			cout << setw(10) << left << employeeDB[i].id_number;
			cout << setw(15) << left << employeeDB[i].department;
			cout << setw(15) << left << employeeDB[i].position << endl;
		}
	}
	cout << endl;
}
//----------------------------------------------------------
// destructor					(деструктор)
//----------------------------------------------------------
Employee::~Employee()
{
	cout << "default constructor" << endl;
	name = "";
	id_number = 0;
	department = "";
	position = "";
}