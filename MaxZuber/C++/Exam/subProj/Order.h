#ifndef ORDER_H_
#define ORDER_H_

#include <string>
#include <list>
#include "Person.h"
#include <iostream>

struct Order_Data
{
	std::string name_;
	unsigned count;
	unsigned price;

	Order_Data (): name_(""), count(0), price(0) {};
	Order_Data (std::string n, unsigned c, unsigned p): name_(n), count(c), price(p) {};
};

class Order
{
	friend std::ostream& operator<<(std::ostream&, Order&);
public:
	Order(): o_data(), who() {};
	Order(Order_Data& od,std::list<Person>::iterator& it) : o_data(od), who(it) {};
	void set_order(std::string& n, unsigned& count, unsigned& price, std::list<Person>::iterator& it);
private:
	Order_Data o_data;
	std::list<Person>::iterator who;
};


#endif