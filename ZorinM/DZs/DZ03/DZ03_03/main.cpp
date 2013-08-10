#include <iostream>
#include <ctime>

#include "Matrix.h"

using std::cout;

int main()
{
	srand(unsigned(time(0)));

	// Matrix <int> mtrx1;
	Matrix <int> mtrx1 (3, 5);
	mtrx1.show();

	cout << "\n------------------------------------------------\n";
	Matrix <int> mtrx2 = mtrx1;
	mtrx2.show();

	cout << "\n------------------------------------------------\n";
	mtrx2.fill();
	mtrx2.show();

	cout << "\n------------------------------------------------\n";
	mtrx2.fill('t');
	mtrx2.show();

	cout << "\n------------------------------------------------\n";
	mtrx2.set_rows(5);
	mtrx2.show();

	cout << "\n------------------------------------------------\n";
	mtrx2.set_cols(6);
	mtrx2.show();

	cout << "\n------------------------------------------------\n";
	mtrx2 = mtrx1;
	mtrx2.show();

	cout << "\n------------------------------------------------\n";
	cout << mtrx2[1][1];


	cout << "\n------------------------------------------------\n";
	Matrix <int> mtrx3 (3, 5);
	Matrix <int> mtrx4;

	mtrx4 = mtrx1 + mtrx3;
	mtrx4.show();

	cout << "\n------------------------------------------------\n";
	mtrx4 += mtrx1;
	mtrx4.show();

	cout << "\n------------------------------------------------\n";
	mtrx3 = mtrx4 - mtrx1;
	mtrx3.show();

	cout << "\n------------------------------------------------\n";
	mtrx4 -= mtrx1;
	mtrx4.show();

	cout << "\n------------------------------------------------\n";
	Matrix <int> mtrx5 (5, 3);
	cout << "\n------------------------------------------------\n";
	mtrx4.show();
	cout << "\n";
	mtrx5.show();
	cout << "\n";

	mtrx1 = mtrx4 * mtrx5;
	mtrx1.show();

	cout << "\n------------------------------------------------\n";
	mtrx4 *= mtrx5;
	mtrx4.show();

	cout << "\n------------------------------------------------\n";
	cout << mtrx4;

	cout << "\n------------------------------------------------\n";
	cout << mtrx2;

	cout << "\n~\n";
	cout << ~mtrx2;

	cout << "\n\n";
	return 0;
}