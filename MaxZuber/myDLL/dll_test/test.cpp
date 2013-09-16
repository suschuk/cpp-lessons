// MyExecRefsDll.cpp 
// compile with: /EHsc /link MathFuncsDll.lib

#include <iostream>
#include "MathFuncsDll.h"
#include <process.h>
#include <Windows.h>

using namespace std;

void foo(void* args);

#define THREADCOUNT 5

HANDLE ghMutex; 

int main()
{

	

	HANDLE hThread[THREADCOUNT];

	ghMutex = CreateMutex( 
		NULL,              // default security attributes
		FALSE,             // initially not owned
		L"myMutex");             // unnamed mutex


	for (int i = 0; i < THREADCOUNT; ++i)
	{
		hThread[i] = (HANDLE)	_beginthread(foo,0,NULL);
	}

	
	WaitForMultipleObjects(THREADCOUNT, hThread, TRUE, INFINITE);
	
	//WaitForSingleObject(hThread, INFINITE);

	return 0;
}
void foo(void* args)
{

	DWORD dwWaitResult; 

	double a = 7.4;
	int b = 99;

	// Request ownership of mutex.

		dwWaitResult = WaitForSingleObject( 
			ghMutex,    // handle to mutex
			5);  // no time-out interval

		switch (dwWaitResult) 
		{
			// The thread got ownership of the mutex
		case WAIT_OBJECT_0: 
			
				// TODO: Write to the database
				cout << "a + b = " <<
					MathFuncs::MyMathFuncs::Add(a, b) << endl;
				cout << "a - b = " <<
					MathFuncs::MyMathFuncs::Subtract(a, b) << endl;
				cout << "a * b = " <<
					MathFuncs::MyMathFuncs::Multiply(a, b) << endl;
				cout << "a / b = " <<
					MathFuncs::MyMathFuncs::Divide(a, b) << endl;

				try
				{
					cout << "a / 0 = " <<
						MathFuncs::MyMathFuncs::Divide(a, 0) << endl; 
				}
				catch (const invalid_argument &e) 
				{
					cout << "Caught exception: " << e.what() << endl; 
				}
		

				// Release ownership of the mutex object
				if (! ReleaseMutex(ghMutex)) 
				{ 
					// Handle error.
				} 
			break; 

			// The thread got ownership of an abandoned mutex
			// The database is in an indeterminate state
		case WAIT_ABANDONED: 
			return;
		}
	return;
}