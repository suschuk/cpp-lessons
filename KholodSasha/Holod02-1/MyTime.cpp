#include "MyTime.h"
#include <iostream>

MyTime::MyTime(void)
{
	timeInMinutes = 0;
	time.minutes = 0;
	time.hours = 0;
}


MyTime::~MyTime(void)
{
}
bool MyTime::operator== (MyTime& time_)
{
	if(timeInMinutes == time_.timeInMinutes)
		return true;
	return false;
}
MyTime MyTime::operator+ (MyTime& time_)
{
	MyTime resTime;
	resTime.timeInMinutes = timeInMinutes + time_.timeInMinutes;
	resTime.minutesToTime();
	return resTime;
}
MyTime MyTime::operator- (MyTime& time_)
{
	MyTime resTime;
	if(timeInMinutes > time_.timeInMinutes)
		resTime.timeInMinutes = timeInMinutes - time_.timeInMinutes;
	else
		resTime.timeInMinutes = timeInMinutes - time_.timeInMinutes + 1440;
	resTime.minutesToTime();
	return resTime;
}
void MyTime::minutesToTime()
{
	time.hours = timeInMinutes % 1440 / 60;
	time.minutes = timeInMinutes % 60;
}
void MyTime::show()
{
	std::cout << "The time is: " << time.hours << ":" << time.minutes << std::endl;
}
void MyTime::showAmerican()
{
	if(time.hours < 13)
		std::cout << "The time is: " << time.hours << ":" << time.minutes << "am" << std::endl;
	else
		std::cout << "The time is: " << time.hours - 12 << ":" << time.minutes << "pm" << std::endl;
}
void MyTime::setTimeAmerican()
{
	std::cout << "(American format)" << std::endl;
	std::cout << "Enter the hours: ";
	unsigned h;
	std::cin >> h;
	if(h >= 0 && h <= 12)
		time.hours = h;
	else
	{
		std::cout << "Uncorrect time!" << std::endl;
		return;
	}

	std::cout << "Enter the minutes: ";
	unsigned m;
	std::cin >> m;
	if(m >= 0 && m <= 60)
		time.minutes = m;
	else
	{
		std::cout << "Uncorrect time!" << std::endl;
		return;
	}
	char t[3];
	std::cout << "Enter time mode(am/pm): ";
	std::cin >> t;
	if(strcmp(t, "am"))
		timeInMinutes = time.hours * 60 + time.minutes;
	else if (strcmp(t, "pm"))
	{
		timeInMinutes = time.hours * 60 + time.minutes + 12 * 60;
		time.hours += 12;
	}
}

void MyTime::setTime()
{
	std::cout << "Enter the hours: ";
	unsigned h;
	std::cin >> h;
	if(h >= 0 && h <= 24)
		time.hours = h;
	else
	{
		std::cout << "Uncorrect time!" << std::endl;
		return;
	}

	std::cout << "Enter the minutes: ";
	unsigned m;
	std::cin >> m;
	if(m >= 0 && m <= 60)
		time.minutes = m;
	else
	{
		std::cout << "Uncorrect time!" << std::endl;
		return;
	}

	timeInMinutes = time.hours * 60 + time.minutes;
}