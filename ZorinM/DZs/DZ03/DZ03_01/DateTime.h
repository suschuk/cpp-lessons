#ifndef DATETIME_H
#define DATETIME_H

class DateTime
{
private:
	time_t d_t;
public:
	DateTime() : d_t(time(0))
	{};
	DateTime(time_t t) : d_t(t)
	{};
	DateTime(int, int, int, int, int, int);
	
	void set();
	void show() const;
	bool checkDT(tm) const;

	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getHours() const;
	int getMins() const;
	int getSecs() const;
};



#endif