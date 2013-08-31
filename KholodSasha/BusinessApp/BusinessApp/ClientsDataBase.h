#pragma once
#include <vector>

class ClientsDataBase
{
public:
	ClientsDataBase(void);
	~ClientsDataBase(void);
	void addClient();
	static void showClients();
	static void showClientsWithOrders();
	void deleteClient();
	void deleteAllClients();
	struct client
	{
		char _firstName[16];
		char _lastName[16];
		int _orderID;
	};
private:
	
	static std::vector<client> _clVector;
};