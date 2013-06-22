#pragma once
#ifndef PERSON_H_
#define PERSON_H_

class Person 
{
private:
	char name_[16];
	int Id_;
	char department_[20];
	char position_[20];
public:
	Person(char* name, int id, char* dep, char* posit);
	Person(char* name, int id);
	Person();

	void setName();
	void setID();
	void setDepartment();
	void setPosition();

	const char* getName() const;
	int getID() const;
	const char* getDepartment() const;
	const char* getPosition() const;

};
#endif