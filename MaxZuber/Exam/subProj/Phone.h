#ifndef PHONE_H_
#define  PHONE_H_
#include "Goods.h"


class Phone: public Goods
{
public:
	Phone(): Goods() {};
	Phone(std::string& n, unsigned c) : Goods(n, c) {} ;
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