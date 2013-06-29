#include "matrix.h"
#include <iostream>

matrix::matrix(void)
{
	data=NULL;
	row=0;
	col=0;
}

matrix::matrix(int row, int col)
{
	data=new double [row*col];
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		{
			*(data+i*col+j)=j+1;
		}
	}
	this->row=row;
	this->col=col;
}

matrix::~matrix(void)
{
	if (data!=NULL)
	{
		delete [] data;
	}
}

matrix::matrix(matrix &copy) : row(copy.row), col(copy.col), data(new double [copy.row*copy.col])
{
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		{
			*(data+i*col+j)=*(copy.data+i*col+j);
		}
	}
}

void matrix::showMatrix(void)
{
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		{
			std::cout << *(data+i*col+j) << " ";
		}
		std::cout << "\n";
	}
}

void matrix::setMatrix(int row, int col)
{
	if (data!=NULL)
	{
		delete [] data;
	}
	data=new double [row*col];
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		{
			*(data+i*col+j)=j+1;
		}
	}
	this->row=row;
	this->col=col;
}

matrix& matrix :: operator = (matrix source)
{
	if (this!=&source)
	{
		if (data!=NULL)
		{
			delete [] data;
		}
		row=source.row;
		col=source.col;
		data=new double [row*col];
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				*(data+i*col+j)=*(source.data+i*col+j);
			}
		}
	}
	return *this;
}

matrix matrix :: operator * (matrix source)
{
	if (col==source.row)
	{
		matrix temp(row,source.col);
		for (int i=0;i<temp.row;i++)
		{
			for (int j=0;j<temp.col;j++)
			{
				*(temp.data+i*temp.col+j)=0;
				for (int h=0;h<col;h++)
				{
					*(temp.data+i*temp.col+j) += *(data+i*col+h) * *(source.data+h*source.col+j);
				}
			}
		}
		return temp;
	}
	else
	{
		matrix temp;
		return temp;
	}
}