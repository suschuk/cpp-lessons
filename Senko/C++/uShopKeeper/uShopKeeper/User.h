#ifndef USER_H
#define USER_H

#include <string>

using std::string;

class User
{
public:
	User(): name(""), department(""), login(""), password("") {};
	User(string, string, string, string);
	string GetLogin();
	string GetPassword();
		
	void Print();

private:
	string name;
	string department;
	string login;
	string password;
};



#endif