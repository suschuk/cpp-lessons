#include "Matrix.h"
#include <iostream>

void printMatrix(const Matrix &A)
{
	for(unsigned y = 0; y < A.Height(); ++y)
	{
		for(unsigned x = 0; x < A.Width(); ++x)
		{
			printf("%3.1f ",A.GetVal(x,y));
		}

		printf("\r\n");
	}
}

void main()
{
	Matrix A(4,3);
	Matrix B(5,4);

	float n = 1.0f;

	for(unsigned y = 0; y < A.Height(); ++y)
	{
		for(unsigned x = 0; x < A.Width(); ++x)
		{
			A.SetVal(n,x,y);
			n += 1.0f;
		}
	}

	

	for(unsigned y = 0; y < B.Height(); ++y)
	{
		for(unsigned x = 0; x < B.Width(); ++x)
		{
			B.SetVal(n,x,y);
			n += 1.0f;
		}
	}
	/*
	printMatrix(A);
	printf("\r\n+\r\n");
	printMatrix(B);
	printf("\r\n----------------------------\r\n");

	Matrix_ C = A + B;
	printMatrix(C);

	printf("\r\n");

	printMatrix(A);
	printf("\r\n-\r\n");
	printMatrix(B);
	printf("\r\n----------------------------\r\n");

	Matrix_ D = A - B;
	printMatrix(D);

	printMatrix(A);

	A.Transpone();
	printf("\r\n----------------------------\r\n");

	printMatrix(A);*/

	printMatrix(A);
	printf("\r\n+\r\n");
	printMatrix(B);
	printf("\r\n----------------------------\r\n");

	Matrix C = A * B;
	printMatrix(C);
}