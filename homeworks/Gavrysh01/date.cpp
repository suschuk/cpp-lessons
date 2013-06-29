#include "date.h"
using namespace std;

date::date(void)
{
	this->day=0;
	this->month=0;
	this->year=0;
}

date::date (int day, int month, int year)
{
	if (day>=0 && day<=31)
	{
		this->day=day;
	}
	if (month>=0 && month<=12)
	{
		this->month=month;
	}
	if (year>=0)
	{
		this->year=year;
	}
}

//date::~date(void)
//{
//}

void date::setDate (int day, int month, int year)
{
	if (day>=0 && day<=31)
	{
		this->day=day;
	}
	if (month>=0 && month<=12)
	{
		this->month=month;
	}
	if (year>=0)
	{
		this->year=year;
	}
}

void date::setDate(void)
{
	int day;
	int month;
	int year;

	for (;;)
	{
		system("cls");
		cout << "Type day: ";
		cin >> day;
		if (day>=0 && day<=31)
		{
			this->day=day;
		}
	}

	for (;;)
	{
		system("cls");
		cout << "Type month: ";
		cin >> month;
		if (month>=0 && month<=12)
		{
			this->month=month;
		}
	}

	for (;;)
	{
		system("cls");
		cout << "Type year: ";
		cin >> year;
		if (year>=0)
		{
			this->year=year;
		}
	}
}

void date::printDate (char *separator)
{
	cout << this->day << separator << this->month << separator << this->year << "\n"; 
}

void date::printDate (char *separator, int monthMode)
{
	cout << this->day << separator;
	if (monthMode==1)
	{
		switch (this->month)
		{
		case 1:
			cout << "January";
			break;
		case 2:
			cout << "February";
			break;
		case 3:
			cout << "March";
			break;
		case 4:
			cout << "April";
			break;
		case 5:
			cout << "May";
			break;
		case 6:
			cout << "June";
			break;
		case 7:
			cout << "July";
			break;
		case 8:
			cout << "August";
			break;
		case 9:
			cout << "September";
			break;
		case 10:
			cout << "October";
			break;
		case 11:
			cout << "November";
			break;
		case 12:
			cout << "December";
			break;
		}
	}
	else
	{
		cout << this->month;
	}
	cout << separator << this->year << "\n"; 
}
