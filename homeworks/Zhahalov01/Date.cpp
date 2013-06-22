#include "Date.h"


Date::Date(void)
{
	this->Year = 1970;
	this->Mon = 1;
	this->Day = 1;
}

void Date::setYr(int yr){

	if(yr < 1){

	this->Year = 1;
	return;
	}

	this->Year = yr;

}

//***************************************** SET

void Date::setMon(int mon){

	if(mon < 1){

	this->Mon = 1;
	return;
	}

	if(mon> 12){

	this->Mon = 12;
	return;
	}

	this->Mon = mon;
}

void Date::setDay(int day){

	if(day < 1){

	this->Day = 1;
	return;
	}

	if(day> 31){

	this->Day = 31;
	return;
	}

	this->Day = day;
}

//*********************************** GET
int Date::getYr() const{

	return this->Year;

}

int Date::getMon() const{

	return this->Mon;
}

int Date::getday() const{

	return this->Day;
}

//*************************************************** SHOW

void Date::showDate1(){

	printf("%02d/%02d/%d\r\n",this->Day, this->Mon, this->Year);
}

void Date::showDate2(){
	const char *MonName[12] = {
				"January",
				"February",
				"March",
				"April",
				"May",
				"June",
				"July",
				"August",
				"September",
				"November",
				"December"
				};

	printf("%s %02d, %d\r\n",MonName[this->Mon - 1], this->Day, this->Year);

}

void Date::showDate3(){

	const char *MonName[12] = {
				"January",
				"February",
				"March",
				"April",
				"May",
				"June",
				"July",
				"August",
				"September",
				"November",
				"December"
				};

	printf("%02d %s %d\r\n", this->Day, MonName[this->Mon - 1], this->Year);
}


Date::~Date(void)
{
}
