#include "Menu.h"

Menu::Menu(std::string caption, DataBase& dataBase):_caption(caption), _dataBase(dataBase){}

void Menu::AddBranch(Menu menu){ _branch.push_back(menu); }
void Menu::AddItem(MenuItem item){ _items.push_back(item); }

DataBase& Menu::Data(){ return _dataBase; }

Menu& Menu::Branch(int idx) { return _branch[idx]; }
std::string Menu::Caption()const { return _caption; }

void Menu::Run()
{
	_isActive = true;
	system("cls");
	while(true == _isActive)
	{
		std::string text = "<<< " + _caption + " >>>\r\n";

		if(!_branch.empty())
		{
			text += "--------------------\r\n";
		}

		unsigned i = 0;

		for(; i < _branch.size();++i)
		{
			text += "#" + std::to_string((long long)(i + 1)) + " " + _branch[i].Caption() + ">\r\n";
		}

		if(!_items.empty())
		{
			text += "--------------------\r\n";
		}

		for(; i < _branch.size() + _items.size(); ++i)
		{
			text += "#" + std::to_string((long long)(i + 1)) + " " + _items[i - _branch.size()].Caption() + "\r\n";
		}

		text += "--------------------\r\n#" + std::to_string((long long)(i + 1)) + " Back/Exit\r\n";

		std::cout << text << std::endl;

		unsigned cmd = 0;

		std::cin >> cmd;

		cmd--;
		if(cmd < _branch.size())
		{
			_branch[cmd].Run();
			system("cls");
		}
		else if(cmd < (_branch.size() + _items.size()) )		
		{
			_items[cmd - _branch.size()].Run(this->_dataBase);
		}
		else if(_branch.size() + _items.size() == cmd)
		{
			_isActive = false;
		}
		else
		{
			std::cout << " No menu item with # \'" << cmd + 1 << "\'\r\n";
		}
	}
}