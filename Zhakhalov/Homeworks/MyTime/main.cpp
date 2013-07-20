#include "Time.h"

void main()
{
	Time t(85867);

	t = t + Time(45);

	t.PrintTime(Time::Format::Format_24);
	t.PrintTime(Time::Format::Format_12);
}