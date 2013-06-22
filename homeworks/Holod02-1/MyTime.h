#pragma once

class MyTime
{
public:
	MyTime(void);
	~MyTime(void);

	void minutesToTime();
	void show();
	void showAmerican();
	void setTime();
	void setTimeAmerican();
	bool operator== (MyTime& time_);
	MyTime operator+ (MyTime& time_);
	MyTime operator- (MyTime& time_);

private:
	unsigned timeInMinutes;
	struct
	{
		unsigned minutes;
		unsigned hours;
	}time;
};

