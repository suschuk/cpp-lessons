#pragma once
#include <string>
typedef bool (*PFUNC)(void);

class MenuItem
{
public:
	MenuItem(std::string itemName, PFUNC pFunc);
	void show();
	bool run();
private:
	std::string itemName_;
	PFUNC pFunc_;
};

