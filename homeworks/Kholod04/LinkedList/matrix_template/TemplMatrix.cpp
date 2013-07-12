#include "TemplMatrix.h"
#include <iostream>
#include <ctime>
#include <iomanip>

template <typename T>
TemplMatrix<T>::TemplMatrix(int row, int col)
{
	this->col = col;
	this->row = row;
	matrix = new T* [row];
	for(int i = 0; i < row; ++i)
	{
		matrix[i] = new T [col];
		for(int j = 0; j < col; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}
template TemplMatrix<int>::TemplMatrix(int row, int col);
template TemplMatrix<double>::TemplMatrix(int row, int col);
template TemplMatrix<char>::TemplMatrix(int row, int col);

template <typename T>
TemplMatrix<T>::~TemplMatrix(void)
{
	for(int i = 0; i < row; ++i)
		delete[] matrix[i];
	delete[] matrix;
	matrix = NULL;
}
template TemplMatrix<int>::~TemplMatrix(void);
template TemplMatrix<double>::~TemplMatrix(void);
template TemplMatrix<char>::~TemplMatrix(void);

template <typename T>
void TemplMatrix<T>::showMatrix()
{
	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
			std::cout << std::setw(3) << matrix[i][j];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
template void TemplMatrix<int>::showMatrix();
template void TemplMatrix<double>::showMatrix();
template void TemplMatrix<char>::showMatrix();

template <typename T>
TemplMatrix<T>::TemplMatrix(TemplMatrix& matrixObj)
{
	col = matrixObj.col;
	row = matrixObj.row;
	matrix = new T* [row];
	for(int i = 0; i < row; ++i)
	{
		matrix[i] = new T [col];
		for(int j = 0; j < col; ++j)
		{
			matrix[i][j] = matrixObj.matrix[i][j];
		}
	}
}
template TemplMatrix<int>::TemplMatrix(TemplMatrix& matrixObj);
template TemplMatrix<double>::TemplMatrix(TemplMatrix& matrixObj);
template TemplMatrix<char>::TemplMatrix(TemplMatrix& matrixObj);

template <typename T>
TemplMatrix<T> TemplMatrix<T>::operator=(const TemplMatrix& matrixObj)
{
	if(this == &matrixObj)
		return *this;

	for(int i = 0; i < row; ++i)
		delete[] matrix[i];
	delete[] matrix;

	col = matrixObj.col;
	row = matrixObj.row;

	matrix = new T* [row];
	for(int i = 0; i < row; ++i)
	{
		matrix[i] = new T [col];
		for(int j = 0; j < col; ++j)
		{
			matrix[i][j] = matrixObj.matrix[i][j];
		}
	}
	return *this;
}
template TemplMatrix<int> TemplMatrix<int>::operator=(const TemplMatrix& matrixObj);
template TemplMatrix<double> TemplMatrix<double>::operator=(const TemplMatrix& matrixObj);
template TemplMatrix<char> TemplMatrix<char>::operator=(const TemplMatrix& matrixObj);

template <typename T>
T* TemplMatrix<T>::operator[] (int i)
{
	return matrix[i];
}
template int* TemplMatrix<int>::operator[] (int i);
template double* TemplMatrix<double>::operator[] (int i);
template char* TemplMatrix<char>::operator[] (int i);

template <typename T>
void TemplMatrix<T>::init()
{
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			matrix[i][j] = rand() % 7;
}
template void TemplMatrix<int>::init();
template void TemplMatrix<double>::init();
template void TemplMatrix<char>::init();

template <typename T>
void TemplMatrix<T>::setCol(int col)
{
	for(int i = 0; i < row; ++i)
		delete[] matrix[i];
	delete[] matrix;

	this->col = col;

	matrix = new T* [row];
	for(int i = 0; i < row; ++i)
	{
		matrix[i] = new T [col];
		for(int j = 0; j < col; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}
template void TemplMatrix<int>::setCol(int col);
template void TemplMatrix<double>::setCol(int col);
template void TemplMatrix<char>::setCol(int col);

template <typename T>
void TemplMatrix<T>::setRow(int row)
{
	for(int i = 0; i < this->row; ++i)
		delete[] matrix[i];
	delete[] matrix;

	this->row = row;

	matrix = new T* [row];
	for(int i = 0; i < row; ++i)
	{
		matrix[i] = new T [col];
		for(int j = 0; j < col; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}
template void TemplMatrix<int>::setRow(int row);
template void TemplMatrix<double>::setRow(int row);
template void TemplMatrix<char>::setRow(int row);

template <typename T>
int TemplMatrix<T>::getCol()
{
	return col;
}
template int TemplMatrix<int>::getCol();
template int TemplMatrix<double>::getCol();
template int TemplMatrix<char>::getCol();

template <typename T>
int TemplMatrix<T>::getRow()
{
	return row;
}
template int TemplMatrix<int>::getRow();
template int TemplMatrix<double>::getRow();
template int TemplMatrix<char>::getRow();