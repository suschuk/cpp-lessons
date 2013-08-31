#include <iostream>
#include <vector>
#include <string>

class Menu
{
public:
	Menu(int ifmain)
	{
		if(!ifmain)
			fillMainMenu();
	}

	void select(int n) 
	{
		fillSubmenu(n);
		showSubmenu(n);
	}
private:
	char name[15];
	typedef std::vector<Menu> subMenu;

	std::vector <subMenu> mainMenu;
	
	void fillMainMenu()
	{
		subMenu clients;
		subMenu orders;
		mainMenu.push_back(clients);
		mainMenu.push_back(orders);
		std::cout << "1. Clients" << std::endl; 
		std::cout << "2. Orders" << std::endl; 
		std::cout << "3. Exit" << std::endl; 
	}

	void fillSubmenu(int n)
	{
		for(int i = 1; i < 10; ++i)
		{
			Menu a(0);
			itoa(i, a.name, 10);
			mainMenu[n].push_back(a);
		}
	}

	void showSubmenu(int n) const
	{
		system("cls");
		for(auto i = mainMenu[n].begin(); i != mainMenu[n].end(); i++)
		{
            std::cout <<  i->name << std::endl;
		}
	}
};

