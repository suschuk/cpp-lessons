#ifndef SHOP_H
#define SHOP_H

#include <string>
#include "Product.h"

using std::string;

class Shop
{
public:
	Shop(): pr(), amount(0) {};
	Shop(string, double, string);
	

private:
	Product pr;
	int amount;
};

#endif