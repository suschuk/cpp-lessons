#pragma once
#include <iostream>


class Date
{
public: 
	Date();

	int setDate(int year, int month, int day);
	
	void setDateOfDay(int day);

	int getDate() const;

	int getCurrentDate();

	int getYear() const;

	int getMonth() const;

	int getDay() const;

	Date (Date & a);
	
	Date operator-(Date & inputDate);

	Date operator+(Date & inputDate);

	char* format(int f);
	
	~Date();
private:
	
	int month[12];
	int day;
	char* strData;
	bool isLeapYear(unsigned int year) const;
};
