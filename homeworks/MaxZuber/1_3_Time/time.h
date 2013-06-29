#pragma once
class time
{
public:
	time(): sec_(0), am_pm(true) {};

	void getTime();
	void printTime() const;
	bool operator==(const time&);

	void convertTime();

	unsigned getTimeinSec()const;
private:
	unsigned sec_;
	bool am_pm; // true am/pm, false 24:00
};

