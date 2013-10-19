#include <iostream>
#include "SafeArray.h"

using namespace std;

int main()
{

	SafeArray sa(10);

	//operator[] test
	cout << "\noperator[] test\n";
	for(int i = 0; i < 10; i++)
	{
		sa[i] = i*i*i;
	}
	
	for(int i = 0; i < 10; i++)
	{
		cout << sa[i] << endl;
	}


	//operator= test
	cout << "\noperator= test\n";
	SafeArray sa2;

	sa2 = sa;

	for(int i = 0; i < 10; i++)
	{
		cout << sa2[i] << endl;
	}

	return 0;
}