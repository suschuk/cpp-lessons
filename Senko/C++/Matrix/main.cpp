#include <iostream>
#include "matrix.h"

using namespace std;

int main ()
{
	Matrix A(2, 2, 5);
	Matrix B(2, 2, 1);
	Matrix C;
	Matrix D;
	Matrix E;
	Matrix F(2,4,9);
		
	cout << "Matrix A (default values): " << endl << A;
	cout << "Matrix B (default values): " << endl << B;
	cout << "Matrix F (default values): " << endl << F;


	cout << "Setting Matrix A, B, F values... " << endl;
	A(0,0) = -134;		A(0,1) = 2;
	A(1,0) = 3;			A(1,1) = 4;

	B(0,0) = 1;		B(0,1) = -9;
	B(1,0) = 6;		B(1,1) = 0;

	F(0,0) = 1; F(0,1) = 2; F(0,2) = 3; F(0,3) = 4;
	F(1,0) = 5; F(1,1) = 5; F(1,2) = 7; F(1,3) = 8;

	cout << "Matrix A: " << endl << A;
	cout << "Matrix B: " << endl << B;
	cout << "Matrix F: " << endl << F;
	
	cout << "Value (1,1) of Matrix A: " << endl;
	cout << A(1,1) << endl;

	cout << "Matrix C = A + B:" << endl;
	C = A + B;
	cout << C;

	cout << "Matrix D = A - B:" << endl;
	D = A - B;
	cout << D;

	cout << "Matrix E = A * B:" << endl;
	E = A * B;
	cout << E;

	cout << "Matrix E = A * 2:" << endl;
	E = A * 2;
	cout << E;

	cout << "Transpose Matrix F:" << endl;
	F.transp();
	cout << F;
			
	return 0;
}