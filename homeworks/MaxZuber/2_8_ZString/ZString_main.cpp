#include <iostream>

#include "ZString.h"

using std::cout;
using std::cin;
using std::endl;

void test_zstring();


int main()
{
test_zstring();

	return 0;
}


void test_zstring()
{
	ZString s1 = ZString();
	cout << s1 << endl;
	cout << "s1 is empty: " <<  std::boolalpha << s1.empty() << endl;
	ZString s2 = ZString("c++ forever");
	ZString s3 = s2;
	cout << "s2 is empty: " <<  std::boolalpha << s2.empty() << endl;
	cout << s1 << " <--> " << s2 << " <--> " << s3 << endl;

	cin >> s1;

	cout << s1;

	s3 = s1 + s2;

	cout << s3 << endl;

	cout << s3[3] << endl;
	s3[3] = '$';
	cout << s3 << endl;


	char buffer[80]  = {0};

	s3.copy(buffer, 2, 5);

	cout << "\n\n\n\n\nCopye from 2 to 5\n\nBuffer: " << buffer << endl;

	int pos = s3.find("for");

	cout << "\n\n\"for\" start at position: " << pos << endl;

}