#include "Matrix.h"
#include <windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

Matrix* operator*(Matrix & m1, Matrix & m2)
{
	if (m1.getColumn() == m2.getRow())
	{
		Matrix* m3 = new Matrix( m1.getRow(), m2.getColumn() );

		for(int i = 0; i < m1.getRow(); ++i)
		{
			for (int j = 0; j < m2.getColumn(); ++j)
			{
				for (int k = 0; k < m1.getColumn(); ++k)
				{
					m3->matrix[i][j] = m3->matrix[i][j] + m1.matrix[i][k] * m2.matrix[k][j];
				}
			}
		}
		return m3;
	}
	else
	{
		cout << "Error !!!" << endl;
		return NULL;
	}
}


Matrix* operator+(Matrix & m1, Matrix & m2)
{
	if (m1.getColumn() == m2.getColumn() && m1.getRow() ==  m2.getRow())
	{
		Matrix* m3 = new Matrix( m1.getRow(), m2.getColumn() );

		for(int i = 0; i < m1.getRow(); ++i)
		{
			for (int j = 0; j < m1.getColumn(); ++j)
			{			
				m3->matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
			}
		}
		return m3;
	}
	else
	{
		cout << "Error !!!" << endl;
		return NULL;
	}
}

Matrix* operator-(Matrix & m1, Matrix & m2)
{
	if (m1.getColumn() == m2.getColumn() && m1.getRow() ==  m2.getRow())
	{
		Matrix* m3 = new Matrix( m1.getRow(), m2.getColumn() );

		for(int i = 0; i < m1.getRow(); ++i)
		{
			for (int j = 0; j < m1.getColumn(); ++j)
			{			
				m3->matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
			}
		}
		return m3;
	}
	else
	{
		cout << "Error !!!" << endl;
		return NULL;
	}
}

int menu() {
	int key=0; 
	int code;  
	do {
		system("cls");  
		key=(key+3)%3;  
		if (key==0) cout << setw(30) << left << "-> Множення матриць";        
		else  cout << setw(30) << left << "   Множення матриць"; 
		if (key==1) cout << setw(40) << left <<  "-> Додавання матриць"; 
		else  cout << setw(40) << left <<  "   Додавання матриць"; 
		if (key==2) cout << setw(40) << left <<  "-> Вiднiмання матриць"; 
		else  cout << setw(40) << left <<  "   Вiднiмання матриць"; 
		if (key==3) cout<<  "-> Вихiд"; 
		else  cout << "   Вихiд"; 
		code=getch();  
		if (code==224)
		{
			code=getch();
			if (code==77) key++; 
			if (code==75) key--; 
		}
	}while(code!=13 && code!=80); 

	system("cls");  
	return key; 
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	int column = 0, row = 0;

	switch(menu())
	{
	case 0:{
		cout << "Кiлькiсть стовпцiв матрицi 1: ";
		cin >> column;
		cout << "Кiлькiсть рядкiв матрицi 1: ";
		cin >> row;

		Matrix m1(row, column);
		m1.fill();
		m1.print();
		cout << endl;

		cout << "Кiлькiсть стовпцiв матрицi 2: ";
		cin >> column;
		cout << "Кiлькiсть рядкiв матрицi 2: ";
		cin >> row;

		Matrix m2(row, column);
		m2.fill();
		m2.print();
		cout << endl;

		Matrix* m3;
		m3 = m1 * m2;
		if (m3 != NULL)
		{
			cout << "Результат множення матриць: " << endl;
			m3->print();
		}
		_getch();
		break;}
	case 1:
		{
		cout << "Кiлькiсть стовпцiв матриць: ";
		cin >> column;
		cout << "Кiлькiсть рядкiв матриць: ";
		cin >> row;

		Matrix m1(row, column);
		m1.fill();
		m1.print();
		cout << endl;

		Matrix m2(row, column);
		m2.fill();
		m2.print();
		cout << endl;

		Matrix* m3;
		m3 = m1 + m2;
		if (m3 != NULL)
		{
			cout << "Результат додавання матриць: " << endl;
			m3->print();
		}
		_getch();
		break;
		}
	case 2:
		{
		cout << "Кiлькiсть стовпцiв матриць: ";
		cin >> column;
		cout << "Кiлькiсть рядкiв матриць: ";
		cin >> row;

		Matrix m1(row, column);
		m1.fill();
		m1.print();
		cout << endl;

		Matrix m2(row, column);
		m2.fill();
		m2.print();
		cout << endl;

		Matrix* m3;
		m3 = m1 - m2;
		if (m3 != NULL)
		{
			cout << "Результат вiднiмання матриць: " << endl;
			m3->print();
		}
		_getch();
		break;
		}
	case 3:
		return 0;
	}
	main();
	return 0;
}