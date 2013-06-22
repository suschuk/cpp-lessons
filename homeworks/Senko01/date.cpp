#include <iostream>
#include <iomanip>
#include "date.h"

using namespace std;

Date::Date ()
{
	this->day = 1;
	this->month = JANUARY;
	this->year = 1900;
}

Date::Date (int inDay, int inMonth, int inYear)
{
	this->day = inDay;
	this->month = inMonth;
	this->year = inYear;
}

Date::Date (const Date& d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}

void Date::setDay (int inDay)
{
	if (inDay >=1 && inDay <= 31)
	{
		this->day = inDay;
	}
	else
	{
		this->day = 1;
	}
	
}

void Date::setMonth (int inMonth)
{
	if (inMonth >=1 && inMonth <= 12)
	{
		this->month = inMonth;
	}
	else
	{
		this->month = JANUARY;
	}
	
}

void Date::setYear(int inYear)
{
	if (inYear >=1 && inYear <= 9999)
	{
		this->year = inYear;
	}
	else
	{
		this->year = 1900;
	}
	
}

int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear()const
{
	return this->year;
}

void Date::strToDate (char* date_str)
{
	const char* sep = "./";
	char* word ;
	
	word = strtok(date_str, sep);
	this->setDay(atoi(word));
	
	word = strtok(NULL, sep);
	this->setMonth(atoi(word));
	
	word = strtok(NULL, sep);
	this->setYear(atoi(word));
}

bool Date::checkDayOfMonth(int day, int month)
{
	int calendar[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (day < 1 || day > 31)
	{
		return false;
	}
	else
	{
		if ( day > calendar[month-1])
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

int Date::daysFromDate()
{
	int calendar[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int rDays = 0;

	rDays = this->year*365;

	for (int i = 1; i <= this->year; i++)
	{
		if (i % 4 == 0)
		{
			rDays++;
		}
	}

	for (int i=0; i < this->month-1; i++ )
	{
		rDays+=calendar[i];
	}

	rDays+= this->day;

	return rDays;
}

CHK_DATE Date::checkDate ()
{
	if (this->year < 0 || this->year > 9999)
	{
		return INC_YEAR;
	}
	else 
		if (this->month < 1 || this->month > 12)
		{
			return INC_MONTH;
		}
			else
				if ( ! checkDayOfMonth(this->day, this->month) )
				{
					return INC_DAY;
				}
				else
				{
					return CORRECT_DATE;
				}
}

void Date::printDate (printFormat f)
{
	char* arrMonth[12] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", 
						  "AUGEST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
	switch (f)
	{
	case SLASH:
		{
			cout << setfill('0');
			cout << setw(2) << this->day <<"/" 
				 << setw(2) << this->month <<"/" 
				 << setw(4) << this->year << endl;
		}
		break;
	case MONTH_FIRST:
		{
			cout << arrMonth[this->month-1] << " " << this->day <<", " << this->year << endl;
		}
		break;
	case DAY_FIRST:
		{
			cout << this->day <<" "<< arrMonth[this->month-1] << ", " << this->year << endl;
		}
		break;
	}
	
}

bool Date::operator== (const Date& inDate)
{
	if(this->day == inDate.day &&
	   this->month == inDate.month &&
	   this->year == inDate.year )
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Date::operator-(Date& inDate)
{
	int days1Date = this->daysFromDate();
	int days2Date = inDate.daysFromDate();

	int daysBetween = 0;
	
	if (days1Date >= days2Date)
		daysBetween = days1Date - days2Date;
	else
		daysBetween = days2Date - days1Date;

	return daysBetween;
}

void Date::operator+(int inDays)
{
	int calendar[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int daysInDate = this->daysFromDate();
	daysInDate+= inDays;

	int tmpD = daysInDate;
	int monthLeft = daysInDate;
	int tmpM = 0;
	int daysLeft = daysInDate;
	
	int y = 0;
	int m = 0;
	
	while (tmpD >= 0)
	{
		if (y % 4 == 0)
			tmpD-=366;
				else
			tmpD-=365;
		y++;
	}
	y--;

	for (int i = 0; i < y; i++)
	{
		if(i % 4 == 0)
			monthLeft-=366;
		else
			monthLeft-=365;
	}
	
	tmpM = monthLeft;

	while (tmpM >= 0)
	{
		tmpM-= calendar[m];
		m++;
	}

	daysLeft = monthLeft;

	for (int i = 0; i < m-1; i++)
	{
		daysLeft-=calendar[i];
	}

	this->year = y;
	this->month = m;
	this->day = daysLeft;
}

Date::~Date()
{

}