#include <iostream>
#include"MyTime.h"
using namespace std;

int main()
{
	MyTime time, t1, t2;
	time.setTime();
	t1.setTimeAmerican();
	t2 = t1 + time;

	time.show();
	time.showAmerican();
	if((time + t1) == t2)
		t2 = time - t1;

	time.show();
	t2.show();
	t1.show();
	
	return 0;
}