#include <iostream>
#include <string>
using namespace std;

string operator* (string& str1, string& str2)
{
	string newStr;
	size_t x = 0;
	for(int i = 0; i < str1.length(); ++i)
	{
		x = str2.find_first_of(str1[i], x + 1);
		if(x != std::string::npos)
			newStr.append(str2, x, 1);
	}
	return newStr;
}

int main()
{
	string str1("sdqcg");
	string str2("rgfas34");
	string str3(str1 * str2);

	cout << str3 << endl;
	return 0;
}