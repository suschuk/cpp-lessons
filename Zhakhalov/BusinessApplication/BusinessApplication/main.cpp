#include "Menu.h"
#include "Custom.h"

void main()
{
	DataBase dataBase;

	Menu mainMenu("Main Menu",dataBase);
	mainMenu.AddBranch(Menu("Clients",mainMenu.Data()));
	mainMenu.AddBranch(Menu("Warehouse",mainMenu.Data()));
	mainMenu.AddBranch(Menu("Orders",mainMenu.Data()));

	mainMenu.Branch(0).AddBranch(Menu("Show",mainMenu.Data()));
	mainMenu.Branch(0).AddItem(MenuItem("Add new client",AddClient));
	mainMenu.Branch(0).Branch(0).AddItem(MenuItem("Show all",ShowAllClients));

	mainMenu.Branch(1).AddBranch(Menu("Show",mainMenu.Data()));
	mainMenu.Branch(1).AddItem(MenuItem("Add Item", AddItem));
	mainMenu.Branch(1).AddItem(MenuItem("Set quantity",SetQuantity));
	mainMenu.Branch(1).Branch(0).AddItem(MenuItem("Show all",ShowWarehouse));

	mainMenu.Branch(2).AddBranch(Menu("Show",mainMenu.Data()));
	mainMenu.Branch(2).Branch(0).AddItem(MenuItem("Show all orders",ShowAllOrders));
	mainMenu.Branch(2).Branch(0).AddItem(MenuItem("Details",ShowOrder));
	mainMenu.Branch(2).AddItem(MenuItem("Add Order",AddOrder));	

	RandomDataBase(dataBase);

	mainMenu.Run();
}