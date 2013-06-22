#include <iostream>
#include <cstring>
#include <iomanip>
//#include <ctime>
//#include <cmath>
//#include <fstream>
//#include <Windows.h>
#include "19_Date.h"
using namespace std;
//----------------------------------------------------------------------------------------------
// Member functions	(Методы класса): Date
//----------------------------------------------------------------------------------------------
// contructors					(конструкторы)
//----------------------------------------------------------
// default constructor			(конструктор по умолчанию)
Date::Date()
{
	cout << "default constructor" << endl;
	year = 1970;
	month = 1;
	day = 1;
}
// overloaded constructor		(перегруженный конструктор)
Date::Date( int date_day, int date_month, int date_year )
{
	cout << "overloaded constructor" << endl;
	setDay( date_day );
	setMonth( date_month );
	setYear( date_year );
}
//----------------------------------------------------------
// setters						(mutator functions)
//----------------------------------------------------------
void Date::setDay( int date_day )
{
    if ( date_day >= 1	&& date_day <= 31 )
		this->day = date_day;
	else this->day	= 1;
}
void Date::setMonth( int date_month )
{
    if ( date_month >= 1 && date_month <= 12 )
		this->month = date_month;
	else this->month = 1;
}
void Date::setYear( int date_year)
{
    if ( date_year > 0 )
		this->year = date_year;
	else this->year  = 1;
}
//----------------------------------------------------------
// getters						(accessor functions)
//----------------------------------------------------------
const int Date::getYear()
{
	return year;
}
const int Date::getMonth()
{
	return month;
}
const int Date::getDay()
{
	return day;
}
//----------------------------------------------------------
// user functions				(функции пользователя)
//----------------------------------------------------------
void Date::showDate()
{
	cout << day << "/" << month << "/" << year << endl;
}
void Date::showDate_1()	// 12/25/2012
{
	cout << month << "/" << day << "/" << year << endl;
}
void Date::showDate_2()	// December 25, 2012
{
	cout << this->getMonth_char( this->getMonth() ) << " " << day << ", " << year << endl;
}
void Date::showDate_3()	// 25 December 2012
{
	cout << day << " " << this->getMonth_char( this->getMonth() ) << " " << year << endl;
}
char* Date::getMonth_char( int date_month )
{
    char *month[12];
    month[1]="January";month[2]="February";month[3]="March";month[4]="April";month[5]="May";month[6]="June";
    month[7]="July";month[8]="August";month[9]="September";month[10]="October";month[11]="November";month[12]="December";
	return month[date_month];
}
//----------------------------------------------------------
// destructor					(деструктор)
//----------------------------------------------------------
Date::~Date()
{
	cout << "destructor" << endl;
	year = 0;
	month = 0;
	day = 0;
}