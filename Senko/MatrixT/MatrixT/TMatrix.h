#ifndef TMATRIX_H
#define TMATRIX_H

using std::ostream;

template <typename T> 
class Matrix 
{
public:
	Matrix();
	Matrix(int dimention, T number);
	Matrix(int r, int c, T number);
	Matrix(const Matrix& inMatrix);

	friend ostream& operator<<	(ostream& out, const Matrix& inMatrix)
	{
	
		for (int i = 0; i < inMatrix.m; i++) 
		{
			for (int j = 0; j < inMatrix.n; j++)
			{
				out << inMatrix.matrix_[i][j] << " ";
			}
			out << endl;
		}



		return out;
	}

	void transp();

	T& operator() (const int r, const int c);

	Matrix& operator= (const Matrix& inMatrix);
	Matrix& operator+= (const Matrix& inMatrix);
	Matrix& operator-= (const Matrix& inMatrix);
	Matrix& operator*= (const Matrix& inMatrix);

	Matrix operator+ (const Matrix& inMatrix);
	Matrix operator- (const Matrix& inMatrix);
	Matrix operator* (const Matrix& inMatrix);
	Matrix& operator* (const int& k);
	

	~Matrix();

private:
	int m; // rows
	int n; // cols

	T** matrix_; 

	void allocMatrix ();
};

/*-------------- implementation --------------*/


template <typename T>
void Matrix<T>::allocMatrix ()
{
	matrix_ = new T*[m];

	for (int i=0; i < m; i++)
	{
		matrix_[i] = new T[n];
	}
}

template <typename T>
Matrix<T>::Matrix()
{
	m = n = 2;

	allocMatrix();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] = 0;
		}
	}
}

template <typename T>
Matrix<T>::Matrix(int dimention, T number)
{
	m = n = dimention;

	allocMatrix();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] = number;
		}
	}
}

template <typename T>
Matrix<T>::Matrix(int r, int c, T number)
{
	m = r;
	n = c;

	allocMatrix();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] = number;
		}
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix& inMatrix)
{
	allocMatrix();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] = inMatrix.matrix_[i][j];
		}
	}
}

template <typename T>
void Matrix<T>::transp()
{
	Matrix tmp(n, m, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp.matrix_[i][j] = matrix_[j][i];
		}
	}
	*this = tmp;
}

template <typename T>
T& Matrix<T>::operator() (const int r, const int c)
{
	if ( (r >= 0 && r < m) && (c >= 0 && c < n) )
	{
		return matrix_[r][c];
	}
	else
	{
		throw -1; // out of bounds
	}
	
}

template <typename T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T>& inMatrix)
{
	if(this == &inMatrix) 
		return *this;

	if (m != inMatrix.m || n != inMatrix.n)
	{
		this->~Matrix();
		m = inMatrix.m;
		n = inMatrix.n;

		allocMatrix();
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] = inMatrix.matrix_[i][j];
		}
	}

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& inMatrix)
{
	if (m == inMatrix.m && n == inMatrix.n)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix_[i][j] += inMatrix.matrix_[i][j];
			}
		}
	}
	else
	{
		throw -1; // dimensions doesn't match
	}

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& inMatrix)
{
	if (m == inMatrix.m && n == inMatrix.n)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix_[i][j] -= inMatrix.matrix_[i][j];
			}
		}
	}
	else
	{
		throw -1; // dimensions doesn't match
	}

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*= (const Matrix<T>& inMatrix)
{
	Matrix tmp(m, inMatrix.n, 0);

	if (n == inMatrix.m)
	{
		for (int i=0; i < tmp.m; i++) 
		{
			for (int j=0; j < tmp.n; ++j) 
			{
				for (int k=0; k < this->n; ++k) 
				{
					tmp.matrix_[i][j] += (this->matrix_[i][k]*inMatrix.matrix_[k][j]);
				}
			}
		}
	}
	else
	{
		throw -1; // rows&cols doesn't match
	}
	return (*this = tmp);
}

template <typename T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T>& inMatrix)
{
	Matrix<T> tmp;
	tmp = *this;
	tmp += inMatrix;
	return tmp;
}

template <typename T>
Matrix<T> Matrix<T>::operator- (const Matrix<T>& inMatrix)
{
	Matrix<T> tmp;
	tmp = *this;
	tmp -= inMatrix;
	return tmp;
}

template <typename T>
Matrix<T> Matrix<T>::operator* (const Matrix<T>& inMatrix)
{
	Matrix<T> tmp;
	tmp = *this;
	tmp *= inMatrix;
	return tmp;
}

template <typename T>
Matrix<T>& Matrix<T>::operator* (const int& k)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix_[i][j] *= k;
		}
	}

	return *this;
}

template <typename T>
Matrix<T>::~Matrix()
{
	for (int i=0; i < m; i++)
	{
		delete[] matrix_[i];
	}

	delete []matrix_;
	matrix_= NULL;
}

#endif