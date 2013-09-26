#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
	Time T1;
	Time T2(3661); // 1 hour 1 minute 1 second
	Time T3(1830050); // 50 hours 50 minutes 50 seconds
	
	cout << "Enter some time: " << endl;
	cin >> T1;
		
	cout << "Time 1 + 1 hour 1 minute 1 second = "<< T1+T2 ;
	cout << "Time 1 - 1 hour 1 minute 1 second = "<< T1-T2 << endl;

	cout << "Time 1 + 50 hours 50 minutes 50 seconds = "<< T1+T3 ;
	cout << "Time 1 - 50 hours 50 minutes 50 seconds = "<< T1-T3 << endl;

	T1.changeFormat();
	
	cout << "Changing time format ..."<< endl;
	cout << T1;
	
	cout << endl << "Comparison operation:" << endl;
	
	cout << "Is T1 > 1 hour 1 minute 1 second ? " ;
	if(T1 > T2) {cout << "YES!";} else { cout << "NO!";};
	cout << endl;

	cout << "Is T1 < 1 hour 1 minute 1 second ? " ;
	if(T1 < T2) {cout << "YES!";} else { cout << "NO!";};
	cout << endl;

	cout << "Is T1 = 1 hour 1 minute 1 second ? " ;
	if(T1 == T2) {cout << "YES!";} else { cout << "NO!";};
	cout << endl;
	
	return 0;
}