/*
	Создайте класс Время, в котором реализованы операции сложения, вычитания, 
	сравнения, ввода и вывод на экран. Возможность конвертации времени из 
	американского формата am (pm): 10:00 pm = 22:00, 12:00 pm =00:00
*/
#include "Time_.h"
#include <iostream>

using std::cout;
using std::boolalpha;

int main()
{
	Time_ myTime4(12, 5);
	Time_ myTime2(25, 75);
	Time_ myTime3(12, 15);
	Time_ myTime1(0, 15);

	cout << "myTime1 : " << myTime1;
	cout << "myTime2 : " << myTime2;
	cout << "myTime3 : " << myTime3;
	cout << "myTime4 : " << myTime4;

	cout << "myTime1 + myTime4 = " << (myTime1 + myTime4);
	cout << "myTime1 - myTime4 = " << (myTime1 - myTime4) << "\n";

	cout << boolalpha << "(myTime2 > myTime1) : " << (myTime2 > myTime1) << "\n";
	cout << boolalpha << "(myTime2 < myTime1) : " << (myTime2 < myTime1) << "\n";
	cout << boolalpha << "(myTime1 == myTime2) : " << (myTime1 == myTime2) << "\n";
	cout << boolalpha << "(myTime1 == myTime3) : " << (myTime1 == myTime3) << "\n";

	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	TimeAmPm_ myTimeAmPm1(2, 1, "pm");
	cout << myTimeAmPm1;

	myTimeAmPm1(10, 0, "pm");
	cout << myTimeAmPm1;
	myTime4.Convert(myTimeAmPm1);
	cout << myTime4;

	myTimeAmPm1(12, 0, "pm");
	cout << myTimeAmPm1;
	myTime4.Convert(myTimeAmPm1);
	cout << myTime4;

	return 0;
}