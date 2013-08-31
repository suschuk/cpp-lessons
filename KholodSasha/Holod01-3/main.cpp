#include <ctime>
#include <iostream>
#include "MyMatrix.h"
#include "MyVector.h"
using namespace std;
MyMatrix operator* (double x, MyMatrix matrixObj)
{
	return matrixObj * x;
}

int main()
{
	srand(time(NULL));

	MyMatrix m1(3, 3);
	MyMatrix m2(3, 3);

	m1.init();
	m2.init();

	m1.showMatrix();
	m2.showMatrix();

	cout << "m3 = m1 + m2;" << endl;
	MyMatrix m3;
	m3 = m1 + m2;
	m3.showMatrix();

	cout << "m4 = m1 * m2;" << endl;
	MyMatrix m4;
	m4 = m1 * m2;
	m4.showMatrix();

	cout << "m4 = m1 * 5;" << endl;
	m4 = m1 * 5;
	m4.showMatrix();
	
	cout << "m4 = 10 * m1;" << endl;
	m4 = 10 * m1;
	m4.showMatrix();

	m4.setCol(5);
	m4.setRow(5);
	m4.init();
	m4.showMatrix();

	cout << "m4[2][3]" << endl;
	cout << m4[2][3] << endl;

	MyVector v1, v2;
	v1.showMatrix();
	v1.init();
	v2.init();
	v1.showMatrix();
	v2.showMatrix();

	cout << "v2 = v1 + v2;" << endl;
	v2 = v1 + v2;
	v2.showMatrix();

	cout << "m1 = v1 * v2;" << endl;
	m1 = v1 * v2;
	m1.showMatrix();

	cout << "m1 = m1 * v1;" << endl;
	m1 = m1 * v1;
	m1.showMatrix();
	
	return 0;
}