#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{

	LinkedList<int> lli;
	//lli.print();
	int i = 9;
	lli.ins(9);
	lli.ins(9);
	lli.ins(9);
	lli.ins(9);
	lli.ins(9);
	try
	{
		lli.print();
	}
	catch(std::runtime_error e)
	{
		cout << e.what()<< endl;
	}


	lli.head_();
	lli.del();
	lli.del();




	try
	{
		lli.print();
	}
	catch(std::runtime_error e)
	{
		cout << e.what()<< endl;
	}

}
