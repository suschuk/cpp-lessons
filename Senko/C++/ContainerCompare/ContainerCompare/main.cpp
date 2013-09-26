#include <iostream>
#include "ContainersTest.h"

using namespace std;

int main ()
{
	const int TST_COUNT = 10;

	// -------------- LIST --------------------
	double sum = 0;
	
	cout << "List filling & getting ..." << endl;
	
	for (int i = 0; i < TST_COUNT; i++)
	{
		sum+= ListTest();

		cout << i << " ";
	}
	
	cout << endl <<	"LIST: " << sum << "ms" << endl << endl;

	// -------------- ARRAY --------------------
	 sum = 0;
	
	cout << "Array filling & getting ..." << endl;
	
	for (int i = 0; i < TST_COUNT; i++)
	{
		sum+= ArrayTest();

		cout << i << " ";
	}
	
	cout << endl <<	"ARRAY: " << sum << "ms" << endl << endl;

	// -------------- VECTOR --------------------
	sum = 0;
	
	cout << "Vector filling & getting ..." << endl;
	
	for (int i = 0; i < TST_COUNT; i++)
	{
		sum+= DequeTest();

		cout << i << " ";
	}
	
	cout << endl <<	"VECTOR: " << sum << "ms" << endl << endl;

	// -------------- DEQUE --------------------
	sum = 0;
	
	cout << "Deque filling & getting ..." << endl;
	
	for (int i = 0; i < TST_COUNT; i++)
	{
		sum+= DequeTest();

		cout << i << " ";
	}
	
	cout << endl <<	"DEQUE: " << sum << "ms" << endl << endl;

	return 0;
}