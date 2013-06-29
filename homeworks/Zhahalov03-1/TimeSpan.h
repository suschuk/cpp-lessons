#pragma once
#include "DateTime.h"
class TimeSpan :public DateTime
{
public:

	TimeSpan();
	TimeSpan(time_t);

	TimeSpan operator+(const TimeSpan&);
	TimeSpan operator-(const TimeSpan&);
	bool operator>(const TimeSpan&) const;
	bool operator<(const TimeSpan&) const;
};

