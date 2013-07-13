# include <iostream>
# include <string.h>
# include <math.h>
# pragma once
# ifndef CLASSDATE_H_
# define CLASSDATE_H_


using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	void set_year(int year);
	void set_month(int month);
	void set_day(int day);

	int get_year();
	int get_month();
	int get_day();

	Date();

	Date(int year, int month, int day);

	Date(const Date& tmp);

	void fillDate();

	void showDate();

	void showDate2();

	void showDate3();

	int operator-(const Date& tmp)
	{
		int res=0;

		Date some;
		some.day = this->day - tmp.day;
		some.month = this->month - tmp.month;
		some.year = this->year - tmp.year;

		abs(some.day);
		abs(some.month);
		abs(some.year);

		while (some.year != 0)
		{
			res += 365;
			some.year--;
		}

		for (int i = some.month; i>0 ; i--)
		{
			if (i%2 == 0 && i!=8 && i!=2)
			{
				res+=30;
			}
			else if (i==2)
			{
				res+=28;
			}
			else
			{
				res+=31;
			}
		}

		res+=some.day;

		return res;
	}

	void operator+(int a)
	{
		int tmp=0;

		tmp=floor(a/365.0);
		this->year += tmp;

		tmp= a % 365;
		int i=tmp;
		for (int count = this->month + 1; i>=28; count++)
		{
			if (count%2 == 0 && count!=8 && count!=2 && i>=30)
			{
				this->month+=1;
				i-=30;
			}
			else if(count==2 && i==28)
			{
				this->month+=1;
				i-=28;
			}
			else if (count==2 && i!=28)
			{
				this->month+=1;
				i-=28;
			}
			else if(count%2 == 1 && i>28 || count==8 && i>28)
			{
				this->month+=1;
				i-=31;
			}
			if (count==12)
			{
				count=0;
			}
			tmp=i;
		}

		this->day+=tmp;

		this->year+=floor(this->month/12.0);

		while(this->day>=31)
		{
			if (this->month%2 == 0 && this->month!=8 && this->month!=2 && this->day>30)
			{
				this->month+=1;
				this->day-=30;
			}
			else if (this->month==2 && this->day>28)
			{
				this->day-=28;
				this->month+=1;
			}
			else if(this->month%2 == 1 && this->month==8 && this->day>31)
			{
				this->day-=31;
				this->month+=1;
			}
		}

		this->month -= floor(this->month/12.0)*12;
	}


};

#endif