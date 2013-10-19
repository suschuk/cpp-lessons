#include "time.h"
#include <iostream>
#include <iomanip>
using namespace std;
void time::getTime()
{
	int tmp = 0;

	std::cout << "Enter hour's: ";
	std::cin >> tmp;
	if(tmp < 0 || tmp > 23)
	{
		throw 1;
	}
	sec_ += (tmp * 60 * 60);

	std:: cout << "Enter min's: ";
	std::cin >> tmp;

	if(tmp < 0 || tmp > 59)
	{
		throw 1;
	}
	sec_ += tmp * 60;

	std::cout << "Enter second's: ";
	std::cin >> tmp;
	if(tmp < 0 || tmp > 59)
	{
		throw 1;
	}
	sec_ += tmp;
}
void time::printTime() const
{
	int hrs = (sec_ / 60) / 60;
	int mins = (sec_ % (60 * 60)) / 60;
	int secs = (sec_ %(60 * 60)) % 60;

	if(am_pm)
	{
		if(hrs == 0)
		{
			std::cout << setfill('0') << setw(2) << hrs + 1 << ":" << setw(2) <<mins 
						<< "." << setw(2) <<secs << "am" << std::endl;
		}
		else if(hrs > 12)
		{
			hrs -= 12;
			std::cout <<setfill('0') << setw(2) << hrs << ":" << setw(2) <<  mins 
						<< "." << setw(2) << secs << "pm" << std::endl;
		}
		else
			std::cout << setfill('0') << setw(2) << hrs << ":" << setw(2) << mins 
					<< "." << setw(2) << secs << "am" << std::endl;
	}
	else
	{
		std::cout << setfill('0') << setw(2) << hrs << ":" << setw(2) << mins 
					<< ":" << setw(2) <<secs << std::endl; 
	}

}
bool time::operator==(const time& t)
{
	return sec_ == t.sec_? true: false;
}

void time::convertTime()
{
	am_pm = !am_pm;
}

unsigned time::getTimeinSec()const
{
	return sec_;
}