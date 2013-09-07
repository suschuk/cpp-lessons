#include "Custom.h"

int FindClient(DataBase &dataBase, std::string name) 
{
	
	std::vector<Client>::iterator it = std::find_if(dataBase.Clients().begin(), dataBase.Clients().end(), [=](const Client& client) { return (0 == client.Name().compare(name)); });
	//not founded
	if(dataBase.Clients().end() == it) 
	{
		return -1;
	}
	return std::distance(dataBase.Clients().begin(), it);
}

int FindItem(DataBase &dataBase, std::string name) 
{
	
	std::vector<Item>::iterator it = std::find_if(dataBase.Items().begin(), dataBase.Items().end(), [=](const Item& item) { return (0 == item.Name().compare(name)); });
	//not founded
	if(dataBase.Items().end() == it) 
	{
		return -1;
	}
	return std::distance(dataBase.Items().begin(), it);
}

int FindOrder(DataBase &dataBase, std::string name) 
{
	
	std::vector<Client>::iterator it = std::find_if(dataBase.Clients().begin(), dataBase.Clients().end(), [=](const Client& client) { return (0 == client.Name().compare(name)); });
	//not founded
	if(dataBase.Clients().end() == it) 
	{
		return -1;
	}
	return std::distance(dataBase.Clients().begin(), it);
}

void AddClient(DataBase& dataBase)
{
	std::string name, mail, telNo;

	std::cout << "Enter name:"; std::cin >> name;
	std::cout << "Enter mail:"; std::cin >> mail;
	std::cout << "Enter Tel.:"; std::cin >> telNo;

	Client newClient(name,mail,telNo);
	dataBase.Clients().push_back(newClient);
}

void AddItem(DataBase& dataBase)
{
	std::string name;
	float price;

	std::cout << "Enter name: "; std::cin >> name;
	std::cout << "Enter price: "; std::cin >> price;

	Item newItem(name, price);
	dataBase.Items().push_back(newItem);
	dataBase.Items()[dataBase.Items().size() - 1].Quantity(1);
}

void RandomDataBase(DataBase& dataBase)
{
	std::string cNames[] = {"Harry","Alan","Benjamin","Frank","Max","Mike"};  //6
	std::string cSurnames[] = {"Morgan","Alda","Pirce","Burns","Hunnicat","Farrel"}; //6

	std::string iNames[] = {"Canon EOS","Nikon COOLPIX","Samsung Galaxy Tab","Apple iPad","HTC Wildfire","Apple iPhone","HP ProBook","Dell Optiplex","Sony PSP","Xbox360"};//10	

	srand((int)time(0));

	for(int i = 0; i < 20; ++i)
	{
		std::string name = cNames[rand() % 6] + " " + cSurnames[rand() % 6];
		std::string mail = name + "@boo.com";
		*std::find(mail.begin(),mail.end(),' ') = '.';
		std::string telNo;
		for(int j = 0; j < 8; ++j)
		{
			telNo += std::to_string((long double)(rand() % 10));
		}

		dataBase.Clients().push_back(Client(name,mail,telNo));
	}

	for(int i = 0; i < 10; ++i)
	{
		float price = (float)(rand() % 20000) / 100.0f + 100;

		dataBase.Items().push_back(Item(iNames[i],price));
		dataBase.Items()[i].Quantity(rand() % 50);
	}

	for(int i = 0; i < 15; ++i)
	{
		Order order(rand() % dataBase.Clients().size());

		int nItems = rand() % 20;

		for(int i = 0; i < nItems; ++i)
		{
			order.AddItem(rand() % dataBase.Items().size(), rand() % 10);
		}
	}
}

void ShowAllClients(DataBase& dataBase)
{
	std::cout << std::setw(3) << "#" << "|" << std::setw(25) << "Name" << "|" << std::setw(30) << "Mail" << "| " << "    TelNo" << std::endl;
	std::cout << "---+-------------------------+------------------------------+----------" << std::endl;

	for(unsigned i = 0; i < dataBase.Clients().size(); ++i)
	{
		std::cout << std::setw(3) << i + 1 << "|" << std::setw(25) << dataBase.Clients()[i].Name() << "|" << std::setw(30) << dataBase.Clients()[i].Mail() << "| " << dataBase.Clients()[i].TelNo() << std::endl;
	}

}

void ShowWarehouse(DataBase& dataBase)
{
	std::cout << std::setw(3) << "#" << "|" << std::setw(25) << "Name" << "|" << std::setw(10) << "Quantity" << "|" << std::setw(10) << "Price" << std::endl;
	std::cout << "---+-------------------------+----------+----------" << std::endl;

	for(unsigned i = 0; i < dataBase.Items().size(); ++i)
	{
		std::cout << std::setw(3) << i + 1 << "|" << std::setw(25) << dataBase.Items()[i].Name() << "|" << std::setw(10) << dataBase.Items()[i].Quantity() << "| " << std::setw(10) << dataBase.Items()[i].Price() <<"$"<< std::endl;
	}


}

void ShowAllOrders(DataBase& dataBase)
{
	std::cout << std::setw(3) << "#" << "|" << std::setw(25) << "Client name" << "|" << std::setw(12) << "Total price" << std::endl;
	std::cout << "---+-------------------------+-------------" << std::endl;

	for(unsigned i = 0; i < dataBase.Orders().size(); ++i)
	{
		float price = 0;

		for(unsigned j = 0; j < dataBase.Orders()[i].Items().size(); ++j)
		{
			price += dataBase.Orders()[i].Items()[j]._quantity * dataBase.Items()[dataBase.Orders()[i].Items()[j]._itemId].Price();
		}

		std::cout << std::setw(3) << i + 1 << "|" << std::setw(25) << dataBase.Clients()[dataBase.Orders()[i].GetClient()].Name() << "|" << std::setw(12) << price << std::endl;
	}
}

void ShowOrder(DataBase& dataBase)
{
	int idx = -1;

	std::cout << "Enter order #:";
	std::cin >> idx;

	idx --;

	if((idx >= 0 ) && (idx < dataBase.Orders().size()))
	{
		float price = 0;

		for(unsigned i = 0; i < dataBase.Orders()[idx].Items().size(); ++i)
		{
			price += dataBase.Orders()[idx].Items()[i]._quantity * dataBase.Items()[dataBase.Orders()[idx].Items()[i]._itemId].Price();
		}

		std::cout << "Client: " << dataBase.Clients()[dataBase.Orders()[idx].GetClient()].Name() << "      Total price: " << price << "$\r\n";

		std::cout << std::setw(3) << "#" << "|" << std::setw(25) << "Name" << "|" << std::setw(10) << "Quantity" << "|" << std::setw(10) << "Price" << std::endl;
		std::cout << "---+-------------------------+----------+----------" << std::endl;

		for(unsigned i = 0; i < dataBase.Orders()[idx].Items().size(); ++i)
		{
			std::cout << std::setw(3) << i + 1 << "|" << std::setw(25) << dataBase.Items()[dataBase.Orders()[idx].Items()[i]._itemId].Name() << "|" << std::setw(10) << dataBase.Orders()[idx].Items()[i]._quantity << "| " << std::setw(10) << dataBase.Orders()[idx].Items()[i]._quantity * dataBase.Items()[dataBase.Orders()[idx].Items()[i]._itemId].Price() <<"$"<< std::endl;
		}
	}
	else
	{
		std::cout << "No order #:" << idx;
	}
}

void AddOrder(DataBase& dataBase)
{
	int	idx = -1;
	std::string name;

	while(idx < 0)
	{
		name.clear();

		std::cout << "type \"help\" to show all clients\r\ntype \"exit\" to exit: " << std::endl;
		std::cout << "Enter client name: ";	

		while(name.empty())std::getline(std::cin,name);

		if(!name.compare("help"))
		{
			ShowAllClients(dataBase);
		}
		else if(!std::string(name).compare("exit"))
		{
			return;
		}
		else
		{
			idx = FindClient(dataBase, std::string(name));
			if(idx < 0)
			{
				std::cout << "No client with name: " << name << std::endl;
			}
		}		
	}

	Order newOrder(idx);
	bool done = false;

	idx = -1;

	while( (newOrder.Items().empty()) || (!done) )
	{
		while(idx < 0)
		{
			name.clear();

			std::cout << "type \"help\" to show all clients\r\ntype \"exit\" to exit: " << std::endl;
			std::cout << "Enter item name: ";	

			while(name.empty())std::getline(std::cin,name);

			if(!name.compare("help"))
			{
				ShowWarehouse(dataBase);
			}
			else if(!std::string(name).compare("exit"))
			{
				return;
			}
			else
			{
				idx = FindItem(dataBase,name);
				if(idx < 0)
				{
					std::cout << "No item with name: " << name << std::endl;
				}
			}		
		}

		std::cout << "Enter quantity: ";
		int quantity = 0;
		std::cin >> quantity;

		newOrder.AddItem(idx, quantity);		

		std::cout << "Confirm?\r\n #1 Yes\r\n #2 No: ";
		std::cin >> idx;

		if(1 == idx)
		{
			done = true;
		}

		idx = -1;
	}	

	dataBase.Orders().push_back(newOrder);
}

void SetQuantity(DataBase& dataBase)
{
	int	idx = -1;
	std::string name;

	while(idx < 0)
	{
		name.clear();

		std::cout << "type \"help\" to show all clients\r\ntype \"exit\" to exit: " << std::endl;
		std::cout << "Enter item name: ";	

		while(name.empty())std::getline(std::cin,name);

		if(!name.compare("help"))
		{
			ShowWarehouse(dataBase);
		}
		else if(!std::string(name).compare("exit"))
		{
			return;
		}
		else
		{
			idx = FindItem(dataBase,name);
			if(idx < 0)
			{
				std::cout << "No item with name: " << name << std::endl;
			}
		}		
	}

	int quantity = 0;

	std::cout << "Enter quantity:";
	std::cin >> quantity;

	dataBase.Items()[idx].Quantity(quantity);
}

void RemoveClient(DataBase& dataBase)
{
	int	idx = -1;
	std::string name;

	while(idx < 0)
	{
		name.clear();

		std::cout << "type \"help\" to show all clients\r\ntype \"exit\" to exit: " << std::endl;
		std::cout << "Enter client name: ";	

		while(name.empty())std::getline(std::cin,name);

		if(!name.compare("help"))
		{
			ShowAllClients(dataBase);
		}
		else if(!std::string(name).compare("exit"))
		{
			return;
		}
		else
		{
			idx = FindClient(dataBase, std::string(name));
			if(idx < 0)
			{
				std::cout << "No client with name: " << name << std::endl;
			}
		}		
	}

	int confirm = 0;

	std::cout << "Confirm?\r\n #1 Yes\r\n #2 No: ";
	std::cin >> confirm;

	if(confirm == 1)
	{
		unsigned i = 0;
		while(i++ < dataBase.Orders().size())
		{
			if(dataBase.Orders()[i].GetClient() == idx)
			{
				dataBase.Orders().erase(dataBase.Orders().begin() + i);
			}
		}
	}
}