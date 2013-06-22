#pragma once		// ¬кл. один раз
//----------------------------------------------------------------------------------------------
// ќбъ€вление  ласса: Employee
//----------------------------------------------------------------------------------------------
class Employee
{
	private:
		// member variables				(элементы данных, переменные-члены класса)
		//-------------------------------------------------------------------------
		string name;
		int	 id_number;
		string department;
		string position;

	public:
		// member functions				(методы класса)
		//-------------------------------------------------------------------------
		// contructors					(конструкторы)
		// default constructor			(конструктор по умолчанию)
		Employee();
		// 1 overloaded constructor		(перегруженный конструктор)
		Employee( string name, int id_number, string department, string position );
		// 2 overloaded constructor		(перегруженный конструктор)
		Employee( string name, int id_number );


		// setters						(mutator functions)
		void setName( string name );
		void setId_number( int id_number );
		void setDepartment( string department );
		void setPosition( string position );
		void setEmployee( string name, int id_number, string department, string position );

		// getters						(accessor functions)
		string getName();
		int getId_number();
		string getDepartment();
		string getPosition();

		// user functions				(функции пользовател€)
		void showEmployees( Employee *employeeDB, int size );
				
		// destructor					(деструктор)
		~Employee();
};