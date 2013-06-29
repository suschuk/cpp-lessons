//множення матриць і векторів
#include <iostream>
#include "matrix.h"


int main()
{
	std::cout << "Matrix * Matrix:\n";
	matrix one(3,4);
	one.showMatrix();
	std::cout << "\n";

	matrix two(4,5);
	two.showMatrix();
	std::cout << "\n";

	two=one*two;
	two.showMatrix();

	system("pause");
	system("cls");


	std::cout << "Matrix * Vector:\n";
	one.setMatrix(3,4);
	one.showMatrix();
	std::cout << "\n";

	two.setMatrix(4,1);//вектор
	two.showMatrix();
	std::cout << "\n";

	two=one*two;
	two.showMatrix();

	system("pause");
	system("cls");


	std::cout << "Vector * Matrix:\n";
	one.setMatrix(1,4);//вектор
	one.showMatrix();
	std::cout << "\n";

	two.setMatrix(4,5);
	two.showMatrix();
	std::cout << "\n";

	two=one*two;
	two.showMatrix();

	system("pause");
	return 0;
}