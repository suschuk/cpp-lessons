#ifndef BIND__H_
#define BIND__H_

#include <stack>
#include "Menu.h"
#include "Orders.h"
#include "Clients.h"

using namespace std;

class bind_
{
public:
	bind_(): clients(0), orders(0), cl_m(0), or_m(0), b_(0) {};
	bind_(Clients* cl, Orders* or, Menu<Clients>* cl_m, Menu<Orders>* or_m, Menu<bind_>* b) : clients(cl), orders(or), cl_m(cl_m), or_m(or_m), b_(b) 
	{
		st.push(b_);
	};

	void cl_add()
	{
		clients->cons_add();
	}
	void cl_remove()
	{
		clients->cons_remove();
	}
	void cl_find()
	{
		clients->cons_find();
	}
	void or_add()
	{
		orders->newOrder();
	}
	void or_showNew()
	{
		orders->showNewOrder();
	}
	void or_showSent()
	{
		orders->showSentOrder();
	}
	void or_review()
	{
		orders->reviewOrders();
	}
	void or_stat()
	{
		orders->statistic();
	}
	void cl_menu()
	{
		st.push(cl_m);
	}
	void or_menu()
	{
		st.push(or_m);
	}
	BaseMenu* top()
	{
		return st.top();
	}
	void pop()
	{
		st.pop();
	}
	bool isEmpty()
	{
		return st.empty();
	}
private:
	stack<BaseMenu*> st;
	Clients* clients;
	Orders* orders;
	Menu<Clients>* cl_m;
	Menu<Orders>* or_m;
	Menu<bind_>* b_;
};
#endif