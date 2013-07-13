# include <iostream>

#ifndef CLASSEMPLOYEE_H_
#define CLASSEMPLOYEE_H_

class employee
{
private:
	char* name;
	unsigned int id;
	char* department;
	char* position;
public:
	char* get_name();
	int get_id();
	char* get_dep() ;
	char* get_pos() ;

	void set_name(char* tmp);
	void set_id(int tmp);
	void set_dep(char* tmp);
	void set_pos(char* tmp);


	employee();
	employee(char* name, int id, char* dep, char* pos);
	employee(char* name, int id);
	~employee();

	void fill_employee();
	void show_employee();
};

#endif