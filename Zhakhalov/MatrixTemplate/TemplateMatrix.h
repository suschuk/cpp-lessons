#pragma once

#include <iostream>

template <typename T> 
class Matrix
{
public:	
	Matrix(Matrix<T> &Src);
	Matrix(unsigned width, unsigned height);
	~Matrix(void);

	void SetVal(T Val,unsigned X, unsigned Y);
	void Transpone();
	T GetVal(unsigned X, unsigned Y) const;

	unsigned Width() const {return _width;}
	unsigned Height() const {return _height;}

	Matrix operator+(const Matrix &A);	
	Matrix operator-(const Matrix &A);
	Matrix operator*(const Matrix &A);

private:
	T **_mat;
	unsigned _width;
	unsigned _height;

	void CreateMatrix();
	void DeleteMatrix();
};

template <typename T>
Matrix<T>::Matrix(unsigned width, unsigned height)
{
	_mat = NULL;

	_width = width;
	_height = height;

	CreateMatrix();	
}

template <typename T>
Matrix<T>::Matrix(Matrix<T> &Src)
{
	_width = Src._width;
	_height = Src._height;

	CreateMatrix();	

	for(unsigned y = 0; y < _height; ++y)
	{
		for(unsigned x = 0; x < _width; ++x)
		{
			_mat[y][x] = Src._mat[y][x];
		}
	}
}

template <typename T>
Matrix<T>::~Matrix(void)
{
	if(_mat)
	{
		DeleteMatrix();
	}
}

template <typename T>
void Matrix<T>::CreateMatrix()
{
	_mat = new T* [_height];

	for(unsigned i = 0; i < _height; ++i)
	{
		_mat[i] = new T[_width];
		memset(_mat[i], 0, sizeof(T)*_width);
	}	
}

template <typename T>
void Matrix<T>::DeleteMatrix()
{
	for(unsigned i = 0; i< _height; ++i)
	{
		delete[] _mat[i];
	}

	delete[] _mat;
}

template <typename T>
void Matrix<T>::Transpone()
{
	Matrix newMat(_height,_width);

	for(unsigned y = 0; y < _height; ++y)
	{
		for(unsigned x = 0; x < _width; ++x)
		{
			newMat._mat[x][y] = _mat[y][x];
		}
	}

	DeleteMatrix();

	_width = newMat._width;
	_height = newMat._height;

	CreateMatrix();

	for(unsigned y = 0; y < _height; ++y)
	{
		for(unsigned x = 0; x < _width; ++x)
		{
			_mat[y][x] = newMat._mat[y][x];
		}
	}

}

template <typename T>
void Matrix<T>::SetVal(T Val,unsigned X, unsigned Y)
{
	if( (X >= _width) || (Y >= _height) ) throw std::runtime_error("Out of Bound!");

	_mat[Y][X] = Val;
}

template <typename T> T Matrix<T>::GetVal(unsigned X, unsigned Y) const
{
	if( (X >= _width) || (Y >= _height) ) throw std::runtime_error("Out of Bound!");

	return _mat[Y][X];
}

template <typename T> Matrix<T> Matrix<T>::operator+(const Matrix<T> &A)
{
	unsigned newWidth = _width;

	if(newWidth < A._width)
		newWidth = A._width;

	unsigned newHeight = _height;

	if(newHeight < A._height)
		newHeight = A._height;

	Matrix<T> R(newWidth,newHeight);

	for(unsigned y = 0; y < newHeight; ++y)
	{
		for(unsigned x = 0; x < newWidth; ++x)
		{
			if( (x < _width) && (y < _height) && (x < A._width) && (y < A._height) )
			{
				R._mat[y][x] = _mat[y][x] + A._mat[y][x];
			}

			else if( (x < _width) && (y < _height) && (x >= A._width) && (y < A._height) )
			{
				R._mat[y][x] = _mat[y][x];
			}

			else if( (x < _width) && (y < _height) && (x < A._width) && (y >= A._height) )
			{
				R._mat[y][x] = _mat[y][x];
			}

			else if( (x >= _width) && (y < _height) && (x < A._width) && (y < A._height) )
			{
				R._mat[y][x] = A._mat[y][x];
			}

			else if( (x < _width) && (y >= _height) && (x < A._width) && (y < A._height) )
			{
				R._mat[y][x] = A._mat[y][x];
			}

			else if( (x >= _width) && (y >= _height) && (x >= A._width) && (y >= A._height) )
			{
				R._mat[y][x] = NULL;
			}
		}
	}
	return R;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &A)
{
	unsigned newWidth = _width;

	if(newWidth < A._width)
		newWidth = A._width;

	unsigned newHeight = _height;

	if(newHeight < A._height)
		newHeight = A._height;

	Matrix<T> R(newWidth,newHeight);

	for(unsigned y = 0; y < newHeight; ++y)
	{
		for(unsigned x = 0; x < newWidth; ++x)
		{
			if( (x < _width) && (y < _height) && (x < A._width) && (y < A._height) )
			{
				R._mat[y][x] = _mat[y][x] - A._mat[y][x];
			}

			else if( (x < _width) && (y < _height) && (x >= A._width) && (y < A._height) )
			{
				R._mat[y][x] = _mat[y][x];
			}

			else if( (x < _width) && (y < _height) && (x < A._width) && (y >= A._height) )
			{
				R._mat[y][x] = _mat[y][x];
			}

			else if( (x >= _width) && (y < _height) && (x < A._width) && (y < A._height) )
			{
				R._mat[y][x] = -A._mat[y][x];
			}

			else if( (x < _width) && (y >= _height) && (x < A._width) && (y < A._height) )
			{
				R._mat[y][x] = -A._mat[y][x];
			}

			else if( (x >= _width) && (y >= _height) && (x >= A._width) && (y >= A._height) )
			{
				R._mat[y][x] = NULL;
			}
		}
	}

	return R;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &A)
{
	if(_width != A._height)throw std::runtime_error("Incompatible matrix size");		

	Matrix<T> R(A._width,_height);

	for(unsigned y = 0; y < R._height; ++y)
	{
		for(unsigned x = 0; x < R._width; ++x)
		{
			for(unsigned i = 0; i < _width; ++i)
			{
				R._mat[y][x] += A._mat[i][x]*_mat[y][i];
			}
		}
	}

	return R;
}
