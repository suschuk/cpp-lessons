#include "vect.h"
#include <iostream>


vect::vect()
{
	vec_ = NULL;
	m_ = 0;
}
vect::vect(int& m)
{
	m_ = m;
	vec_ = new int[m_];
	
}
vect::vect(const vect& vc)
{
	if(m_ > 0)
	{
		delete [] this->vec_;
		this->vec_ = NULL;
		this->m_ = 0;
	}
}
vect::~vect()
{
	if(m_ > 0)									//if vector exist - delete
	{
		delete [] vec_;
		m_ = 0;
	}
	vec_ = NULL;
}

void vect::fillRanom()
{
	if(m_ > 0)
	{
		for(int i = 0; i < m_; i++)
		{
			vec_[i] = rand() % 10;
		}
	}
}

int vect::getNum(int& n)
{
	if(m_ > 0)
	{
		return vec_[n];
	}
	return 0;
}

int vect::getVectSize()
{
	return m_;
}

void vect::printVect()
{
	for(int i = 0 ; i < m_; i++)
	{
		std::cout << vec_[i] << "\t";
	}
	std::cout << std::endl;
}


