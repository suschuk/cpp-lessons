#pragma once
#include <vector>
#include "ClientsDataBase.h"

class Goods
{
	friend class ClientsDataBase;
public:
	Goods(void);
	~Goods(void);

	static void loadGoodsFromFile();
	static void print();
	static int getSize();
	struct good
	{
		char _brand[16];
		char _model[16];
		char _price[16];
		int _goodID;
	};
private:
	
	static std::vector<good> goodsVec;
};

