#include "cross_string.h"


cross_string::cross_string(void)
{
}


cross_string::~cross_string(void)
{
}

std::string cross_string::operator* (std::string& str)
{
	std::string newStr;
	size_t x = 0;
	while(x != std::string::npos)
	{
		x = this->find_first_of(str);
		if(x != std::string::npos)
			newStr.append(this[x]);
	}
	return newStr;
}