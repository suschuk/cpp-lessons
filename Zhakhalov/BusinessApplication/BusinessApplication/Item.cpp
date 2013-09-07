#include "Item.h"


Item::Item( std::string name, float price):_name(name), _price(price)
{
}



float Item::Price() const{ return _price; }

std::string Item::Name() const{ return _name; }

void Item::Quantity(int quantity) { _quantity = quantity; }
int Item::Quantity() const{ return _quantity; }
