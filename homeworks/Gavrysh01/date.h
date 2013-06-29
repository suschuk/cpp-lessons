#pragma once
#include <iostream>
class date
{
private:   // private має йти наприкінці
	int day;
	int month;
	int year;
public:
	date(void);
	date(int day, int month, int year);
	//~date(void);
	void setDate (int day, int month, int year);
	void setDate(void);
	void printDate (char *separator);
	void printDate (char *separator, int monthMode);
};

