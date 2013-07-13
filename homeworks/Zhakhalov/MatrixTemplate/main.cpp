#include "TemplateMatrix.h"

void main()
{
	Matrix<int> A(3,5);
	Matrix<int> B(1,3);

	Matrix<int> C = A + B;
	Matrix<int> D = A * B;
	Matrix<int> E = A - B;
}