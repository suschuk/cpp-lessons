#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <ctime>
using namespace std;
// global methods

//void getaLine(string&);	
void setCoords(int, int);
void hideCursor();
void showCursor();
string dTimeToStr(int, int, int, int, int);
string clLstName(string);

// classes
class Menu_
{
private:
	vector<string> items;
public:
	Menu_(): items(NULL)
	{}
	Menu_(vector<string> it) : items(it)
	{}
	int show(string = "");
	void set(vector<string> it)
	{
		items = it;
	}
};

class fileShow
{
private:
	string fileName;
	string title;
public:
	fileShow(string fN, string t) : fileName(fN), title(t)
	{}
	void interact();
};

class Client
{
private:
	string		firstName;
	string		lastName;
	Menu_*		ptrMenu_;
	fileShow*	ptrFileShow;
public:
	void interact();
	void add();
	void remove();
	static vector<string> pick(); 
};

class Goods
{
private:
	string title;
	string id;
	int q;						// quantity
	float price;
	Menu_*		ptrMenu_;
	fileShow*	ptrFileShow;
public:
	void add();
	vector<string> pick(); 
	void toFileGd(vector<string>);
	Goods strToGoods(string);
	string goodsToStr (Goods);
	string getTitle() const
		{	return title;	}
	string getId() const
		{	return id;	}
	int getQ() const
		{	return q;	}
	void setQ( int iQ)
		{	q = iQ;	}
	float getPrice() const
		{	return price;	}
	void remove();
	void interact();
};

class userInterface 
{
private:
	Menu_*	ptrMenuClients;
	Menu_*	ptrMenuGoods;
	Menu_*	ptrMenu_;
	Client* ptrClient;
	Goods*	ptrGoods;
public:
	//userInterface();
	//~userInterface();
	void interact();
};
