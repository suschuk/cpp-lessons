#pragma once
#ifndef _DATE_H_
#define _DATE_H_

#include<iostream>
using namespace std;

class Date
{
private:
	int day;
	int mounth;
	int year;
public:
	Date(void);
	Date(int, int, int);

	void setDay(int);
	void setMounth(int);
	void setYear(int);

	int getDay();
	int getMounth();
	int getYear();

	void setDateFromKeyboard();
	void getInfoOnScreen();
	~Date(void);
};

#endif //_DATE_H_
