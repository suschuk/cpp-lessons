#pragma once
#include <vector>

class Order
{
public:

	enum Status{InPogress = 0, Confirmed};

	struct OrderItem
	{
		int _itemId;
		int _quantity;	

		OrderItem(int itemId, int quantity) : _itemId(itemId), _quantity(quantity){}
	};

	Order(int client);
	~Order(void);

	void AddItem(int idx, int quantity);
	void RemoveItem(int);

	void SetStatus(Status);
	Status GetStatus() const;

	void Quantity(int idx, int quantity);
	int Quantity(int idx) const;

	const int GetClient() const;
	std::vector<OrderItem> Items();

	std::string ToString() const;

private:	

	int _clientID; //dataBase.Clients()[_client]
	std::vector<OrderItem> _items;
	Status _status;	

	int _idx;
};

