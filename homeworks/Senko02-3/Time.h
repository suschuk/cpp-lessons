#ifndef TIME_H
#define TIME_H

using std::ostream;
using std::istream;

enum t_format{UA = 0, US = 1};

static const int SEC_DAY = 86400;
static const int SEC_HOUR = 3600;
static const int SEC_MINUTE = 60;

class Time
{
public:
	Time();
	Time(int inTime, t_format = UA);
	Time(const Time& inTime);

	friend ostream& operator<<	(ostream& out, const Time& inTime); 
	friend istream& operator>>(istream& in, Time& inTime);

	Time& operator= (const Time& inTime);
	Time& operator+= (const Time& inTime);
	Time& operator-= (const Time& inTime);
	Time operator+ (const Time& inTime);
	Time operator- (const Time& inTime);

	bool operator> (const Time& inTime);
	bool operator>= (const Time& inTime);
	bool operator< (const Time& inTime);
	bool operator<= (const Time& inTime);
	bool operator== (const Time& inTime);
	bool operator!= (const Time& inTime);

	void changeFormat();
	
	~Time();

private:
	int t;
	t_format f;
};

#endif