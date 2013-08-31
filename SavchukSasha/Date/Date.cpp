#include "Date.h"	
#include <iostream>
#include <ctime>


Date::Date(){
	month[0] = 31; month[1] = 28; month[2] = 31; month[3] = 30; month[4] = 31; month[5] = 30; 
	month[6] = 31; month[7] = 31; month[8] = 30; month[9] = 31; month[10] = 30; month[11] = 31;
	day = 0;
}

int Date::setDate(int year, int month, int day){
	if (this->month[month-1] < day || month > 12){
		return -1;
	}
	for (int i = 1; i < year; ++i){
		if (isLeapYear(i)){
			this->day += 366;
		}else{
			this->day += 365;
		}
	}
	for (int i = 1; i < month; ++i){
		if (isLeapYear(year)){
			(i == 2)? this->day += (this->month[i-1]+1) : this->day += this->month[i-1];
		}else{
			this->day += this->month[i-1];
		}
	}
	this->day += day-1;
	return this->day;
}

void Date::setDateOfDay(int day){
	this->day = day;
}

int Date::getDate() const{
	return day;
}

int Date::getCurrentDate() {
	Date current;
	return (current.setDate(1970,1,1))+(time(NULL)/60/60/24)-10;
}

int Date::getYear() const{ 
	int year = 1;
	for (int i = 1; i <= this->day; ++i){
		if (isLeapYear(year)){
			if (i%366==0)
				year++;
		}else{
			if (i%365==0){
				year++;
				i+=364;
			}
		}
	}
	return year;
}

int Date::getMonth() const{ 
	int year = 1, month = 1;
	for (int i = 1, m = 1; i <= this->day; ++i, ++m){
		if (isLeapYear(year)){
			if(m % (this->month[month-1]+1) == 0 && month != 2){
				month++;
				m = 1;
			}else if (m % (this->month[month-1]+2) == 0 && month == 2){
				month++;
				m = 1;
			}
			if (i%366==0){
				year++;
				month = m = 1;
			}
		}else{
			if(m % (this->month[month-1]+1) == 0){
				month++;
				m = 1;
			}
			if (i%365==0){
				year++;
				month = m = 1;
			}
		}
	}
	return month;
}

int Date::getDay() const{
	int year = 1, month = 1, day = 1;
	for (int i = 1, m = 1, d = 1; i <= this->day; ++i, ++d, ++m){
		day=d;
		if (isLeapYear(year)){
			if(m % this->month[month-1]+1 == 0 && month != 2){
				month=m;
				day = d = m = 1;
			}else if (m % (this->month[month-1]+2) == 0 && month == 2){
				month=m;
				day = d = m = 1;
			}
			if (i%366==0){
				year++;
				day = d = m = 1;
				month = 1;
			}
		}else{
			if(m % (this->month[month-1]+1) == 0){
				month++;
				day = d = m = 1;
			}
			if (i%365==0){
				year++;
				day = d = m = 1;
				month = 1;
			}
		}
	}
	return day;
}

Date::Date (Date & a){
	this->setDateOfDay(a.getDate()); 
}

Date Date::operator-(Date & inputDate){
	Date tmp;
	tmp.setDateOfDay(this->getDate()-inputDate.getDate());
	return tmp;
}

Date Date::operator+(Date & inputDate){
	Date tmp;
	tmp.setDateOfDay(this->getDate()+inputDate.getDate());
	return tmp;
}
/*  
1: ddmmyyyy
2: yyyymmdd
3: dd month yyyy
*/

char* Date::format(int f){	
	char* nameMonth[12] = {"January","February","March","May","June","July","Augus","September","October","November","December"};
	strData = new char[20];
	strData[0] = 0; 
	char buffer[5]; 
	
	if(f==1){
		strcat(strData, itoa(this->getDay(), buffer, 10));
		strcat(strData, ".");
		strcat(strData, itoa(this->getMonth(), buffer, 10));
		strcat(strData, ".");
		strcat(strData, itoa(this->getYear(), buffer, 10));
	}else if (f==2){
		strcat(strData, itoa(this->getYear(), buffer, 10));
		strcat(strData, ".");
		strcat(strData, itoa(this->getMonth(), buffer, 10));
		strcat(strData, ".");
		strcat(strData, itoa(this->getDay(), buffer, 10));
	}else if (f==3){
		strcat(strData, itoa(this->getDay(), buffer, 10));
		strcat(strData, " ");
		strcat(strData, nameMonth[this->getMonth()-2]);
		strcat(strData, " ");
		strcat(strData, itoa(this->getYear(), buffer, 10));
	}
	
	return strData ;
}

bool Date::isLeapYear(unsigned int year) const
{
	if ((year % 4) == 0 && (year % 100) != 0 || (year % 400) == 0)
	{
		return false;
	}
	return false;
}
Date::~Date(){
	if(!strData)
		delete [] strData;
}