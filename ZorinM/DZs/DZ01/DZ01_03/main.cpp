/*	 —оздать класс дл€ работы с матрицами. ѕредусмотреть, как минимум, 
	 функции дл€ сложени€ матриц, умножени€ матриц, транспонировани€ матриц, 
	 присваивани€ матриц друг другу, установка и получение произвольного элемента 
	 матрицы. Ќеобходимо перегрузить соответствующие операторы.
*/

#include "Matrix_.h"
#include <iostream>

using namespace std;


int main()
{
	Matrix_ mtrx1 (5, 10);

	cout << "\nshowMtrx() demo:\n";
	mtrx1.showMtrx();

	cout << "\noverloaded operator '<<' demo:\n";
	cout << mtrx1;
	
	Matrix_ mtrx2;
	mtrx2 = mtrx1;
	cout << "\noverloaded operator '=' demo:\n";
	cout << mtrx2;

	cout << "\noverloaded operator '--' demo (matrix transpose):\n";
	cout << --mtrx2;
	
	cout << "\nmax element of the matrix is:\n";
	cout << mtrx2.getMax();
	
	cout << "\nmin element of the matrix is:\n";
	cout << mtrx2.getMin() << "\n";

	int r = 0, c = 4;
	cout << "\noverloaded operator '[]' (matrix[" << r << "][" << c << "]) demo:\n";
	cout << mtrx2[r][c] << "\n";

	Matrix_ mtrx3(10, 5);
	cout << "\noverloaded operator '+' demo:\n";
	cout << mtrx2;
	cout << "+\n";
	cout << mtrx3;
	cout << "=\n";
	cout << mtrx2 + mtrx3 << "\n";
	cout << "\n===========================================================\n\n";

	Matrix_ mtrx4(2, 4);
	Matrix_ mtrx5(4, 1);
	
	mtrx4[0][0] = -1;	
	mtrx4[0][1] = 0;	
	mtrx4[0][2] = 3;	
	mtrx4[0][3] = 6;

	mtrx4[1][0] = 2;	
	mtrx4[1][1] = 1;	
	mtrx4[1][2] = 0;	
	mtrx4[1][3] = -4;

	mtrx5[0][0] = -1;	
	mtrx5[1][0] = 2;	
	mtrx5[2][0] = 0;	
	mtrx5[3][0] = 3;

	cout << "\noverloaded operator '*' demo:\n";
	cout << mtrx4;
	cout << "*\n";
	cout << mtrx5;
	cout << "=\n";
	cout << mtrx4 * mtrx5 << "\n";
	
	cout << "\n===========================================================\n\n";
	return 0;
}