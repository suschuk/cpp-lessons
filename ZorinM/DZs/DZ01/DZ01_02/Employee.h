#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
private:
	char* name;
	int idNumber;
	char* department;
	char* position;
public:
	Employee();		
	Employee(char*, int);		
	Employee(char*, int, char*, char*);
	~Employee();

	// mutator functions prototypes
	void setName(char*);
	void setIdNumber(int);
	void setDepartment(char*);
	void setPosition(char*);

	// accessor functions
	const char* getName() const
	{	return name;	}

	int getIdNumber() const
	{	return idNumber;	}

	const char* getDepartment() const
	{	return department;	}

	const char* getPosition() const
	{	return position;	}

};

#endif