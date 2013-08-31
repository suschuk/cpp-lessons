#include "../Date/Date.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	cout << "Default date: " << endl;
	Date first;
	first.print();

	cout << "Now: " << endl;
	time_t timer;
	time(&timer);
	Date now(timer);
	now.print();
	
	cout << "5491230111 seconds: " << endl;
	time_t tmp = 5491230111;
	Date inSec(tmp);
	inSec.print();
	
  	cout << "first = now, first.print() " << endl;
  	first = now;
  	first.print();

	TimeSpan A(10,10,10,10);
	TimeSpan B(1,1,1,1);

	cout << "now + 10 days 10 hours 10 minutes 10 seconds " << endl;
	now+A;
	now.print();

	cout << "now - 1 day 1 hour 1 minute 1 second " << endl;
	now-B;
	now.print();

	return 0;
}