#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <time.h>
#include <Windows.h>
using namespace std;

const unsigned long MAX = 1000000;

inline double getRand()
{
	return 100.0 + ((double)rand()) / RAND_MAX;
}

void vectorMeasure();
void listMeasure();
void dequeMeasure();

int main()
{
	vectorMeasure();
	listMeasure();
	dequeMeasure();

	cout << "\n\n";
	return 0;
}

void vectorMeasure()
{
	vector<double> v;
	DWORD dwStart, dwFinish;

	cout << "Measure of the vector:\n";

	dwStart = GetTickCount();
	for(int i = 0; i < MAX; i++)
		v.push_back ( getRand() );
    dwFinish = GetTickCount();

	cout << "Time of push_back all of " << MAX << " elements is: " 
		 << dwFinish - dwStart << " ms.\n";

	cout << "Time of access to element v[" << MAX / 2 << "] = " ;
	dwStart = GetTickCount();
	cout << v[MAX / 2];
    dwFinish = GetTickCount();
	cout << " is: " << dwFinish - dwStart << " ms.\n";

	dwStart = GetTickCount();
	while( !v.empty() )
		v.pop_back();
    dwFinish = GetTickCount();
	cout << "Time of pop_back all of " << MAX << " elements is: " 
		 << dwFinish - dwStart << " ms.\n";

}

void listMeasure()
{
	list<double> l;
	list<double>::iterator iter;
	DWORD dwStart, dwFinish;
	int n;

	cout << "\n\nMeasure of the list:\n";

	dwStart = GetTickCount();
	for(int i = 0; i < MAX; i++)
		l.push_back ( getRand() );
    dwFinish = GetTickCount();
	
	cout << "Time of push_back all of " << MAX << " elements is: " 
		 << dwFinish - dwStart << " ms.\n";

	dwStart = GetTickCount();
	for( iter = l.begin(), n = 0; n != MAX/ 2  ; iter++, n++ )
	dwFinish = GetTickCount();

	cout << "Time of access to element v[" << MAX / 2 << "] = " << *iter;
	cout << " is: " << dwFinish - dwStart << " ms.\n";

	dwStart = GetTickCount();
	while( !l.empty() )
		l.pop_back();

    dwFinish = GetTickCount();
	cout << "Time of pop_back all of " << MAX << " elements is: " 
		 << dwFinish - dwStart << " ms.\n";

}

void dequeMeasure()
{
	deque<double> qu;
	DWORD dwStart, dwFinish;

	cout << "\n\nMeasure of the deque:\n";

	dwStart = GetTickCount();
	for (int i = 0; i < MAX; i++)
		qu.push_back( getRand() );
	dwFinish = GetTickCount();
	cout << "Time of push_back all of " << MAX << " elements is: " 
		 << dwFinish - dwStart << " ms.\n";

	cout << "Time of access to element v[" << MAX / 2 << "] = " ;
	dwStart = GetTickCount();
	cout << qu[MAX / 2];
    dwFinish = GetTickCount();
	cout << " is: " << dwFinish - dwStart << " ms.\n";

	dwStart = GetTickCount();
	while( !qu.empty() )
		qu.pop_back();
    dwFinish = GetTickCount();
	cout << "Time of pop_back all of " << MAX << " elements is: " 
		 << dwFinish - dwStart << " ms.\n";

}

