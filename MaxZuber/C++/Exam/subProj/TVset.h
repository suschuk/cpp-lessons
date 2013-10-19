#ifndef TVSET_H_
#define TVSET_H_
#include "Goods.h"

class TVset: public Goods
{
public:

	TVset(): Goods() {};
	TVset(std::string& n, unsigned c) : Goods(n, c) {} ;
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