#include <iostream>
#include "date.h"

using namespace std;

int main()
{
	Date my_date;
	char date_str[20] = "01/02/2013";

	my_date.strToDate(date_str);

	cout << "Date 01.02.2013 in different formats:" << endl ;

	if (my_date.checkDate() == CORRECT_DATE)
	{
		my_date.printDate(MONTH_FIRST);
		my_date.printDate(DAY_FIRST);
		my_date.printDate(SLASH);
	}
	else
	{
		cout << "incorrect date" << endl;
	}	
	cout << endl <<"----------------------------------" << endl;
	cout << "Days between 31.12.2012 and 01.01.2014: "; 
	Date d1(31,12,2012);
	Date d2(01,01,2014);
	Date d3(01,01,2013);

	cout << d2 - d1 << endl;

	cout << endl <<"----------------------------------" << endl;
	cout << "100 days added to 01.01.2013: "; 
	d3+100;
	d3.printDate(SLASH);

	return 0;
}