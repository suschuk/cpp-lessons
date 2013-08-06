#include <iostream>

#include "array_.h"

using std::cout;
using std::endl;


int main()
{
	array_ A1(5);
	for ( int i = 0; i < A1.get_size(); i++)
		A1[i] = i + 1;

	array_ A2(5);
	for ( int i = 0; i < A2.get_size(); i++)
		A2[i] = i + 2;

	array_ A3 = A1 + A2;
	cout << A1 << "+\n" << A2 << "= \n" << A3 << endl;

	A1 += A2;
	cout << "A1 += A2\n" << A1;

	cout << "\n------------------------------------------\n";
	A3 = A1 - A2;
	cout << A1 << "-\n" << A2 << "= \n" << A3 << endl;

	A1 -= A2;
	cout << "A1 -= A2\n" << A1;

	cout << "\n------------------------------------------\n";
	A3 = A1 + 5;
	cout << "A1 + 5\n" << A3;

	cout << "\n------------------------------------------\n";
	A3 = A1 - 5;
	cout << "A1 - 5\n" << A3;

	cout << endl << endl;

	return 0;
}