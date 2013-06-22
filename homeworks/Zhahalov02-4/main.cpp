#include "Time_.h"

void main()
{
	Time_ t(85867);

	t = t + Time_(45);

	t.PrintTime(Time_::Format::Format_24);
	t.PrintTime(Time_::Format::Format_12);
}