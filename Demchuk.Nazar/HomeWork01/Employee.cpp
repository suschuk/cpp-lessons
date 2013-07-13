# include <string.h>
# include "ClassEmployee.h"
using namespace std;

char* employee::get_name()
{
	return name;
}
int employee::get_id()
{
	return id;
}
char* employee::get_dep()
{
	return department;
}
char* employee::get_pos()
{
	return position;
}

void employee::set_name(char* tmp)
{
	if (name!=NULL)
		delete[] name;
	name=new char[sizeof(tmp)+1];
	strcpy(name, tmp);
}
void employee::set_id(int tmp)
{
	id=tmp;
}
void employee::set_dep(char* tmp)
{
	if (department!=NULL)
		delete[] department;
	department=new char[sizeof(tmp)+1];
	strcpy(department, tmp);
}
void employee::set_pos(char* tmp)
{
	if (position!=NULL)
		delete[] position;
	position=new char[sizeof(tmp)+1];
	strcpy(position, tmp);
}

employee::employee()
{
	name=NULL;
	id=0;
	department=NULL;
	position=NULL;
}
employee::employee(char* name, int id, char* dep, char* pos)
{
	this->id=id;

	this->name=new char[sizeof(name)+1];
	department=new char[sizeof(dep)+1];
	position=new char[sizeof(pos)+1];

	strcpy(this->name, name);
	strcpy(department, dep);
	strcpy(position, pos);
}
employee::employee(char* name, int id)
{
	this->id=id;

	this->name=new char[sizeof(name)+1];
	strcpy(this->name, name);

	department=NULL;
	position=NULL;
}
employee::~employee()
{
	if (name!=NULL)
	{
		delete[] name;
		name=NULL;
	}

	id=0;

	if (department!=NULL)
	{
		delete[] department;
		department=NULL;
	}
	if (position!=NULL)
	{
		delete[] position;
		position=NULL;
	}
}

void employee::fill_employee()
{
	char tname[100];
	cout<<"Enter name and surname of employee: ";
	cin>>tname;
	if (name!=NULL)
		delete[] name;
	name=new char[sizeof(tname)+1];
	strcpy(name, tname);

	cout<<"Enter ID of employee: ";
	cin>>id;

	char tdep[100];
	cout<<"Enter department of employee: ";
	cin>>tdep;
	if (department!=NULL)
		delete[] department;
	department=new char[sizeof(tdep)+1];
	strcpy(department, tdep);

	char tpos[100];
	cout<<"Enter position of employee: ";
	cin>>tpos;
	if (position!=NULL)
		delete[] position;
	position=new char[sizeof(tpos)+1];
	strcpy(position, tpos);
}
void employee::show_employee()
{
	cout<<name<<"\t"<<id<<"\t"<<department<<"\t"<<position<<endl;
}