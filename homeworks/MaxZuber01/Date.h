#pragma once
#ifndef DATE_H_
#define DATE_H_

	class Date
	{

	private:
		int day_;
		int month_;
		int year_;
	public:

		Date();
		Date(int day, int month, int year);
		void setDay();
		void setMonth();
		void setYear();

		int getDay() const;
		int getMonth() const;
		int getYear() const;

		void showInfoOne() const;
		void showInfoTwo() const;
		void showInfoThree() const;


	};
#endif