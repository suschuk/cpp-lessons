#include <iostream>
#include <ctime>
#include "DateTime.h"

using std::cout;
using std::endl;

char* month_str[12] = { "January", "February", 
						"March", "April", "May", 
						"June", "July", "August", 
						"September", "October", "November", "December"};

int main()
{
	DateTime dt1;
	DateTime dt2(2011, 5, 2, 10, 0, 0);
	dt1.show();
	dt2.show();

	cout << "\ndt1 year = " << dt1.getYear();
	cout << "\ndt1 month = " << month_str[dt1.getMonth() - 1];
	cout << "\ndt1 day = " << dt1.getDay();
	cout << "\ndt1 hours = " << dt1.getHours();
	cout << "\ndt1 mins = " << dt1.getMins();
	cout << "\ndt1 secs = " << dt1.getSecs();
	
	cout << endl;
	cout << "\ndt2 year = " << dt2.getYear();

	DateTime dt3(2013, 2, 29, 10, 0, 0);
	// dt1.set();

	return 0;
}

// source:
// http://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
// http://www.cplusplus.com/reference/ctime/localtime/