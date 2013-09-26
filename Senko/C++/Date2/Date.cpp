#include "Date.h"
#include <iostream>

Date::Date()
{
	mDate.tm_year = 0;
	mDate.tm_mon  = JANUARY;
	mDate.tm_yday = 1;
	mDate.tm_mday = 1;
	mDate.tm_wday = 1;
	
	mDate.tm_hour = 0;
	mDate.tm_min  = 0;
	mDate.tm_sec  = 0;

	mDate.tm_isdst = 0;
}

Date::Date(time_t inDate)
{
	localtime_s(&mDate, &inDate);
}

Date::Date(const Date& inDate)
{
	mDate = inDate.mDate;
}

void Date::print()
{
	char buff[32];
	asctime_s(buff, 32, &mDate);
	std::cout << buff << std::endl;
	//std::cout << asctime(&mDate) << std::endl;
}

bool Date::operator== (Date& inDate)
{
	if( mktime(&mDate) == mktime(&inDate.mDate) )
		return true;
	else
		return false;
}

bool Date::operator> (Date& inDate)
{
	if( mktime(&mDate) > mktime(&inDate.mDate) )
		return true;
	else
		return false;
}

bool Date::operator< (Date& inDate)
{
	if( mktime(&mDate) < mktime(&inDate.mDate) )
		return true;
	else
		return false;
}

bool Date::operator>= (Date& inDate)
{
	if( mktime(&mDate) >= mktime(&inDate.mDate) )
		return true;
	else
		return false;
}

bool Date::operator<= (Date& inDate)
{
	if( mktime(&mDate) <= mktime(&inDate.mDate) )
		return true;
	else
		return false;
}

void Date::operator+ (TimeSpan& inSpan)
{
	time_t sec_span = inSpan.seconds 
					+ inSpan.minutes*SEC_IN_MIN
					+ inSpan.hours*SEC_IN_HOUR
					+ inSpan.days*SEC_IN_DAY;

	time_t sec_date = mktime(&this->mDate);

	sec_date+=sec_span;

	Date tmp(sec_date);

	*this = tmp;
}

void Date::operator- (TimeSpan& inSpan)
{
	time_t sec_span = inSpan.seconds 
					+ inSpan.minutes*SEC_IN_MIN
					+ inSpan.hours*SEC_IN_HOUR
					+ inSpan.days*SEC_IN_DAY;

	time_t sec_date = mktime(&this->mDate);

	sec_date-=sec_span;

	Date tmp(sec_date);

	*this = tmp;
}