#pragma once
#include <vector>
#include "ClientsDataBase.h"

class Orders
{
	friend class ClientsDataBase;
public:
	Orders(void);
	~Orders(void);

	static int addOrder();
	static void removeOrder(int orderID);
	static void removeAllOrders();
	struct order
	{
		int goods;
		int ID;
	};
private:
	
	static std::vector<order> _ordersVec;
	static int orderUnicID;
};

