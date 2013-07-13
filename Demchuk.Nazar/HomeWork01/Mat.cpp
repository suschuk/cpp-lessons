# include "ClassMat.h"
# include <time.h>

using namespace std;


void matrix::set_mat(int **num)
{
	this->num = num;
}
void matrix::set_size(int size)
{
	this->size = size;
}

int** matrix::get_mat()
{
	return this->num;
}
int matrix::get_size()
{
	return this->size;
}

matrix::matrix()
{
	this->num=NULL;
	this->size=0;
}
matrix::matrix(int** tmp, int size)
{
	this->size = size;

	num = new int *[size];

	for (int i=0; i<this->size; i++)
	{
		*num = new int [size];
		for (int j=0; j<this->size; j++)
		{
			num[i][j]=tmp[i][j];
		}
	}
}
matrix::matrix(const matrix& tmp)
{
	size = tmp.size;

	num = new int *[size];

	for (int i=0; i<size; i++)
	{
		*num = new int [size];
		for (int j=0; j<size; j++)
		{
			num[i][j]=tmp.num[i][j];
		}
	}
}
matrix::~matrix()
{
	for (int i=size; i>0; i--)
	{
		delete[] *num;
	}
	delete[] num;
	num=NULL;
	size=0;
}

void matrix::randomfill_matrix()
{
	srand(time(0));
	cout<<"Enter number of rows and columns: ";
	cin>>size;

	num = new int *[size];

	for (int i=0; i<size; i++)
	{
		*num = new int [size];
		for (int j=0; j<size; j++)
		{
			num[i][j]=rand();
		}
	}
}
void matrix::show_matrix()
{
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			cout<<num[i][j]<<"  ";
		}
		cout<<endl;
	}
}
int matrix::operator+(const matrix& tmp)
{
	if(size != tmp.size)
	{
		cout<<"It's impossible to add 2 matrix with different sizes!";
		return 0;
	}

	for (int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			num[i][j]+=tmp.num[i][j];
		}
	}
	return 0;
}
int matrix::operator-(const matrix& tmp)
{
	if(size != tmp.size)
	{
		cout<<"It's impossible to subtract 2 matrix with different sizes!";
		return 0;
	}

	for (int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			num[i][j]-=tmp.num[i][j];
		}
	}
	return 0;
}
matrix* matrix::operator*(const matrix& tmp)
{
	if(size != tmp.size)
	{
		cout<<"It's impossible to add 2 matrix with such sizes!";
		return this;
	}

	matrix res;
	res.size = size;

	for (int i=0; i<res.size; i++)
	{
		for (int j=0; j<res.size; j++)
		{
			for (int x=0; x<size; x++)
			{
				res.num[i][j]+=num[i][x]*tmp.num[x][j];
			}
		}
	}

	return &res;
}