#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"

using namespace std;
vector<Menu> v;

void Add_new_client();
void Delete_client();
void Review_order();
void Exit_();

void main()
{
	
	v.push_back(Menu("#1 Add new client",Add_new_client));
	v.push_back(Menu("#2 Delete client",Delete_client));
	v.push_back(Menu("#3 Review order",Review_order));
	v.push_back(Menu("#4 Exit",Exit_));

	vector<Menu>::iterator i;
	for(i = v.begin();i != v.end(); ++i)
		(*i).Print();

	cout << "Enter your choice: " << endl;
	int choice;
	cin >> choice;

	if(choice > 0 && choice <= v.size())
	{
		v[choice-1].Work_function();
	}
	else
	{
		cout << "Incorect value!" << endl;
	}


	/*
	Menu f1("#1 Add new client",Add_new_client);
	Menu f2("#2 Delete client",Delete_client);
	Menu f3("#3 Review order",Review_order);
	Menu f4("#4 Exit",Exit_);
	*/
	
}

void Add_new_client()
{
	cout << "Work function \"Add_new_client()\"" << endl;
}

void Delete_client()
{
	cout << "Work function \"Delete_client()\"" << endl;
}

void Review_order()
{
	cout << "Work function \"Review_order()\"" << endl;
	v.push_back(Menu("#1 Show new orders",Add_new_client));
	v.push_back(Menu("#2 Show set orders",Add_new_client));
	v.push_back(Menu("#3 Show execution orders",Add_new_client));

	vector<Menu>::iterator i;
	for(i = v.begin(); i != v.begin() +3; ++i)
		(*i).Print();
}

void Exit_()
{
	cout << "Work function \"Exit()\"" << endl;
	exit(0);
}