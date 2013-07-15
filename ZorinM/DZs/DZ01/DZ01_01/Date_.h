#ifndef DATE_H
#define DATE_H

class Date_
{
private:
	int day;
	int month;
	int year;
public:
	Date_();
	Date_(int, int, int);
	Date_(const Date_&);

	void setDate(int, int, int);
	void showDate(int = 0) const;

	bool checkDate();
	// ввід дати з клавіатури
	void enterDate();
};

#endif
