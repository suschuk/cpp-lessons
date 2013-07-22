/*
	class String_
*/
#include "String_.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	String_ str1("Our first string");
	cout << str1.getStr() << "\n";
	cout << "str1 length = " << str1.getLen() << "\n\n";

	str1.setStr("Our first string edited");
	cout << str1.getStr() << "\n";
	cout << "str1 length = " << str1.getLen() << "\n\n";

	String_ str2("Our second string"), str3;

	str3 = str1 + str2;
	cout << "str1 + str2 = ";
	cout << str3.getStr() << "\n";

	cout << "str1[0] = " << str1 [0] << "\n";
	cout << "str1[1] = " << str1 [1] << "\n";
	cout << "str1[2] = " << str1 [2] << "\n\n";
	cout << "str1[22] = " << str1 [22] << "\n\n";

	return 0;
}