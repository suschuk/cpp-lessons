# include "ClassArray.h"
# include <ctime>
using namespace std;

	array::array()
	{
		p=NULL;
		size=0;
	}
	array::array(int is)
	{
		size=is;
		p = new int[size];
	}
	array::array(int* ip, int is)
	{
		size=is;
		p=ip;
	}
	array::~array()
	{
		delete[] p;
		size=0;
	}

	int* array::get_p()
	{
		return p;
	}
	int array::get_size()
	{
		return size;
	}

	void array::set_p(int* sp)
	{
		p=sp;
	}
	void array::set_size(int ss)
	{
		size=ss;
	}

	void array::randfill_arr()
	{
		srand(time(0));

		if(p)
		{
			delete[] p;
		}
		cout<<"Enter size of array: ";
		cin>>size;
		p = new int[size];
		for(int i=0; i<size; ++i)
		{
			p[i]=rand()%100;
		}
	}
	void array::print_arr()
	{
		for(int i=0; i<size; ++i)
		{
			cout<<p[i]<<"  ";
		}
		cout<<endl;
	}
	
	int array::operator[](int tmp)
	{
		if(tmp+1<=size)
			return *(p+tmp);
		else
			return 0;
	}
	void array::operator=( const array& tmp)
	{
		size=tmp.size;
		if(p)
		{
			delete[] p;
		}

		p = new int[size];
		for(int i=0; i<size; ++i)
		{
			p[i]=tmp.p[i];
		}
	}
	array& array::operator+(array& tmp)
	{
		if(size!=tmp.size)
		{
			cout<<"It's impossible to add 2 arrays with different sizes\n";
			return *this;
		}

		static array res(size);
		for(int i=0; i<size; ++i)
		{
			res.p[i]=p[i] + tmp.p[i];
		}

		return res;
	}
	array& array::operator-(array& tmp)
	{
		if(size!=tmp.size)
		{
			cout<<"It's impossible to substract 2 arrays with different sizes\n";
			return *this;
		}

		static array res(size);
		for(int i=0; i<size; ++i)
		{
			res.p[i]=p[i] - tmp.p[i];
		}

		return res;
	}
	void array::operator++()
	{
		srand(time(0));

		array some(size);
		for(int i=0; i<size; ++i)
		{
			some.p[i]=p[i];
		}

		delete[] p;
		p = new int[size+1];

		for(int i=0; i<size; ++i)
		{
			p[i]=some.p[i];
		}

		p[size]=rand()%100;
		size++;
	}
	void array::operator--()
	{
		array some(size);
		for(int i=0; i<size; ++i)
		{
			some.p[i]=p[i];
		}

		delete[] p;
		size--;
		p = new int[size];

		for(int i=0; i<size; ++i)
		{
			p[i]=some.p[i];
		}
	}