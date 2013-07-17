#include <iostream>
#include "String.h"

using namespace std;

int main ()
{
	String STR1;
	String STR2;

	cout << "STR 1:" << endl;
	STR1.inputString();
		
	cout << "STR 2:" << endl;
	STR2.inputString();

	String STR3;
	STR3 = STR1+STR2;
	cout << "STR1 + STR2 = " << STR3.getString() << endl;
	
	STR3 = STR1*STR2;
	cout << "STR1 * STR2 = " << STR3.getString() << endl;
	
	cout <<  endl << "All strings data:" << endl;
	STR1.printString();
	STR2.printString();
	STR3.printString();

	return 0;
}