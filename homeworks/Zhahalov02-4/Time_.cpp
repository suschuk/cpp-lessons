#include "Time_.h"


Time_::Time_(void)
{
	Seconds = 0;
}

Time_::Time_(int seconds)
{
	Seconds = seconds;
}


Time_::~Time_(void)
{
}

void Time_::PrintTime(Format f) const
{
	int hou = Seconds / 3600;
	int min = Seconds / 60 - hou * 60;
	int sec = Seconds % 60;	

	if(f == Format_24)
	{
		std::cout << std::setfill('0') << std::setw(2) << hou << ":"<< std::setw(2) << min << ":"<< std::setw(2) << sec << "\r\n";
	}
	else
	{
		if(hou > 12)
		{
			std::cout << std::setfill('0') << std::setw(2) << hou - 12 << ":"<< std::setw(2) << min << ":" << std::setw(2) << sec << " pm\r\n";
		}
		else
		{
			std::cout << std::setfill('0') << std::setw(2) << hou << ":"<< std::setw(2) << min << ":" << std::setw(2) << sec << " am\r\n";
		}

	}


}
