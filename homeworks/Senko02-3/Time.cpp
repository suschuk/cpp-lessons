#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

Time::Time()
{
	t = 0;
	f = UA;
}

Time::Time(int inTime, t_format inFormat)
{
	f = inFormat;
	if (inTime >= 0 && inTime <= SEC_DAY)
		t = inTime;
	else
		t = inTime % SEC_DAY;
}

Time::Time(const Time& inTime)
{
	t = inTime.t;
	f = inTime.f;
}

ostream& operator<< (ostream& out, const Time& inTime)
{
	int h = inTime.t / SEC_HOUR;
	int m = (inTime.t % SEC_HOUR)/SEC_MINUTE;
	int s = inTime.t - h*SEC_HOUR - m*SEC_MINUTE;
	
	if (inTime.f == UA)
	{
	if (h == 24)
		h = 0;

	out << setfill('0') << setw(2) << h << ":" 
						<< setw(2) << m << ":" 
						<< setw(2) << s << endl;
	}
	else
	{
		if (h == 0 && m == 0 && s == 0)
		{
			h = 12;

			out << setfill('0') << setw(2) << h << ":" 
				<< setw(2) << m << ":" 
				<< setw(2) << s << " PM" <<endl;
		}
		else
			if (h <= 12)
			{
				out << setfill('0') << setw(2) << h << ":" 
					<< setw(2) << m << ":" 
					<< setw(2) << s << " AM" <<endl;
			}
			else
			{
				out << setfill('0') << setw(2) << h-12 << ":" 
					<< setw(2) << m << ":" 
					<< setw(2) << s << " PM" << endl;
			}
	}
	return out;
}

istream& operator>>(istream& in, Time& inTime)
{
	char* time_str = new char[11];
	const char* sep = ": ";
	char* word;
	
	in.getline(time_str, 11);
		
	int h = 0;
	int m = 0;
	int s = 0;

	word = strtok(time_str, sep);
	h = atoi(word);
	word = strtok(NULL, sep);
	m = atoi(word);
	word = strtok(NULL, sep);
	s = atoi(word);

	word = strtok(NULL, sep);
	
	if ( word != NULL )
	{
		inTime.f = US;
		
		if (strcmp(word, "P") == 0)
			h += 12;	
	}
	else
	{
		inTime.f = UA;
	}

	inTime.t = h*SEC_HOUR+m*SEC_MINUTE+s;

	delete []time_str;

	return in;


}

Time& Time::operator= (const Time& inTime)
{
	t = inTime.t;
	f = inTime.f;

	return *this;
}

Time& Time::operator+= (const Time& inTime)
{
	if(this == &inTime) 
		return *this;
	
	this->f = inTime.f;

	int addTime = this->t + inTime.t; 

	if(addTime <= SEC_DAY)
		this->t = addTime;
	else
		this->t = addTime % SEC_DAY;

	return *this;
}

Time& Time::operator-= (const Time& inTime)
{
	if(this == &inTime) 
		return *this;

	this->f = inTime.f;

	int addTime = this->t - inTime.t; 

	while (addTime <= 0)
	{
		addTime+=SEC_DAY;
	}

	if(addTime <= SEC_DAY)
		this->t = addTime;
	else
		this->t = addTime % SEC_DAY;

	return *this;
}

Time Time::operator+ (const Time& inTime)
{
	Time tmp;
	tmp = *this;
	tmp += inTime;

	return tmp;
}

Time Time::operator- (const Time& inTime)
{
	Time tmp;
	tmp = *this;
	tmp -= inTime;

	return tmp;
}

bool Time::operator> (const Time& inTime)
{
	if (t > inTime.t)
		return true;
	else
		return false;
}

bool Time::operator>= (const Time& inTime)
{
	if (t >= inTime.t)
		return true;
	else
		return false;
}

bool Time::operator< (const Time& inTime)
{
	if (t < inTime.t)
		return true;
	else
		return false;
}

bool Time::operator<= (const Time& inTime)
{
	if (t <= inTime.t)
		return true;
	else
		return false;
}

bool Time::operator== (const Time& inTime)
{
	if (t == inTime.t)
		return true;
	else
		return false;
}

bool Time::operator!= (const Time& inTime)
{
	if (t != inTime.t)
		return true;
	else
		return false;
}

void Time::changeFormat()
{
	if (this->f == UA)
		f = US;
	else
		f = UA;
}

Time::~Time() { }
