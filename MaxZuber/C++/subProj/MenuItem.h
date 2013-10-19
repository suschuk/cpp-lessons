#pragma once

//#include <iostream>
#include <string>

class MenuItem
{
	friend std::ostream& operator << (std::ostream&, const MenuItem&);
public:
	MenuItem() : name_(0), command(0) {};
	MenuItem(std::string&, void(*)(void));
	void print() const;
	void cmd() const;
private:
	std::string name_;
	void (*command)(void);
};