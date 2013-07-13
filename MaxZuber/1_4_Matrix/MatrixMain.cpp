#include "Matr.h"
#include <iostream>
#include <ctime>

using namespace std;

inline void printLine();

int main()
{
	srand(unsigned(time(0)));

	int row1 = 3;
	int col1 = 2;

	int row2 = 2;
	int col2 = 3;

	int vecSize = col1;

	Matr matrix1(row1, col1), matrix2(row2, col2), matrix3, matrix4(row1, col1);
	vect v1(vecSize);

	v1.fillRanom();						//fill vector and matrix random numbers
	matrix1.fillRandom();				//
	matrix2.fillRandom();				//
	matrix4.fillRandom();

	cout << "\nMatrix + Matrix:\n";		//Matrix + Matrix
	cout << "\nMatrix1:";
	matrix1.showM();

	cout << "\nMatrix2:";
	matrix4.showM();

	matrix3 = matrix1 + matrix4;
	cout << "\n=\n";
	matrix3.showM();
	printLine();

	cout << "\n\n\nMatrix x Matrix:\n";		//Matrix * Matrix

	cout << "\nMatrix1:";
	matrix1.showM();

	cout << "\nMatrix2:";
	matrix2.showM();

	matrix3 = matrix1 * matrix2;

	cout << "\n=\n";
	matrix3.showM();
	printLine();

	cout << "\n\n\nMatrix x Vector:\n";		//Matrix * vector

	cout << "\nMatrix:";
	matrix1.showM();

	cout << "\nVector:\n";
	v1.printVect();

	cout << "\n=\n";

	matrix3 = matrix1 * v1;
	matrix3.showM();
	printLine();


	return 0;
}

inline void printLine()
{
	cout << "\n____________________________\n" ;
}