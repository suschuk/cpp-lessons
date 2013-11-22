#ifndef MATRIX__H_
#define MATRIX__H_
#include <iostream>
using namespace std;

template <class T, int ROW, int COL>
class Matrix_
{
public:
	Matrix_();
	Matrix_<T, ROW, COL>(const Matrix_<T, ROW, COL>& m)
	{
		for(int i = 0; i < ROW; i++)
			for(int j = 0; j < COL; j++)
				mx[i][j] = m.mx[i][j];
	}

	T* operator[](const int);
	Matrix_ operator+(Matrix_&) const;
	Matrix_& operator=(const Matrix_&);
	Matrix_ operator*(T);
	template <int X>
	Matrix_<T, ROW, X> operator*( Matrix_<T, COL, X >& rhs) const
	{
		Matrix_<T, ROW, X> tmp;
		for(int i = 0; i < ROW; i++)					
		{												
			for(int j = 0; j < X; j++)				
			{
				tmp[i][j] = 0;
				for(int k = 0; k < COL; k++)		
				{											
					tmp[i][j] += mx[i][k] * rhs[k][j];
				}
			}
		}
		return tmp;
	}

	void fillRandom();
private:
	T mx[ROW][COL];
};
//*************************************************************************************************//



template<class T, int ROW, int COL>
Matrix_<T, ROW,COL>::Matrix_()
{
	for(int i = 0; i < ROW; ++i)
	{
		for(int j = 0; j < COL; ++j)
		{
			mx[i][j] = 1 + rand() % 9;
		}
	}
}

template<typename T, int ROW, int COL>
T* Matrix_<T, ROW, COL>::operator[](const int row) {
	return mx[row];
}

template<class T, int ROW, int COL>
Matrix_<T,ROW,COL> Matrix_<T,ROW,COL>::operator*(T rhs)
{
	Matrix_<T,ROW,COL> tmp;
	for(int i = 0; i < ROW; ++i)
	{
		for(int j = 0; j < COL; ++j)
		{
			tmp[i][j] = mx[i][j] * rhs;
		}
	}
	return tmp;
}

template<class T, int ROW, int COL>
Matrix_<T, ROW, COL> Matrix_<T, ROW,COL>::operator+(Matrix_<T, ROW , COL>& m) const
{

	Matrix_<T, ROW, COL> tmp;
	for(int i = 0; i < ROW; i++)
		for(int j = 0; j < COL; j++)
		{
			tmp.mx[i][j] = mx[i][j] + m.mx[i][j];
		}
		return tmp;
}

template<class T,  int ROW,  int COL>
Matrix_<T, ROW, COL>& Matrix_<T, ROW,COL>::operator=(const Matrix_<T, ROW , COL>& m)
{
	for(int i = 0; i < ROW; i++)
		for(int j = 0; j < COL; j++)
		{
			mx[i][j] = m.mx[i][j];
		}
		return *this;
}

template<class T, int ROW, int COL>
void Matrix_<T, ROW,COL>::fillRandom()
{
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			mx[i][j] = 1 + rand() % 9;
		}
	}
}

template <class T, const int ROW, const int COL>
ostream& operator<<(ostream& out, Matrix_<T,ROW,COL>& rhs)
{
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			out <<  rhs[i][j] << " ";
		}
		out << endl;
	}
	return out ;
}
#endif