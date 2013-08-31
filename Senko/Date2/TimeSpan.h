#ifndef TIMESPAN_H
#define TIMESPAN_H

class TimeSpan
{
friend class Date;

public:
	TimeSpan();
	TimeSpan(int , int, int, int);
	TimeSpan(const TimeSpan& inTime);
	
private:
	int days;
	int hours;
	int minutes;
	int seconds;

};

#endif