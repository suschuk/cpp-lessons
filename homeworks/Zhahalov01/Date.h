#pragma once

#include <iostream>

class Date
{
private:
	int Day;
	int Mon;
	int Year;

public:
	Date(void);
	Date(int day, int mon, int yr);
	~Date(void);

	void setYr(int yr);
	void setMon(int mon);
	void setDay(int day);

	int getYr() const;
	int getMon()const;
	int getday()const;

	void showDate1();
	void showDate2();
	void showDate3();
};

