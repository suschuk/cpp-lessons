#include "Matr.h"
#include <iostream>
using namespace std;

Matr::Matr()
{
	n_ = 0;
	m_ = 0;
	Mx_ = NULL;
}


Matr::~Matr()
{
	for(int i = 0; i < m_;i++)
	{
		delete [] Mx_[i];
		Mx_[i] = NULL;
	}
	delete [] Mx_;
	Mx_ = NULL;
}

Matr::Matr(int& m, int& n)
{
	m_ = m;
	n_ = n;

	Mx_ = new int*[m];							//reserv memory for matrix
	for(int i = 0; i < m;i++)
	{
		Mx_[i] = new int[n];
	}


	/*
	/ fill matrix by zero
	*/
	for(int i = 0; i < m_; i++)
	{
		for(int j = 0; j < n_; j++)
		{
			Mx_[i][j] = 0;
		}
	}
}

void Matr::fillRandom()
{
	for(int i = 0; i < m_; i++)
	{
		for(int j = 0; j < n_; j++)
		{
			Mx_[i][j] = rand() % 10;
		}
	}
}

Matr Matr::operator+(Matr& m)
{
	if(this->m_ != m.m_ || this->n_ != m.n_)					//chek size's
	{
		cout << "\bWrong matrix size's!\n\n";
		return *this;
	}

	Matr tmp(this->m_, this->n_);								//create temporary object

	for(int i = 0; i < m.m_; i++)								//add matrix's
	{
		for(int j = 0; j < m.n_; j++)
		{
			tmp.Mx_[i][j] = this->Mx_[i][j] + m.Mx_[i][j];
		}
	}

	return tmp;
}
Matr Matr::operator*(Matr& m)
{
	if(this->n_ != m.m_)							//chek size's
	{
		cout << "\nWrong matrix size's\n\n";
		return *this;
	}

	Matr tmp (this->m_, m.n_);

	for(int i = 0; i < tmp.m_; i++)					//outside loop
	{												//	 to reach, each position
		for(int j = 0; j < tmp.n_; j++)				//		in new matrix
		{
			for(int k = 0; k < m.m_; k++)			//inside loop to collect sum of produts A[row's] x B[column's]
			{											
				tmp.Mx_[i][j] += this->Mx_[i][k] * m.Mx_[k][j];
			}
		}
	}

	return tmp;
}

Matr& Matr::operator=(Matr& m)
{
	if(this->m_ > 0)										//chek if object exist
	{															//if exist delete
		for(int i = 0; i < m_;i++)
		{
			delete [] Mx_[i];
			Mx_[i] = NULL;
		}
		delete [] Mx_;
		Mx_ = NULL;
	}



	this->m_ = m.m_;									//save objec sizes
	this->n_ = m.n_;									//

	this->Mx_ = new int*[this->m_];						//get memory for new object
	for(int i = 0; i < this->m_;i++)					//
	{													//
		this->Mx_[i] = new int[this->n_];				//
	}													//

	for(int i = 0; i < this->m_; i++)					// copy data
	{													//
		for(int j = 0; j < this->n_; j++)				//
		{												//
			this->Mx_[i][j] = m.Mx_[i][j];				//
		}												//
	}													//

	return *this;
}

void Matr::showM() const
{
	std::cout << std::endl;
	for(int i = 0; i < this->m_; i++)
	{
		for(int j = 0; j < this->n_; j++)
		{
			std::cout << this->Mx_[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

Matr::Matr(const Matr& mtx)
{
	if(this->m_ > 0)							//chek if object exist
	{													//if exist delete
		for(int i = 0; i < this->m_;i++)
		{
			delete [] this->Mx_[i];
		}
		delete [] this->Mx_;
		this->Mx_ = NULL;

		this->m_ = 0;
		this->n_ = 0;
	}

	
	

	/*
	/ start copy object
	*/

	
	this->m_ = mtx.m_;			//copy size of Matrix
	this->n_ = mtx.n_;			//


	/*
	/reserv memory for new object
	*/
	Mx_ = new int*[m_];
	for(int i = 0; i < m_;i++)
	{
		Mx_[i] = new int[n_];
	}


	/*
	/ copy data
	*/
	for(int i = 0; i < m_; i++)
	{
		for(int j = 0; j < n_; j++)
		{
			Mx_[i][j] = mtx.Mx_[i][j];
		}
	}

}

Matr Matr::operator*(vect& vc)
{
	int size = vc.getVectSize();

	if(vc.getVectSize() != n_)							//chek size's
	{
		cout << "\nWrong Matrix or Vector size\n\n";
		return *this;
	}

	int one = 1;											// for Matr constructor
	Matr temp(m_, one);

	for(int i = 0; i < m_; i++)
	{
		for( int k = 0; k < size; k++)
		{
			temp.Mx_[i][0] += this->Mx_[i][k] * vc.getNum(k);
		}
	}

	return temp;
}