#pragma once
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
private:
	char* name;
	int idNumber;
	char* department;
	char* position;
public:
	Employee(void);
	Employee(char*, int);
	Employee(char*, int, char*, char*);
	~Employee(void);

	void setName(char* name);
	void setIdNumber(int idNumber);
	void setDepartment(char* department);
	void setPosition(char* position);

	char* getName();
	int getIdNumber();
	char* getDepartment();
	char* getPosition();

	void showInfo();
};

#endif //_EMPLOYEE_H_