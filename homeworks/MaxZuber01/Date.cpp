#include <iostream>
#include <iomanip>
#include "Date.H"

using namespace std;



	Date::Date()
	{
		day_ = 1;
		month_ = 1;
		year_ = 1970;
	}
	Date::Date(int day, int month, int year)
	{
		this->day_ = day;
		this->month_ = month;
		this->year_ = year;
	}
	void Date::setDay()
	{
		while(1)
		{
			cout << "\nEnter Day: ";
			cin >> day_;
			if(day_ >= 1 && day_ <= 31)
			{
				break;
			}
			cout << "\nIncorect Day\n";
		}
	}
	void Date::setMonth()
	{
		
		while(1)
		{
			cout << "\nEnter Month: ";
			cin >> month_;
			if(month_ >= 1 && month_ <= 12)
			{
				break;
			}
			cout << "\nincoretc Month!\n";
		}
	}
	void Date::setYear()
	{
			cout << "\nEnter Year: ";
			cin >> year_;

	}

	int Date::getDay() const
	{
		return day_;
	}
	int Date::getMonth() const
	{
		return month_;
	}
	int Date::getYear() const
	{
		return year_;
	}
	void Date::showInfoOne() const
	{
		cout << "\nDate: " << setw(2) << setfill('0') << day_ << " / " << setw(2) << month_ << " / " << setw(4) << year_ << endl;
	}

	void Date::showInfoTwo() const
	{
		char month[][16] = {"January", "February",
						"March", "April", "May", 
						"June", "July", "August", 
						"September", "October", "November", 
						"December"};

		cout << "\nDate: " << month[month_ - 1] << " " << setw(2) <<  day_ <<", " << setw(4) <<  year_ << endl;
	
	}
	void Date::showInfoThree() const
	{
		char month[][16] = {"January", "February",
						"March", "April", "May", 
						"June", "July", "August", 
						"September", "October", "November", 
						"December"};

		cout << setw(2) << day_ << " " << month[month_ - 1] << " " << year_ << endl;
	
	}
