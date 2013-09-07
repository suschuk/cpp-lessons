#include "Order.h"


Order::Order(int clientID) : _clientID(clientID)
{ }

Order::~Order(void)
{ _items.clear(); }

void Order::AddItem(int idx, int quantity)
{
	OrderItem item(idx, quantity);
	_items.push_back(item); 
}

void Order::RemoveItem(int idx)
{ _items.erase(_items.begin() + idx); }

void Order::SetStatus(Status status)
{ _status = status; }

Order::Status Order::GetStatus() const 
{ return _status; }

const int Order::GetClient() const
{
	return _clientID;
}

void Order::Quantity(int idx, int quantity)
{
	_items[idx]._quantity = quantity;
}

int Order::Quantity(int idx) const
{
	return _items[idx]._quantity;
}


std::vector<Order::OrderItem> Order::Items()
{
	return _items;
}

std::string Order::ToString() const
{
	return std::string();
}



