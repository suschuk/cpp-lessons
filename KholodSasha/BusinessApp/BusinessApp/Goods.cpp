#include "Goods.h"
#include <iostream>
#include <iomanip>
#include <string>

std::vector<Goods::good> Goods::goodsVec;

Goods::Goods(void)
{
	Goods::loadGoodsFromFile();
}


Goods::~Goods(void)
{
}

void Goods::loadGoodsFromFile()
{
	FILE* in = NULL;
	fopen_s(&in, "goods.txt", "r");
	if (in == NULL)
	{
		std::cerr << "Open File Error" << std::endl;
		return;
	}
	char goodsCount[10];
	good newGood;
	
	fgets(goodsCount, 10, in);
	for(int i = 0; i < atoi(goodsCount); ++i)
	{
		fgets(newGood._brand, 16, in);
		fgets(newGood._price, 16, in);
		fgets(newGood._model, 16, in);
		newGood._goodID = i + 1;
		goodsVec.push_back(newGood);
	}
	fclose(in);
}

void Goods::print()
{
	std::cout << "ID   " << std::setw(10) << "Brand" << std::setw(10) << "Model" << std::setw(10) << "Price" << std::endl;
	for(auto it = goodsVec.begin(); it < goodsVec.end(); ++it)
	{
		for(int i = 0; i < 16; ++i)
		{
			if(it->_brand[i] == 10)
			{
				it->_brand[i] = '\0';
			}
			if(it->_model[i] == 10)
			{
				it->_model[i] = '\0';
			}
			if(it->_price[i] == 10)
			{
				it->_price[i] = '\0';
			}
		}
		std::cout << it->_goodID;
		std::cout << "   " << std::setw(10) << std::string(it->_brand);
		std::cout << std::setw(10) << std::string(it->_model);
		std::cout << std::setw(10) << it->_price << " $" << std::endl;
	}
}
int Goods::getSize()
{
	return goodsVec.size();
}