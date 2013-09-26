#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using std::string;

class Product
{
public:
	Product(): ID(0), name(""), price(0.0), model(""), amount(0) {};
	Product(string, double, string, unsigned, unsigned);
	unsigned GetID();
	string GetName();
	double GetPrice();
	string GetModel();
	unsigned GetAmount();

	void SetID(unsigned);
	void SetName(string);
	void SetPrice(double);
	void SetModel(string);
	void SetAmount(unsigned);

private:
	unsigned ID;
	string name;
	double price;
	string model;
	unsigned amount;
};

#endif