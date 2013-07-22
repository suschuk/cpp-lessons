#ifndef TIME_H
#define TIME_H
#include <iostream>

using std::ostream;
using std::istream;

class TimeAmPm_;

class Time_
{
private:
	int hours;
	int mins;
public:
	Time_();
	Time_(int, int);

	void correctTime_(Time_&);
	void Convert(const TimeAmPm_&);

	Time_ operator+ (const Time_&);
	Time_ operator- (const Time_&);
	bool operator > (const Time_&);
	bool operator < (const Time_&);
	bool operator == (const Time_&);
	friend ostream& operator << (ostream&, const Time_&);
	friend istream& operator >> (istream&, Time_&);
};

class TimeAmPm_
{
private:
	int hours;
	int mins;
	char* pref;

public: 
	TimeAmPm_();
	TimeAmPm_(int, int, char*);
	friend ostream& operator << (ostream&, const TimeAmPm_&);
	void operator() (int, int, char*);

	friend Time_;
};

#endif	