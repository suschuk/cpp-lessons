
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Employee.h"

int main(){

	using namespace std; 

	Date date;

	int buf = 0;

	std::cout << "Enter Year: ";
	std::cin >> buf;
	date.setYr(buf);

	std::cout << "Enter Month: ";
	std::cin >> buf;
	date.setMon(buf);

	std::cout << "Enter Day: ";
	std::cin >> buf;
	date.setDay(buf);

	date.showDate1();
	date.showDate2();
	date.showDate3();

	cout << "Enter amount of EMPLOYERS: ";
	int amount = 0;	cin >> amount;
	
	Employee *staff = new Employee[amount];

	for (int i = 0; i < amount; i++)
	{
		char cBuf[256];
		int  iBuf = 0;

		cout << "\r\nField #" << i + 1 << endl;

		cout << "Enter Name: ";
		cin >> cBuf;

		staff[i].setName(cBuf);

		cout << "Enter ID: ";
		cin >> iBuf;

		staff[i].setID(iBuf);

		cout << "Enter Departament: ";
		cin >> cBuf;

		staff[i].setDepartment(cBuf);

		cout << "Enter Position: ";
		cin >> cBuf;

		staff[i].setPosition(cBuf);
	}

	for (int i = 0; i < amount; i++)
	{
		staff[i].showEmployee();
	}

	delete [] staff;
	staff = NULL;

	return 0;
}