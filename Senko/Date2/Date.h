#ifndef DATE_H
#define DATE_H

#include <time.h>
#include "../TimeSpan/TimeSpan.h"

class Date
{
public:

	static enum MONTHS {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, 
						AUGEST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

	static const int SEC_IN_MIN = 60;
	static const int SEC_IN_HOUR = 60*60;
	static const int SEC_IN_DAY = 60*60*24;

	Date();
	Date(time_t);
	Date(const Date&);
		
	bool operator== (Date&);
	bool operator>  (Date&);
	bool operator<  (Date&);
	bool operator>= (Date&);
	bool operator<= (Date&);

	void operator+ (TimeSpan&);
	void operator- (TimeSpan&);

	void print();
private:
	tm mDate;
};

#endif