#include "helper.h"
#include <iostream>

using namespace std;

bool Login(vector<User> inUsers, string inLogin, string inPass)
{
	for (vector<User>::iterator it = inUsers.begin() ; it != inUsers.end(); ++it)
		{
			if ( (it->GetLogin() == inLogin) && (it->GetPassword() == inPass) )
				return true;
		}
	return false;
}

int MainMenu()
{
	system ("cls");
	cout << "[1] Admin Panel " << endl;
	cout << "[2] Operation " << endl;
	cout << "[3] Exit " << endl;

	int item = 0;
	bool flag = false;

	while (flag == false)
	{
		cin >> item;

		if ((item < 1) || (item > 3))
			cout << "Incorrect menu item! Enter one more time." << endl;
		else
			flag = true;
	} 

	return item;
}

int AdminMenu()
{
	system ("cls");
	cout << "[1] Add user" << endl;
	cout << "[2] Add product" << endl;
	cout << "[3] Back" << endl;

	int item = 0;
	bool flag = false;

	while (flag == false)
	{
		cin >> item;

		if ((item < 1) || (item > 3))
			cout << "Incorrect menu item! Enter one more time." << endl;
		else
			flag = true;
	} 

	return item;
}

int OperationMenu()
{
	system ("cls");
	cout << "[1] Price list " << endl;
	cout << "[2] Buy " << endl;
	cout << "[3] Sell " << endl;
	cout << "[4] Back " << endl;

	int item = 0;
	bool flag = false;

	while (flag == false)
	{
		cin >> item;

		if ((item < 1) || (item > 4))
			cout << "Incorrect menu item! Enter one more time." << endl;
		else
			flag = true;
	} 

	return item;
}

void AddUser(vector<User>& inUsers)
{
	string inName, inDep, inLogin, inPass;

	cout << "Name: " << endl;
	cin >> inName;

	cout << "Department: " << endl;
	cin >> inDep;

	cout << "Login: " << endl;
	cin >> inLogin;

	cout << "Password: " << endl;
	cin >> inPass;

	User tmp(inName, inDep, inLogin, inPass);

	inUsers.push_back(tmp);	
}

void PriceList(vector<Product>& inProducts )
{
	cout << "ID \tName \tModel \tPrice \tAmount" << endl;
	for (vector<Product>::iterator it = inProducts.begin() ; it != inProducts.end(); ++it)
		{
			cout << it->GetID() << "\t" << it->GetName() << "\t" << it->GetModel() << "\t" << it->GetPrice() << " $ \t" << it->GetAmount() << " \t"<< endl;
		}

	cout << endl << "Press 0 to return to main menu... " << endl;

	int i = -1;

	while (i != 0)
	{
		cin >> i;
	}
}

void AddProduct(vector<Product>& inProducts)
{
	string inName, inModel;
	double inPrice;
	unsigned inAmount, inID;

	cout << "Name: " << endl;
	cin >> inName;

	cout << "Model: " << endl;
	cin >> inModel;

	cout << "Price: " << endl;
	cin >> inPrice;

	cout << "Amount: " << endl;
	cin >> inAmount;

	cout << "ID: " << endl;
	cin >> inID;

	Product tmp(inName, inPrice, inModel, inAmount, inID);

	inProducts.push_back(tmp);	
}

void BuyProduct(vector<Product>& inProducts)
{
	unsigned inID = 0;

	cout << "Enter productID :" << endl;
	cin >> inID;
	
	int i = 0;

	bool flag = false;

	for (vector<Product>::iterator it = inProducts.begin() ; it != inProducts.end(); ++it)
		{
			i++;
			if (it->GetID() == inID)
			{
				flag = true;
				break;
			}
		}
	i--;

	if (flag == true)
	{
		cout << "ID: " << inProducts[i].GetID() << endl;
		cout << "Name: " << inProducts[i].GetName() << endl;
		cout << "Model: " << inProducts[i].GetModel() << endl;
		cout << "Price: " << inProducts[i].GetPrice() << endl;
		cout << "Amount: " << inProducts[i].GetAmount() << endl;

		unsigned amnt = 0;

		while (amnt < 1) 
		{
			cout << " Product buying... Input amount: " << endl;
			cin >> amnt;

			if (amnt < 1)
				cout << "Incorrect amount" << endl;
		}

		unsigned newAmount = inProducts[i].GetAmount() + amnt;

		inProducts[i].SetAmount(newAmount);
	}
	else
	{
		cout << "Product not found !";
	}
}

void SellProduct(vector<Product>& inProducts)
{
	unsigned inID = 0;

	cout << "Enter productID :" << endl;
	cin >> inID;
	
	int i = 0;

	bool flag = false;

	for (vector<Product>::iterator it = inProducts.begin() ; it != inProducts.end(); ++it)
		{
			i++;
			if (it->GetID() == inID)
			{
				flag = true;
				break;
			}
		}
	i--;

	if (flag == true)
	{
		cout << "ID: " << inProducts[i].GetID() << endl;
		cout << "Name: " << inProducts[i].GetName() << endl;
		cout << "Model: " << inProducts[i].GetModel() << endl;
		cout << "Price: " << inProducts[i].GetPrice() << endl;
		cout << "Amount: " << inProducts[i].GetAmount() << endl;

		unsigned amnt = 0;

		while ((amnt < 1) || (amnt > inProducts[i].GetAmount()))
		{
			cout << " Product selling... Input amount: " << endl;
			cin >> amnt;

			if ((amnt < 1) || (amnt > inProducts[i].GetAmount()))
				cout << "Incorrect amount" << endl;
		}

		unsigned newAmount = inProducts[i].GetAmount() - amnt;

		inProducts[i].SetAmount(newAmount);
	}
	else
	{
		cout << "Product not found !";
	}
}
