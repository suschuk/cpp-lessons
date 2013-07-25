#include "MenuItem.h"
#include <iostream>
#include <string>
#include "Menu.h"
#include "Clients.h"
#include "Order.h"
#include "Orders.h"
#include <exception>
#include <stack>
#include <cstdlib>
#include "bind_.h"
using namespace std;




Clients clients;
Clients* Orders::DB = &clients; 


int main()
{	
	unsigned short ans;
	BaseMenu* bm = 0;
	Orders orders;
	Menu<Clients> cl_menu;
	Menu<Orders> or_menu;
	Menu<bind_> menu_main;

	bind_ b(&clients, &orders, &cl_menu, &or_menu, &menu_main);

	cl_menu += MenuItem<Clients>(string("1 - Add client"), &clients, &Clients::cons_add);
	cl_menu += MenuItem<Clients>(string("2 - Delete client"), &clients, &Clients::cons_remove);
	cl_menu += MenuItem<Clients>(string("3 - Find client\n... - Previous menu"), &clients, &Clients::cons_find);


	or_menu += MenuItem<Orders>(string("1 - Add new order"), &orders, &Orders::newOrder);
	or_menu += MenuItem<Orders>(string("2 - Show new orders"), &orders, &Orders::showNewOrder);
	or_menu += MenuItem<Orders>(string("3 - Show sent orders"), &orders, &Orders::showSentOrder);
	or_menu += MenuItem<Orders>(string("4 - Review orders\n... - Previous menu"), &orders, &Orders::reviewOrders);

	
	menu_main += MenuItem<bind_>(string("1 - Client menu"), &b, &bind_::cl_menu);
	menu_main += MenuItem<bind_>(string("2 - Order menu"), &b, &bind_::or_menu);
	menu_main += MenuItem<bind_>(string("3 - Statistic"), &b, &bind_::or_stat);
	menu_main += MenuItem<bind_>(string("4 - Exit"), &b, &bind_::pop);

	
	do 
	{
		b.top()->print();
		cin >> ans;
		--ans;
		try
		{
			system("CLS");
			(*b.top())[ans];
		}
		catch(length_error e)
		{
			b.pop();
		}
		
		system("PAUSE");
		system("CLS");
		
	} while (!b.isEmpty());

	return 0;
}



