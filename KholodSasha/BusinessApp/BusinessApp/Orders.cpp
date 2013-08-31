#include "Orders.h"
#include "Goods.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

int Orders::orderUnicID = 0;
std::vector<Orders::order> Orders::_ordersVec;

Orders::Orders(void)
{
}


Orders::~Orders(void)
{
}

int Orders::addOrder()
{
	order newOrder;
	system("cls");
	std::cout << "Choose goods, you are going to buy or press 'q' to return back:: " << std::endl << std::endl;
	Goods::print();
	char ch = 'r';
	int s;
	while (ch != 'q')
	{
		int goodsCount = 0;
		ch = _getch();
		s = atoi(&ch);
		if(!(s < 1 || s > Goods::getSize()))
		{
			newOrder.goods = s - 1;
			ch = 'q';
			orderUnicID++;
			newOrder.ID = orderUnicID;
			_ordersVec.push_back(newOrder);
			return orderUnicID;
		}		
	}
			
	//std::cout << "Error while creating order" << std::endl;
	return 0;
}
void Orders::removeOrder(int orderID)
{
	for(auto it = _ordersVec.begin(); it != _ordersVec.end(); ++it)
	{
		if(it->ID == orderID)
		_ordersVec.erase(it);
	}
}
void Orders::removeAllOrders()
{
	_ordersVec.clear();
}