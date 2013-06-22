#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
	Array A(4);

	A[0] = 9;	A[1] = 9;
	A[2] = 9;	A[3] = 9;
	
	Array B(4);
	
	B[0] = 5;	B[1] = 5;
	B[2] = 5;	B[3] = 5;

	cout << "A:\t" << A;
	cout << "B:\t" << B;
	
	Array C;
	Array D;

	C = A+B;
	cout << "C=A+B:\t" << C;

	D = A-B;
	cout << "D=A-B:\t" << D;

	C++;
	cout << "C++:\t" << C;

	D--;
	cout << "D--:\t" << D;
	
	return 0;
}