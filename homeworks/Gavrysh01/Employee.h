#pragma once
#include <iostream>

class Employee
{
private:
	char *name;
	int idNumber;
	char *department;
	char *position;
public:
	Employee(void);
	Employee(char *name, int idNumber, char *department, char *position);
	Employee(char *name, int idNumber);
	~Employee(void);
	void setEmployee(char *name, int idNumber, char *department, char *position);
	char* getName ();
	int getIdNumber ();
	char* getDepartment ();
	char* getPosition();
};

