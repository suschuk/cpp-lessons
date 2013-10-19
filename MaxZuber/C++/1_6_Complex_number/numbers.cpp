#include "ComplexNumber.h"
#include <iostream>

using namespace std;



int main()
{

	ComplexNumber cn1(1.0, 0.0), cn2(1.0, 0.0), cn3;


	cout << cn1 << endl;
    
	cn3 = (cn1 / cn2);
	cn3 +=(5);
    
	cout << cn3 << endl;

    ComplexNumber result;

    {
        ComplexNumber cn1(1.,0.), cn2(2.,0.);
        result = cn1 + cn2;

    }

    cout << result << endl;


	return 0;
}