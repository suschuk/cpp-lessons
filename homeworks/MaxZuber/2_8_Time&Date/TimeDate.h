#pragma once
#ifndef TIMEDATE_H_
#define TIMEDATE_H_
#include <ctime>

class TimeDate
{
public:
	TimeDate();
	TimeDate(time_t);
	TimeDate(tm);

	void getTD();
	void showTD()const;

private:
	time_t tim;	
	static int days_in_months[12];
};

#endif
