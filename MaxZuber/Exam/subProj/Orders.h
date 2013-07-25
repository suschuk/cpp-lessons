#ifndef ORDERS_H_
#define ORDERS_H_
#include "Goods.h"
#include <list>
#include "Order.h"
#include "Clients.h"

class Orders
{
public:
	void newOrder();

	void add(Order_Data&, Person&);
	void showNewOrder();
	void showSentOrder();
	void reviewOrders();
	void statistic();

private:
	void del(std::list<Order>::iterator&);
	void send(std::list<Order>::iterator&);

	std::list<Order> newOrders;
	std::list<Order> sentOrders;
	static Clients* DB;
};

#endif