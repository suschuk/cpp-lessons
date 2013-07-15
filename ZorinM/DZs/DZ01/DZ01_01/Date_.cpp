#include "Date_.h"
#include <iostream>
#include <iomanip>
using namespace std;

// конструктор по замовчуванню
Date_::Date_()
{
	day = 1;
	month = 1;
	year = 1970;
}

// конструктор з параметрами
Date_::Date_(int d, int m, int y)
{
	setDate(d, m, y);
}

// конструктор коп≥њ
Date_::Date_(const Date_& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}

void Date_::setDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void Date_::showDate(int mode) const
{
	char* month_str[12] = { "January", "February", 
							"March", "April", "May", 
							"June", "July", "August", 
							"September", "October", "November", "December"};
	
	switch(mode)
	{
	case 1:  // вив≥д дати у формат≥: December 25, 2012 
		cout << month_str[month - 1] << " ";
		cout << setw(2) << setfill('0');
		cout << day << ", ";
		cout << setw(4) << setfill('0');
		cout << year << endl;
		break;
	case 2: //вив≥д дати у формат≥: 25 December 2012
		cout << setw(2) << setfill('0');
		cout << day << " ";
		cout << month_str[month - 1] << " ";
		cout << setw(4) << setfill('0');
		cout << year << endl;
		break;
	
	default:	
		cout << setw(2) << setfill('0');
		cout << day << ":";
		cout << setw(2) << setfill('0');
		cout << month << ":";
		cout << setw(4) << setfill('0');
		cout << year << endl;
		break;
	}
}

bool Date_::checkDate()
{
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

void Date_::enterDate()
{
	int d, m, y;
	Date_ tmp;

	while(true)
	{
		cout << "Enter day: ";
		cin >> d;
		cout << "Enter month: ";
		cin >> m;
		cout << "Enter year: ";
		cin >> y;

		tmp.setDate(d, m, y);

		if(tmp.checkDate())
		{
			day = d;
			month = m;
			year = y;

			break;
		}
		else
		{
			cout << "Incorrect date!\nPlease reenter\n";
		}
	}
}
