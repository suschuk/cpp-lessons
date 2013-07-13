# include "ClassDate.h"

void Date::set_year(int year)
{
	this->year = year;
}
void Date::set_month(int month)
{
	this->month = month;
}
void Date::set_day(int day)
{
	this->day = day;
}
int Date::get_year()
{
	return this->year;
}
int Date::get_month()
{
	return this->month;
}
int Date::get_day()
{
	return this->day;
}

Date::Date()
{
	this->year = 1970;
	this->month = 1;
	this->day = 1;
}

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(const Date& tmp)
{
	this->day = tmp.day;
	this->month = tmp.month;
	this->year = tmp.year;
}

void Date::fillDate()
{
	int year=0, month=0, day=0;
	cout<<"Year: ";
	cin>>year;
	do 
	{
		cout<<"Month: ";
		cin>>month;
		if(month > 12 || month < 1)
		{
			cout<<"Wrong month!\n";
		}
	}while(month < 1 || month > 12);
	do
	{
		cout<<"Day: ";
		cin>>day;
		if(day > 31 || day < 1)
		{
			cout<<"Wrong day!\n";
		}
	}while(day < 1 || day > 31);

	this->set_day(day);
	this->set_month(month);
	this->set_year(year);
}

void Date::showDate()
{
	cout<<"Year: "<<this->year<<endl;
	cout<<"Month: "<<this->month<<endl;
	cout<<"Day: "<<this->day<<endl;
}

void Date::showDate2()
{
	cout<< this->month <<"/"<< this->day <<"/"<< this->year <<endl;
}

void Date::showDate3()
{
	enum mon{null, January, February, March, April, May, June, July, August, September, October, November, December};

	cout<< this->day <<" ";
	switch (this->month)
	{
	case January:
		cout<<"January ";
		break;
	case February:
		cout<<"February ";
		break;
	case March:
		cout<<"March ";
		break;
	case April:
		cout<<"April ";
		break;
	case May:
		cout<<"May ";
		break;
	case June:
		cout<<"June ";
		break;
	case July:
		cout<<"July ";
		break;
	case August:
		cout<<"August ";
		break;
	case September:
		cout<<"September ";
		break;
	case October:
		cout<<"October ";
		break;
	case November:
		cout<<"November ";
		break;
	case December:
		cout<<"December ";
		break;
	}
	cout<< this->year<<endl;

}

