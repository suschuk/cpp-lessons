#include "Time_.h"

Time_::Time_()
{
	hours = 0;
	mins = 0;
}

Time_::Time_(int hh, int mm)
{
	hours = hh;
	mins = mm;
	correctTime_(*this);
}

void Time_::correctTime_(Time_& t)
{
	int dH;
	dH = mins / 60;
	mins = mins % 60;
	hours = (hours + dH) % 24;
}

Time_ Time_::operator+ (const Time_& t)
{
	Time_ res;
	res.mins = mins + t.mins;
	res.hours = hours + t.hours;
	
	res.correctTime_(res);

	return res;
}

Time_ Time_::operator- (const Time_& t)
{
	Time_ res;
	int dH = 0;
	if (mins - t.mins < 0)
	{
		dH = -1; 
		res.mins = 60 + mins - t.mins;
	}
	else
		res.mins = mins - t.mins; 
	
	if (hours - t.hours < 0)
	{
		res.hours = 24 + hours - t.hours + dH;
	}
	else	
		res.hours = hours - t.hours + dH;
	
	res.correctTime_(res);

	return res;
}

bool Time_::operator > (const Time_& t)
{	return hours > t.hours ? true : false;	}

bool Time_::operator < (const Time_& t)
{	return hours < t.hours ? true : false;	}

bool Time_::operator == (const Time_& t)
{	return ( hours == t.hours && mins == t.mins ) ? true : false;	}

ostream& operator << (ostream& output, const Time_& t)
{
	output.width(2);
	output.fill('0');
	output << t.hours;
	output << ":";
	
	output.width(2);
	output.fill('0');
	output << t.mins;
	output << "\n";
	
	return output;
}

istream& operator >> (istream& input, Time_& t)
{
	std::cout << "Enter hours: ";
	input >> t.hours;
	std::cout << "Enter minutes: ";
	input >> t.mins;

	t.correctTime_(t);

	return input;
}


TimeAmPm_::TimeAmPm_()
{
	mins = 0;
	hours = 0;
	pref = "*";
}

TimeAmPm_::TimeAmPm_(int hh, int mm, char* pr)
{
	hours= hh;
	mins = mm;
	pref = pr;
}

ostream& operator << (ostream& output, const TimeAmPm_& t)
{
	output << t.hours;
	output << ":";
	
	output.width(2);
	output.fill('0');
	output << t.mins;
	output << " ";
	output << t.pref;
	output << "\n";
	
	return output;
}

void TimeAmPm_::operator() (int hh, int mm, char* pr)
{
	hours= hh;
	mins = mm;
	pref = pr;

}

void Time_::Convert(const TimeAmPm_& t)
{
	
	if(strcmp(t.pref, "pm") == 0)
	{
		hours = t.hours + 12; // post meridiem
	}
	else
		hours = t.hours;

	mins  = t.mins;

	this->correctTime_(*this);
}
