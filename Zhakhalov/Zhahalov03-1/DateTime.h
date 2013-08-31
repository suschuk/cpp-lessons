#pragma once

#include <ctime>

class DateTime
{
public:

	struct Date{
		unsigned year;
		unsigned month;
		unsigned day;
		unsigned dow; // Day of week
	};

	struct Time{
		unsigned hour;
		unsigned minute;
		unsigned second;
	};

	DateTime(void);

	//accessors

	Date GetDate() const;
	Time GetTimeUTC() const;
	Time GetTimeLocal() const;
	time_t GetTime() const;

	//mutators
	void Current();

	void SetTime(const Time&);
	void SetTime(const time_t);
	void SetDate(const Date&);

private:

	time_t t;
};

