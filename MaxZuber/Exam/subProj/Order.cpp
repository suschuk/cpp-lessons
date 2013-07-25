#include "Order.h"

std::ostream& operator<<(std::ostream& out , Order& rhs)
{
	out << "Client: " << *rhs.who 
		<< "\nGoods: " << "\n    Name: " << rhs.o_data.name_ << "\n    Count: " << rhs.o_data.count 
		<< "\nPrice:  " << rhs.o_data.price << std::endl;
	return out;
}

void Order::set_order(std::string& n, unsigned& c , unsigned& p , std::list<Person>::iterator& it)
{
	o_data.name_ = n;
	o_data.count = c;
	o_data.price = p;
	who = it;
}