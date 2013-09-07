#pragma once
#include "Client.h"
#include "Order.h"
#include "Item.h"
#include <vector>
#include <string>

class DataBase
{
public:
	DataBase(void);
	~DataBase(void);

	std::vector<Item>& Items();
	std::vector<Client>& Clients();
	std::vector<Order> & Orders();

private:
	std::vector<Item>   _items;
	std::vector<Client> _clients;
	std::vector<Order>  _orders;
};

