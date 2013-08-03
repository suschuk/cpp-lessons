#include <iostream>
#include <ctime>

#include "Matrix.h"

using std::cout;

int main()
{
	srand(unsigned(time(0)));

	Matrix mtrx1 (3, 5);
	mtrx1.show();
	
	cout << "\n------------------------------------------------\n";
	mtrx1.fill(7);
	mtrx1.show();

	cout << "\n------------------------------------------------\n";
	cout << "mtrx1.show()\n";
	mtrx1.fill();
	mtrx1.show();

	cout << "\n------------------------------------------------\n";
	cout << "mtrx2.show()\n";
	Matrix mtrx2 = mtrx1;
	mtrx2.show();

	cout << "\n------------------------------------------------\n";
	cout << "mtrx1[1][1] = ";
	cout << mtrx1[1][1];

	cout << "\n------------------------------------------------\n";
	cout << "mtrx3 = mtrx1 + mtrx2\n";
	Matrix mtrx3 = mtrx1 + mtrx2;
	mtrx3.show();

	cout << "\n------------------------------------------------\n";
	cout << "mtrx3 = mtrx3 - mtrx2 and \"<<\" overloaded operator\n";
	mtrx3 = mtrx3 - mtrx2;
	cout << mtrx3;

	cout << "\n------------------------------------------------\n";
	cout << "cout << ^mtrx3\n";
	~mtrx3;
	cout << mtrx3;

	cout << "\n------------------------------------------------\n";
	cout << "set cols\n";
	mtrx3.set_cols(10);
	cout << mtrx3;

	cout << "\n------------------------------------------------\n";
	cout << "set rows\n";
	mtrx3.set_rows(10);
	cout << mtrx3;

	cout << "\n------------------------------------------------\n";
	Matrix mtrx4 (3, 5);
	mtrx4.fill();
	cout << mtrx4 << "\n+\n";
	cout << mtrx1 << "\n=\n";
	mtrx4 += mtrx1;
	cout << mtrx4;

	cout << "\n------------------------------------------------\n";
	cout << mtrx4 << "\n-\n";
	cout << mtrx1 << "\n=\n";
	mtrx4 -= mtrx1;
	cout << mtrx4;

	cout << "\n------------------------------------------------\n";
	Matrix mtrx5 (5, 3);
	mtrx5.fill();
	cout << mtrx5 << "\n*\n";
	cout << mtrx1 << "\n=\n";
	cout << mtrx5 * mtrx1;

	cout << "\n------------------------------------------------\n";
	cout << "\n mtrx5 *= mtrx2 \n";
	mtrx5 *= mtrx2;
	mtrx5.show();

	cout << "\n\n";

	return 0;
}