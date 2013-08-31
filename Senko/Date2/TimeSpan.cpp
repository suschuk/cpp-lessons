#include "TimeSpan.h"

TimeSpan::TimeSpan()
{
	days = 0;
	hours = 0;
	minutes = 0;
	seconds = 0;
}
TimeSpan::TimeSpan(int d, int h, int m, int s)
{
	days = d;
	hours = h;
	minutes = m;
	seconds = s;
}
TimeSpan::TimeSpan(const TimeSpan& inTimeSpan)
{
	days = inTimeSpan.days;
	hours = inTimeSpan.hours;
	minutes = inTimeSpan.minutes;
	seconds = inTimeSpan.seconds;
}