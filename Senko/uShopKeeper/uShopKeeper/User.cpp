#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

User::User(string inName, string inDep, string inLogin, string inPass)
{
	name = inName;
	department = inDep;
	login = inLogin;
	password = inPass;
}

string User::GetLogin()
{
	return login;
}

string User::GetPassword()
{
	return password;
}

void User::Print()
{
	cout << name <<" " << department << " " << login << " " << password << endl; 
}

