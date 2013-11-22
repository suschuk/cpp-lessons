#include "ClientsDataBase.h"
#include <iostream>
#include "Orders.h"
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "Goods.h"

using namespace std;

std::vector<ClientsDataBase::client> ClientsDataBase::_clVector;

ClientsDataBase::ClientsDataBase(void)
{
}
ClientsDataBase::~ClientsDataBase(void)
{
}
void ClientsDataBase::addClient()
{
	system("cls");
	client newClient;
	cout << "Enter your first name: ";	
	cin >> newClient._firstName;
	cout << "Enter your last name: ";	
	cin >> newClient._lastName;
	newClient._orderID = Orders::addOrder();
	if(newClient._orderID)
	{
		_clVector.push_back(newClient);
		system("cls");
		std::cout << "\n\n\tClient added.";
		Sleep(1500);
	}
}
void ClientsDataBase::showClients()
{
	std::cout << "  #" << std::setw(16) << "First Name" << std::setw(16) << "Last Name" << std::endl;
	int i = 1;
	for(auto it = _clVector.begin(); it < _clVector.end(); ++it,++i)
	{
		std::cout << std::setw(3) << i << std::setw(16) << it->_firstName << std::setw(16) << it->_lastName << std::endl;
	}
	_getch();
}
void ClientsDataBase::deleteClient()
{
	showClients();
	std::cout << "Choose client you are going to delete: ";
	int c;
	std::cin >> c;
	auto it = _clVector.begin();
	int t = 1;
	for(;it != _clVector.end(); ++it)
	{
		if(t == c)
		{
			_clVector.erase(it);
			break;
		}
	}
	system("cls");
	std::cout << "\n\n\tClient deleted.";
	Sleep(1500);
}

void ClientsDataBase::deleteAllClients()
{
	_clVector.clear();
	Orders::removeAllOrders();
}

void ClientsDataBase::showClientsWithOrders()
{
	system("cls");
	std::cout << "  #" << std::setw(16) << "Name" << std::setw(16) << "Brand" << std::setw(16) << "Model" << std::setw(8) << "Price" << std::endl;
	int i = 0;
	for(auto it = _clVector.begin(); it < _clVector.end(); ++it,++i)
	{
		std::cout << std::setw(3) << i+1 << std::setw(16) << it->_firstName << std::endl << std::setw(19) << it->_lastName;
		
		std::cout << std::setw(16) << Goods::goodsVec[Orders::_ordersVec[i].goods]._brand;
		std::cout << std::setw(16) << Goods::goodsVec[Orders::_ordersVec[i].goods]._model;
		std::cout << std::setw(8) << Goods::goodsVec[Orders::_ordersVec[i].goods]._price << " $";
		std::cout << std::endl;
	}
	_getch();
}
