#pragma once
#include <vector>
#include <string>
class Item
{
public:
	Item( std::string , float );

	void Quantity(int quantity);

	float Price() const;
	std::string Name() const;
	int Quantity() const;

private:
	int _quantity;
	float _price;
	std::string _name;

	int _idx;

};

