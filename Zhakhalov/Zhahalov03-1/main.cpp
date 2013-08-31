#include <ctime>
#include "DateTime.h"
#include "TimeSpan.h"

void main()
{

	DateTime DT;
	DT.Current();

	DateTime::Time myTime = DT.GetTimeLocal();
	DateTime::Date myDate = DT.GetDate();

	myTime.hour = 23;

	DT.SetTime(myTime);

	myDate.year = 2000;
	myDate.month = 1;
	myDate.day = 29;

	DT.SetDate(myDate);

	TimeSpan TS1, TS2;

	TS2.Current();

	TS1.SetTime(myTime);

	TimeSpan TS3 = TS1 + TS2;

	DateTime::Time mySpan = TS3.GetTimeUTC();


}