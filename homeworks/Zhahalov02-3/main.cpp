#include <iostream>
#include "String_.h"

void main()
{
	String_ Str1("sdqcgg");
	String_ Str2("rgfas34");
	String_ Str3 = Str1 * Str2; 

	std::cout << Str3.GetStr() << "\r\n";


    String_ s(Str1);
    std::cout << s.GetStr() << "\r\n";

}