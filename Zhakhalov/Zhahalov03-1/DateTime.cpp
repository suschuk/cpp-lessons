#include "DateTime.h"

DateTime::DateTime(void): t(0){}

//accessors

DateTime::Date DateTime::GetDate() const
{
	tm *Tm = new tm;
	gmtime_s(Tm,&t);

	Date retDate = {Tm->tm_year + 1900, Tm->tm_mon, Tm->tm_mday, Tm->tm_wday};
	return retDate;
}

DateTime::Time DateTime::GetTimeUTC() const
{
	tm *Tm = new tm;
	gmtime_s(Tm,&t);

	Time retTime = {Tm->tm_hour, Tm->tm_min, Tm->tm_sec};
	return retTime;
}

DateTime::Time DateTime::GetTimeLocal() const
{
	tm *Tm = new tm;
	localtime_s(Tm,&t);

	Time retTime = {Tm->tm_hour, Tm->tm_min, Tm->tm_sec};
	return retTime;
}

time_t DateTime::GetTime() const
{
	return t;
}


//mutators
void DateTime::Current() 
{time(&t);}

void DateTime::SetTime(const Time &newTime)
{
	try
	{
		if(24 <= newTime.hour)   throw newTime.hour;
		if(60 <= newTime.minute) throw newTime.minute;
		if(60 <= newTime.second) throw newTime.second;

		tm *Tm = new tm;

		gmtime_s(Tm,&t);

		Tm->tm_hour = newTime.hour;
		Tm->tm_min  = newTime.minute;
		Tm->tm_sec  = newTime.second;

		t = mktime(Tm);
	}

	catch(int e)
	{
		e = e;//std::cout << "Illegal Time:" << newTime.hour << ":" << newTime.minute << ":" << newTime.second << "\r\n" 
	}
	
}

void DateTime::SetTime(const time_t T)
{
	t = T;
}

void DateTime::SetDate( const Date &newDate)
{
	const unsigned MONLEN[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	bool BS = false;

	if( !(newDate.year % 4) && ( (newDate.year % 100) || !(newDate.year % 400) ) )BS = true; // Feb length = 29

	try
	{
		if( (11 < newDate.month) && (0 > newDate.month) ) throw newDate.month;

		unsigned daymax = MONLEN[newDate.month];
		if(BS && (newDate.month == 1)) daymax = 29;

		if( (1 > newDate.day) || (daymax < newDate.day) ) throw newDate.day;

		if( (0 > newDate.dow) || (6 < newDate.dow) ) throw newDate.dow;

		tm *Tm = new tm;

		gmtime_s(Tm,&t);

		Tm->tm_year  = newDate.year - 1900;
		Tm->tm_mon   = newDate.month;
		Tm->tm_mday  = newDate.day;
		Tm->tm_wday  = newDate.dow;

		t = mktime(Tm);
	}
	
	catch(int e)
	{
		e = e;//std::cout << "Illegal Date:" << newDate.year << "/" << newDate.month << "/" << newDate.day << "/" << newDate.dow << "\r\n"
	}
}

