# include <iostream>
# include <cstring>
# include <math.h>
# include "ClassTime.h"

using namespace std;

time::time()
{
	min=0;
	half=NULL;
}
time::time(int s)
{
	min=s;
	half=NULL;
}
time::time(int s, char* h)
{
	min=s;
	half = new char[sizeof(h)+1];
	strcpy(half, h);
}
time::time(time& tmp)
{
	min=tmp.min;
	if(half)
		delete[] half;
	half= new char[sizeof(tmp.half)+1];
	strcpy(half, tmp.half);
}
time::~time()
{
	delete[] half;
	min=0;
}

void time::amer_fill()
{
	if(min!=0)
		min=0;

	int tmp;
	bool flag=false;
	while(flag==false)
	{
		cout<<"Enter hours: ";
		cin>>tmp;
		if(tmp>=0 && tmp<12)
			flag=true;
	}
	flag=false;

	while(flag==false)
	{
		cout<<"Enter minutes: ";
		cin>>min;
		if(min>=0 && min<60)
			flag=true;
	}
	
	min+=tmp*60;

	cout<<"am or pm: ";
	half = new char[3];
	cin>>half;
}
void time::fill()
{
	if(min!=0)
		min=0;

	int tmp;
	bool flag=false;
	while(flag==false)
	{
		cout<<"Enter hours: ";
		cin>>tmp;
		if(tmp>=0 && tmp<24)
			flag=true;
	}
	flag=false;

	while(flag==false)
	{
		cout<<"Enter minutes: ";
		cin>>min;
		if(min>=0 && min<60)
			flag=true;
	}
	
	min+=tmp*60;
}
void time::print()
{
	if(half)
	{
		cout<<floor(float(min/60))<<":"<<min%60<<" "<<half<<endl;
	}
	else
	{
		cout<<floor(float(min/60))<<":"<<min%60<<endl;
	}
}
void time::convert_toAmer()
{
	half= new char[3];

	if(floor(float(min/60)))
	{
		min-=12*60;
		half="pm";
	}
	else
		half="am";
}
void time::convert_fromAmer()
{
	if(half)
	{
		if(half[0]=='p')
			min+=12*60;
		delete[] half;
		half=NULL;
	}
}
void time::compare(time& a, time& b)
{
	if(a.half)
		a.convert_fromAmer();
	if(b.half)
		b.convert_fromAmer();

	if(a.min<b.min)
		cout<<"Second time is bigger\n";
	else if(a.min>b.min)
		cout<<"First time is biggrser\n";
	else
		cout<<"Times are equal\n";

}
void time::equalize()
{
	if(half)
	{
		if(floor(float(min/60))>11)
			min-=12*60;
	}
	else
	{
		if(floor(float(min/60))>23)
			min-=24*60;
	}
}

void time::operator+(time& some)
{
	if(half)
		convert_fromAmer();
	if(some.half)
		some.convert_fromAmer();

	min+=some.min;
	equalize();
}
void time::operator-(time& some)
{
	if(half)
		convert_fromAmer();
	if(some.half)
		some.convert_fromAmer();

	if(min<some.min)
		cout<<"Impossible to subtract greater from the smaller\n";
	min-=some.min;

	equalize();
}
