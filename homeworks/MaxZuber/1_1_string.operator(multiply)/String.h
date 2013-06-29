#pragma once
#ifndef STR_H_
#define STR_H_

class Str
{
private:
	char* s;
	int len;

public:
	Str();
	Str(char*);
	Str(const Str&);
	~Str();

	void showStr() const;

	Str operator*(const Str&);

};
#endif