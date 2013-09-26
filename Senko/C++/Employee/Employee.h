#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
private:
	char* name;
	int id;
	char* department;
	char* position;
public:
	Employee();
	Employee(char* inName, int inId, char* inDepartment, char* inPosition);
	Employee(char* inName, int inId);
	
	void setName(char* inName);
	void setId(int inId);
	void setDepartment(char* inDepartment);
	void setPosition(char* inPosition);

	char* getName() const;
	int getId() const;
	char* getDepartment() const;
	char* getPosition() const;

	void printEmployeeCard();

	~Employee();
};

#endif