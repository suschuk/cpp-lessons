#include <iostream>
#include <ctime>
#include "DateTime.h"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

DateTime::DateTime(int yy, int mm, int dd, 
	               int h,  int m,  int s)
{
	tm ti;				// timeInfo
	ti.tm_sec = s;   
	ti.tm_min = m;   
	ti.tm_hour = h;  
	ti.tm_mday = dd;  
	ti.tm_mon = mm - 1;   
	ti.tm_year = yy - 1900;  

	if ( checkDT(ti))
	{
		d_t = mktime(&ti);
		// cout << "\nDataTime is correct\n";
	}
	else
	{ cerr << "\nUncorrect Data\n"; exit(1); }
}

void DateTime::set()
{
	tm ti;
	
	cout << "Enter year: ";
	cin >> ti.tm_year;
	
	cout << "Enter month: ";
	cin >> ti.tm_mon;
	
	cout << "Enter day: ";
	cin >> ti.tm_mday;
	
	cout << "Enter hours: ";
	cin >> ti.tm_hour;
	
	cout << "Enter minutes: ";
	cin >> ti.tm_min;
	
	cout << "Enter seconds: ";
	cin >> ti.tm_sec;

	ti.tm_year -= 1900;
	ti.tm_mon--;

	if ( checkDT(ti))
	{
		d_t = mktime(&ti);
		cout << "\nDataTime is correct\n";
	}
	else
	{ cerr << "\nUncorrect Data\n"; exit(1); }

}

void DateTime::show() const
{
	tm timeinfo;
	char timebuff [32];

	localtime_s (&timeinfo, &d_t);
	asctime_s(timebuff, 32, &timeinfo);
	cout << timebuff;
}

bool DateTime::checkDT(tm dt_info) const
{
	int year = dt_info.tm_year + 1900;
	int month = dt_info.tm_mon + 1;
	int day = dt_info.tm_mday;

	if (month < 1 || month > 12)
	{
		return false;
	}
	else if (year < 0)
	{
		return false;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) // 30 дн≥в у даних м≥с€ц€х, нелалежно в≥д року
	{
		if(day < 1 || day > 30)
			return false;
	}
	else if(month == 2)
	{
		// визначаЇмо, чи не Ї даний р≥к високосним
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

		if (isLeapYear) 
		{
			if(day < 1 || day > 29)
				return false;
		}
		else
		{
			if(day < 1 || day > 28)
				return false;
		}
	}	
	else
	{
		if(day < 1 || day > 31)
			return false;
	}
	
	return true;
}

int DateTime::getYear() const
{
	tm ti;
	localtime_s (&ti, &d_t);	
	return ti.tm_year + 1900;
}

int DateTime::getMonth() const
{
	tm ti;
	localtime_s (&ti, &d_t);	
	return ti.tm_mon + 1;
}

int DateTime::getDay() const
{
	tm ti;
	localtime_s (&ti, &d_t);	
	return ti.tm_mday;
}

int DateTime::getHours() const
{
	tm ti;
	localtime_s (&ti, &d_t);	
	return ti.tm_hour;
}

int DateTime::getMins() const
{
	tm ti;
	localtime_s (&ti, &d_t);	
	return ti.tm_min;
}

int DateTime::getSecs() const
{
	tm ti;
	localtime_s (&ti, &d_t);	
	return ti.tm_sec;
}
