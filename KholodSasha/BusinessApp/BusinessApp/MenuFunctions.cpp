#include "MenuFunctions.h"
#include "ClientsDataBase.h"
#include "MenuItem.h"
#include "Menu.h"
#include <iostream>
#include <conio.h>

extern ClientsDataBase cdb;

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
	MenuItem DeleteOne(std::string("Delete One"), DeleteOneF);
	MenuItem DeleteAll(std::string("Delete All"), DeleteAllF);
	MenuItem Back(std::string("Back"), BackF);
	Menu menu(&DeleteOne, &DeleteAll, &Back, NULL);

	bool notExit = true;
	char ch;
	int input;

	do
	{
		system("cls");
		menu.show();
		ch = _getch();
		input = atoi(&ch);
		system("cls");
		if(!(input < 1 || input > menu.size()))
		{
			notExit = menu[input - 1]->run();
		}

	}while(notExit);

	return true;
}
bool BackF()
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

bool ReviewClientsWithOrdersF()
{
	cdb.showClientsWithOrders();
	return true;
}