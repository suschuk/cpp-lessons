#include "Date.h"


Date::Date(void)
{
	day = 1970;
	mounth = 1;
	year = 1;
}
Date::Date(int day, int mounth, int year)
{
	setDay(day);
	setMounth(mounth);
	setYear(year);
}


Date::~Date(void)
{
	day = 0;
	mounth = 0;
	year = 0;
}

void Date::setDay(int day)
{
	if(day > 0 && day < 32)
		this->day = day;
	else
		cerr << "Uncorrect day!" << endl;
}
void Date::setMounth(int mounth)
{
	if(mounth > 0 && mounth < 13)
		this->mounth = mounth;
	else
		cerr << "Uncorrect mounth" << endl;
}
void Date::setYear(int year)
{
	if(year >= 0)
		this->year = year;
	else
		cerr << "Uncorrect year" << endl;
}
int Date::getDay()
{
	return day;
}
int Date::getMounth()
{
	return mounth;
}
int Date::getYear()
{
	return year;
}
void Date::setDateFromKeyboard()
{
	int day;
	cout << "Enter the day: ";
	cin >> day;
	setDay(day);

	int mounth;
	cout << "Enter the mounth: ";
	cin >> mounth;
	setMounth(mounth);

	int year;
	cout << "Enter the year: ";
	cin >> year;
	setYear(year);
}
void Date::getInfoOnScreen()
{
	cout << "The date is: ";
	cout << day << "/" << mounth << "/" << year << endl;
}