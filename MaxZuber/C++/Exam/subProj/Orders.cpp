#include <iostream>
#include <cstdlib>
#include "Orders.h"
#include "Order.h"
#include "Person.h"

using namespace std;


void Orders::newOrder()
{
	Order_Data od;
	cout << "Enter goods name: ";
	cin.sync();
	getline(cin, od.name_);
	cout << "Enter count: ";
	cin.sync();
	cin >> od.count;
	cout << "Enter price per one: ";
	cin.sync();
	cin >> od.price;
	od.price *= od.count;


	string f, s, l;
	cout << "Enter first name: ";
	cin.sync();
	getline(cin, f);
	cout << "Enter second name: ";
	cin.sync();
	getline(cin , s);
	cout << "Enter last name: ";
	cin.sync();
	getline(cin, l);

	add(od, Person(f, s, l));
}

void Orders::add(Order_Data& od, Person& p)
{
	auto it = DB->_find(p.fName, p.sName, p.lName);

	if(it == DB->last_in_list())
	{
		DB->add(p.fName, p.sName, p.lName);
		it = DB->last_in_list();
		--it;
		newOrders.push_back(Order(od, it));
	}
	else
	{
		newOrders.push_back(Order(od,it));
	}
}

void Orders::showNewOrder()
{
	if(newOrders.empty())
	{
		cout << "\nOrder list is empty" << endl;
		return;
	}
	auto it = newOrders.begin();

	while(it != newOrders.end())
	{
		cout << *it << endl;
		++it;
	}
}
void Orders::showSentOrder()
{
	if(sentOrders.empty())
	{
		cout << "\nSent order list is empty" << endl;
		return;
	}
	auto it = sentOrders.begin();

	while(it != sentOrders.end())
	{
		cout << *it << endl;
		++it;
	}
}

void Orders::reviewOrders()
{
	if(newOrders.empty())
	{
		cout << "No order's to review" << endl;
		return;
	}
	auto it = newOrders.begin();
	auto next= it;

	

	while(it != newOrders.end())
	{
		system("CLS");
		short ans = 0;
		cout << *it << endl;
		cout << endl << "Choose action:\n";
		cout << "1 - Delete Order    "
			<< "2 - Send order    "
			<< "... - Continue\n";
		cin >> ans;
		next = it;
		++next;
		switch(ans)
		{
		case 1:
			del(it);
			break;
		case 2:
			send(it);
			break;
		default:
			break;
		}
		it = next;
	}
}

void Orders::del(std::list<Order>::iterator& it)
{
	newOrders.erase(it);
}
void Orders::send(std::list<Order>::iterator& it)
{
	sentOrders.push_back(*it);
	del(it);
}
void Orders::statistic()
{
	cout << "New orders: " << newOrders.size();
	cout << "\nSent orders: " << sentOrders.size() << endl;
}