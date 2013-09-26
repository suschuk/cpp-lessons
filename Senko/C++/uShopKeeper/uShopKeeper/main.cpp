#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "Product.h"
#include "helper.h"

using namespace std;

enum MAIN_MENU {ADMIN_PANEL = 1, OPERATIONS, EXIT};
enum ADM_MENU {ADD_USER = 1, ADD_PRODUCT, BACK};
enum OPERATIONS_MENU {PRICE_LIST = 1, BUY, SELL, OP_BACK};

int main ()
{
	// system users
	User admin("Test Admin", "IT", "admin", "1");
	User manager("Test Seller", "Sale", "sale", "2");
	vector<User> sysusers;
	sysusers.push_back(admin);
	sysusers.push_back(manager);

	//products
	Product laptop("Dell", 2000.0, "540 S", 10, 555);

	vector<Product> products;
	products.push_back(laptop);

	cout << "uShopKeeper v.1.0.23" << endl << endl;

	// authorization
	string login;
	string pass;
	bool flag = false;

	do
	{
		cout << "Login: ";
		cin >> login;

		cout << "Password: ";
		cin >> pass;

		flag = Login(sysusers, login, pass);

		if (!flag)
			cout << "Access denided!" << endl; 

	}while (!flag);

	int m_item = 0;

	while (m_item != EXIT)
	{
		m_item = MainMenu();
		if (m_item == EXIT)
			break;

		switch (m_item)
		{
		case ADMIN_PANEL:
			{
				int adm_item = AdminMenu();
				switch (adm_item)
				{
				case ADD_USER:
					{
						AddUser(sysusers);
					}
					break;
				case ADD_PRODUCT:
					{
						AddProduct(products);
					}
					break;
				case BACK:
					{
						m_item = MainMenu();
					}
					break;
				}
			}
			break;
		case OPERATIONS:
		{
			int op_item = OperationMenu();
			switch (op_item)
			{
			case PRICE_LIST:
				{
					PriceList(products);
				}
				break;
			case BUY:
				{
					BuyProduct(products);
				}
				break;
			case SELL:
				{
					SellProduct(products);
				}
				break;
			case OP_BACK:
				{
					m_item = MainMenu();
				}
				break;
			}		
		}
		break;
		case EXIT:
			exit(0);
			break;
		}
	}
	return 0;
}
