/*
	Написать класс, реализующий работу с комлексными числами
*/
//#include <iostream>
//using namespace std;
#include "Complex.h"

using std::cout;

int main()
{
	Complex myZ_1(0.444, 0.5555);
	Complex myZ_3(44, 5.555);

	cout << myZ_1;

	Complex myZ_2;
	myZ_2 = myZ_1;
	
	cout << myZ_2;

	cout << myZ_3 + myZ_2;
	cout << myZ_3 - myZ_2;
	cout << myZ_3 * myZ_2;
	cout << myZ_3 / myZ_2;

	cout << "\n\n";
	
	return 0;
}