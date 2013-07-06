#include "TimeSpan.h"

TimeSpan::TimeSpan(void)
{
	SetTime(0);
}

TimeSpan::TimeSpan(time_t T)
{
	SetTime(T);
}

TimeSpan TimeSpan::operator+(const TimeSpan& rms)
{
	return TimeSpan(GetTime() + rms.GetTime());
}

TimeSpan TimeSpan::operator-(const TimeSpan& rms)
{
	return TimeSpan(GetTime() - rms.GetTime());
}

bool TimeSpan::operator>(const TimeSpan& rms) const
{
	return (GetTime() > rms.GetTime());
}

bool TimeSpan::operator<(const TimeSpan& rms) const
{
	return (GetTime() < rms.GetTime());
}


