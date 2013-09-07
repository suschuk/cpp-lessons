#pragma once
#include <vector>
#include <string>

class Client
{
public:
	Client(std::string name, std::string mail, std::string telNo);
	Client(const Client&);

	std::string Name() const;
	std::string Mail() const;
	std::string TelNo() const;

private:
	std::string _name;
	std::string _mail;
	std::string _telNo;

	int _idx;
};

