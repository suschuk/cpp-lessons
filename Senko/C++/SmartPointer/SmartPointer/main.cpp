#include <iostream>
#include "SmartPointer.h"

using namespace std;

class Tmp
{
public:
	Tmp (int t = 0) 
	{ 
		val = t; 
	}
	
	int getVal () 
	{ 
		return val; 
	}

private:
	int val;
};



int main()
{
	SmartPointer<Tmp> sp0 = new Tmp();
	SmartPointer<Tmp> sp1 = new Tmp(5);
	SmartPointer<Tmp> sp2 = new Tmp(10);
	SmartPointer<Tmp> sp3 = new Tmp(100);

	cout << "Creating smart pointers... " << endl;
	cout << "Setting values to 0, 5, 10, 100... " << endl;

	cout << sp0->getVal() << endl;
	cout << sp1->getVal() << endl;
	cout << sp2->getVal() << endl;
	cout << sp3->getVal() << endl;

	cout << "Smart pointer #1 = Smart pointer #2... " << endl;
	sp1 = sp2;
	cout << sp1->getVal() << endl;

	cout << "Copy constructor sp4(sp3)... " << endl;
	SmartPointer<Tmp> sp4(sp3);
	cout << sp4->getVal() << endl;

	return 0;
}


