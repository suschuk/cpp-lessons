#ifndef GOODS_H_
#define GOODS_H_
#include <string>
/*
*Base abstract class 
*/

class Goods
{
public:

	virtual unsigned getCount() =0;
	virtual std::string getName() = 0;
	Goods(): name_(""), count(0) {};
	Goods(std::string n, unsigned c) : name_(n), count(c) {} ;

protected:
	std::string name_;
	unsigned count;
};
#endif