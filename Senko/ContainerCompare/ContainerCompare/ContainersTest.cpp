#include "ContainersTest.h"
#include <iostream>
#include <ctime>
#include <array>
#include <deque>
#include <vector>
#include <list>

using namespace std;

const int SIZE = 100000;

double timediff(clock_t end, clock_t start)
{
	double d_ticks = start-end;
    double d_msec = (d_ticks/CLOCKS_PER_SEC) * 1000;
    return d_msec;
}

double ArrayTest()
{
	array<int, SIZE> tst;

	clock_t start = clock();

	for(long i = 0; i < SIZE;i++)
    {
		tst[i] = i;
    }
	
	for(int i=0; i < SIZE;i++)
    {
		long tst_val = tst[i];
    }

	clock_t end = clock();

	return timediff(start, end);

}

double DequeTest()
{
	deque<int> tst;
	tst.begin();

	clock_t start = clock();

	for(long i = 0; i < SIZE;i++)
    {
		tst.push_back(i);	
    }
	
	for(int i=0; i < SIZE;i++)
    {
		long tst_val = tst.at(i);
    }

	clock_t end = clock();

	return timediff(start, end);
}

double VectorTest()
{
	vector<int> tst;
	tst.begin();

	clock_t start = clock();

	for(long i = 0; i < SIZE;i++)
    {
		tst.push_back(i);	
    }
	
	for(int i=0; i < SIZE;i++)
    {
		long tst_val = tst.at(i);
    }

	clock_t end = clock();

	return timediff(start, end);
}

double ListTest()
{
	list<int> tst;
	tst.begin();

	clock_t start = clock();

	for (int i = 0; i < SIZE; i++)
    {
		tst.push_back(i);	
    }
	
	for (list<int>::iterator it = tst.begin(); it != tst.end(); it++)
    {
		long tst_val = *it;
    }

	clock_t end = clock();

	return timediff(start, end);
}
