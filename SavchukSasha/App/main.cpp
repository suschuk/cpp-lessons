#include <iostream>
#include <conio.h>
#include "Menu.h"
#include "MenuItem.h"
#include <Windows.h>
#include "ClientsDataBase.h"
#include "MenuFunctions.h"
#include "Goods.h"
#include "Orders.h"

using namespace std;

ClientsDataBase cdb;
Goods gds;
Orders ord;

int main()
{

	MenuItem AddClient(std::string("Add Client"),AddClientF);
	MenuItem ReviewClients(std::string("Review Clients"),ReviewClientsF);
	MenuItem ReviewClientsWithOrders(std::string("ReviewClientsWithOrders"), ReviewClientsWithOrdersF);
	MenuItem DeleteClient(std::string("Delete Client"),DeleteClientF);
	MenuItem Exit(std::string("Exit"), BackF);
	Menu menu(&AddClient, &ReviewClients, &ReviewClientsWithOrders, &DeleteClient, &Exit, NULL);

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
	return 0;
}