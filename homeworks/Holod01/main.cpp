#include<iostream>
#include"Date.h"
using namespace std;
int main()
{
	Date date(12, 3, 1440);
	date.getInfoOnScreen();

	Date myDate;
	myDate.setDateFromKeyboard();
	myDate.getInfoOnScreen();

	return 0;
}