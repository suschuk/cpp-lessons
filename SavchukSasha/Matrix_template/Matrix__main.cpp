#include "Matrix_.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(0)));
	Matrix_<int, 2, 3> m1;
	
	Matrix_<int, 3, 2> m2;

	Matrix_<int, 2, 2> m3;

	m3 = m1 * m2;
	cout << "\nm1 =\n";
	cout << m1 << endl;
	cout << "\nm2 =\n";
	cout << m2 << endl;
	cout << "\nm3 =\n";
	cout << m3;
	cout << "\nm3 x 2 =" << endl;
	m3 = m3 * 2;
	cout << m3 << endl;
	return 0;
}