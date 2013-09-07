#include "DataBase.h"


DataBase::DataBase(void)
{
}


DataBase::~DataBase(void)
{
}

std::vector<Item>& DataBase::Items(){ return _items; }
std::vector<Client>& DataBase::Clients(){return _clients;}
std::vector<Order>& DataBase::Orders(){ return _orders;}
