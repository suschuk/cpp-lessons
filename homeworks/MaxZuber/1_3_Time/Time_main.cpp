#include "time.h"
using namespace std;
#include <iostream>


int main()
{
	time t1;

	t1.getTime();		
	t1.printTime();
	t1.convertTime();
	t1.printTime();

	cout << "\nTime in second's: " << t1.getTimeinSec() << endl;
	return 0;
}