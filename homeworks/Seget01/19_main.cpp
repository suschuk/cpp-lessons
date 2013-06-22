/*
1. Разработать класс Date для представления даты (день, месяц, год). 
Реализовать методы для доступа к полям (с контролем допустимости аргументов!).
Определить конструктор с параметрами для удобного пользования классом, методы считывания даты с клавиатуры и печати ее на экране. 

2. Доработать разработанный ранее класс Date, определив в нем конструктор по умолчанию, создающий «дату по умолчанию» (например, 1970/01/01).

3. Design a class called Date. The class should store a date in three integers: month, day, and year.
There should be member functions to print the date in the following forms:
12/25/2012			December 25, 2012			25 December 2012
Demonstrate the class by writing a complete program implementing it.
Input Validation: Do not accept values for the day greater than 31 or less than 1.
Do not accept values for the month greater than 12 or less than 1. 

4. Write a class named Employee that has the following member variables:
 - name. A string that holds the employee's name. 
 - idNumber. An int variable that holds the employee's ID number. 
 - department. A string that holds the name of the department where the employee works. 
 - position. A string that holds the employee's job title.
The class should have the following constructors:
 - A constructor that accepts the following values as arguments and assigns them to the appropriate member variables:
 employee's name, employee's ID number, department, and position. 
 - A constructor that accepts the following values as arguments and assigns them to the appropriate member variables:
 employee's name and ID number. The department and position fields should be assigned an empty string (""). 
 - A default constructor that assigns empty strings ("") to the name, department, and position member variables, and 0 to the idNumber member variable.
Write appropriate mutator functions that store values in these member variables and accessor functions
that return the values in these member variables. Once you have written the class,
write a separate program that creates three Employee objects to hold the following data.

Name 			ID Number 	Department 		Position 
------------------------------------------------
Susan Meyers	47899 		Accounting 		Vice President 
Mark Jones		39119 		IT 				Programmer 
Joy Rogers		81774 		Manufacturing 	Engineer

The program should store this data in the three objects and then display the data for each employee on the screen.
// Tony Gaddis, p.791
*/

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
//#include <ctime>
//#include <cmath>
//#include <fstream>
//#include <Windows.h>
using namespace std;
#include "19_Date.h"
#include "19_Employee.h"
//----------------------------------------------------------------------------------------------
// Главная ФУНКЦИЯ
//----------------------------------------------------------------------------------------------
void main()
{
	// Кириллица в консоли
	// Есть один весомый недостаток у данных функций — они работают со шрифтом Lucida Console.
	// По умолчанию в консоли стоит шрифт Consolas. Поэтому в командной строке необходимо настроить используемый шрифт.
	// Для этого открываем cmd, заходим в свойства, в закладке Шрифт выбираем Lucida Console, нажимаем ОК
    //SetConsoleCP(1251);				// установка кодовой страницы win-cp 1251 в поток ввода
    //SetConsoleOutputCP(1251);			// установка кодовой страницы win-cp 1251 в поток вывода

	// Устанавливаем Локаль для потока Вывода
	setlocale(LC_CTYPE, "rus"); // не функционирует с потоком ввода
    /*
	cout << "--------------------------" << endl;
	cout << "Task 19-1, 19-2:" << endl;
	cout << "--------------------------" << endl;
	Date date1;					// Создаем ОБЪЕКТ класса Date и называем его date1
	date1.showDate();
	Date date2(23, 03, 1990);
	date2.showDate();
	Date date3(35, 15, -1990);
	date3.showDate();

	cout << "--------------------------" << endl;
	cout << "Task 19-3:" << endl;
	cout << "--------------------------" << endl;
	date2.showDate_1();
	date2.showDate_2();
	date2.showDate_3();

	cout << "--------------------------" << endl;
	cout << "Task 19-4:" << endl;
	cout << "--------------------------" << endl;
    */
	int size = 5;
	// Объявление одномерного динамического массива структур на size элементов:
	Employee *employeeDB = new Employee [size];

	employeeDB[0].setEmployee( "Susan Meyers",	47899, "Accounting", "Vice President" );
	employeeDB[1].setEmployee( "Mark Jones",	39119, "IT", "Programmer" );
	employeeDB[2].setEmployee( "Joy Rogers",	81774, "Manufacturing", "Engineer" );

	employeeDB->showEmployees( employeeDB, size );

	// Удаление Базы Данных из Динамической памяти.
	// Высвобождение памяти отводимой под одномерный динамический массив структур:
	delete [] employeeDB;

//----------------------------------------------------------------------------------------------
}	// КОНЕЦ ПРОГРАММЫ - Main
//----------------------------------------------------------------------------------------------