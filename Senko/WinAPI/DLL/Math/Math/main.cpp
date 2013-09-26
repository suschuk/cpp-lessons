#include <iostream>
#include "complex.h"

using std::cout;
using namespace complex;

int main()
{
	Complex A(5, -2);
	Complex B(-3, 10);

	Complex C, D, E, F;

	cout << "A:\t " << A;
	cout << "B:\t " << B;
	
	C = A + B;
	cout << "C=A+B:\t " << C;

	D = A - B;
	cout << "D=A-B:\t " << D;
	
	E = A * B;
	cout << "E=A*B:\t " << E;

	F = A / B;
	cout << "F=A/B:\t " << F;

	return 0;
}