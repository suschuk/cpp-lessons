#pragma once

#include <iostream>
#include <iomanip>

class Employee
{
private:

	char*  Name;
	int    ID;
	char*  Department;
	char*  Position;

public:
	Employee(void);
	Employee(const char* name, const int &id);
	Employee(const char* name, const int &id, const char* department, char* position);
	~Employee(void);

	void setName(char* name);
	void setID(int id);
	void setDepartment(char* department);
	void setPosition(char* position);

	char* getName();
	int	  getID();
	char* getDepartment();
	char* getPosition();

	void showEmployee();

};

