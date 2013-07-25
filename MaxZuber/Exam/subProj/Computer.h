#ifndef COMPUTER_H_
#define  COMPUTER_H_
#include "Goods.h"

class Computer: public Goods
{
public:
	Computer(): Goods() {};
	Computer(std::string& n, unsigned c) : Goods(n, c) {} ;
	unsigned getCount()
	{
		return count;
	}
	std::string getName()
	{
		return name_;
	}
};


#endif