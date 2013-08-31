#pragma once

#include <string>
class cross_string :
	public std::string
{
public:
	cross_string(void);
	~cross_string(void);

	std::string operator * (std::string& str);
};

