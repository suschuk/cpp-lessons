#ifndef DATE_H
#define DATE_H

// enumerators
enum printFormat {SLASH = 0, MONTH_FIRST = 1, DAY_FIRST = 2};
enum MONTHS {JANUARY = 1, FEBRUARY = 2, MARCH = 3, APRIL = 4, MAY = 5, JUNE = 6, JULY = 7, 
			 AUGEST = 8, SEPTEMBER = 9, OCTOBER = 10, NOVEMBER = 11, DECEMBER = 12};
enum CHK_DATE {CORRECT_DATE = 0, INC_DAY = 1, INC_MONTH = 2, INC_YEAR = 3};

// Date class
class Date
{
public:
	// constructors
	Date ();
	Date (int inDay, int inMonth, int inYear);
	Date::Date (const Date& d);

	// setters 
	void setDay (int inDay);
	void setMonth (int inMonth);
	void setYear (int inYear);

	// getters
	int getDay () const;
	int getMonth () const;
	int getYear () const;

	// set&check date
	void strToDate (char* date_str);
	bool checkDayOfMonth(int day, int month);
	CHK_DATE Date::checkDate ();
	int daysFromDate();
	
	// date output
	void printDate (printFormat f);

	//overloaded operators
	bool operator== (const Date& inDate);
	int operator-(Date& inDate);
	void operator+(int inDays);

	//bool operator> (const Date& inDate);
	//bool operator< (const Date& inDate);

	// destructor
	~Date();

private:
	int day;
	int month;
	int year;
};

#endif