/*Разработать класс Date для представления даты (день, месяц, год). 
Реализовать методы для доступа к полям (с контролем допустимости аргументов!).
Определить конструктор с параметрами для удобного пользования классом, 
методы считывания даты с клавиатуры и печати ее на экране. */

#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	Date d1, d2(1,12,2013);

	d1.showInfoOne(); //default info
	d2.showInfoTwo(); //overloaded constructor info

	d1.setDay();
	d1.setMonth();
	d1.setYear();

	d1.showInfoThree();	//info created by metod's

	cout << "\nDay: " << d1.getDay() ;
	cout << "\nMonth: " << d1.getMonth() ;
	cout << "\nyear: " << d1.getYear() << endl;

return 0;
}
