#pragma once

#include <cstring>
#include <cstdio>
#include <iostream>
#include <iomanip>

class Time_
{
private:

	int Seconds;

public:

	enum Format{
		Format_24 = 0,
		Format_12
	};

	Time_(void);
	Time_(int seconds);
	~Time_(void);

	void PrintTime(Format) const;
	void SetTime();

	Time_ operator +(const Time_ T)
	{
		return Time_(Seconds + T.Seconds);
	}

	Time_ operator -(const Time_ T)
	{
		return Time_(Seconds - T.Seconds);
	}

	bool operator >(const Time_ T)
	{
		return(Seconds > T.Seconds);
	}

	bool operator <(const Time_ T)
	{
		return(Seconds < T.Seconds);
	}
};

