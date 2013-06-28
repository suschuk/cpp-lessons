#include "TimeDate.h"
#include <iostream>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

int TimeDate::days_in_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


TimeDate::TimeDate()
{
	tim = time(0);
}
TimeDate::TimeDate(time_t t)
{
	tim = t;
}
TimeDate::TimeDate(tm t)
{
	tim = mktime(&t);
}


void TimeDate::getTD()
{
	tm date_;
	//date
	cout << "\nEnter year: ";
	cin >> date_.tm_year;

	if((date_.tm_year % 4 == 0 && date_.tm_year % 100 != 0) || date_.tm_year % 400 == 0) 
	{
		days_in_months[1] = 29; // leap year
	}
	else days_in_months[1] = 28; // not leap year

	date_.tm_year -= 1900;


	cout << "\nEnter month: ";
	cin >> date_.tm_mon;
	if(date_.tm_mon < 1 || date_.tm_mon > 12) throw 1;
	date_.tm_mon -= 1;

	cout << "\nEnter day: ";
	cin >> date_.tm_mday;
	if(date_.tm_mday < 0 || date_.tm_mday > days_in_months[date_.tm_mon]) throw 1;	



	//time
	cout << "\nEnter hour's: ";
	cin >> date_.tm_hour;
	if(date_.tm_hour < 0 || date_.tm_hour > 23) throw 1;

	cout << "\nEnter minute's: ";
	cin >> date_.tm_min;
	if(date_.tm_min < 0 || date_.tm_min > 59) throw 1;

	cout << "\nEnter second's: ";
	cin >> date_.tm_sec;
	if(date_.tm_sec < 0 || date_.tm_sec > 59) throw 1;

	tim = mktime(&date_);
}

void TimeDate::showTD() const
{
	char buffer[80];
	tm tmp;
	localtime_s(&tmp, &tim);
	strftime(buffer,80,"%B, %d %Y. %H:%M:%S", &tmp);
	cout << buffer << endl;
}