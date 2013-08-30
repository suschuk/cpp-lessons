#include "Product.h"

Product::Product(string inName, double inPrice, string inModel, unsigned inAmount, unsigned inID)
{
	name = inName;
	price = inPrice;
	model = inModel;
	amount = inAmount;
	ID = inID;
}

unsigned Product::GetID()
{
	return ID;
}

string Product::GetName()
{
	return name;
}
double Product::GetPrice()
{
	return price;
}
unsigned Product::GetAmount()
{
	return amount;
}
string Product::GetModel()
{
	return model;
}

void Product::SetName(string inName)
{
	name = inName;
}
void Product::SetPrice(double inPrice)
{
		price = inPrice;
}
void Product::SetModel(string inModel)
{
		model = inModel;
}

void Product::SetAmount(unsigned inAmount)
{
	amount = inAmount;
}

void Product::SetID(unsigned inID)
{
	ID = inID;
}