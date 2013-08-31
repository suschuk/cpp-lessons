#include <iostream>
#include "Menu.h"
#include "MenuItem.h"
#include <Windows.h>
#include "ClientsDataBase.h"

using namespace std;

bool AddClientF();
bool ReviewClientsF();
bool DeleteClientF();
bool ExitF();

bool DeleteOneF();
bool DeleteAllF();

ClientsDataBase cdb;

int main()
{

	MenuItem AddClient(std::string("Add Client"),AddClientF);
	MenuItem ReviewClients(std::string("Review Clients"),ReviewClientsF);
	MenuItem DeleteClient(std::string("Delete Client"),DeleteClientF);
	MenuItem Exit(std::string("Exit"), ExitF);
	Menu menu(&AddClient, &ReviewClients, &DeleteClient, &Exit, NULL);

	bool notExit = true;
	int input;

	do
	{
		menu.show();
		cin >> input;
		system("cls");
		if(!(input < 1 || input > menu.size()))
		{
			notExit = menu[input - 1]->run();
		}

	}while(notExit);
	return 0;
}

bool AddClientF()
{
	cdb.addClient();
	return true;
}
bool ReviewClientsF()
{
	cdb.showClients();
	return true;
}
bool DeleteClientF()
{
	MenuItem DeleteOne(string("Delete One"), DeleteOneF);
	MenuItem DeleteAll(string("Delete All"), DeleteAllF);
	MenuItem Exit(std::string("Exit"), ExitF);
	Menu menu(&DeleteOne, &DeleteAll, &Exit, NULL);

	bool notExit = true;
	int input;

	do
	{
		menu.show();
		cin >> input;
		system("cls");
		if(!(input < 1 || input > menu.size()))
		{
			notExit = menu[input - 1]->run();
		}

	}while(notExit);

	return true;
}
bool ExitF()
{ 
	
	return false;
}
bool DeleteOneF()
{
	cdb.deleteClient();
	return true;
}
bool DeleteAllF()
{
	cdb.deleteAllClients();
	return true;
}