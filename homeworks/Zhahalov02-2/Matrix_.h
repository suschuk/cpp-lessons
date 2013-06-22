#pragma once

#include <iostream>

class Matrix_
{
private:

	float **Mat;
	unsigned width;
	unsigned height;

	void CreateMatrix();
	void DeleteMatrix();

public:
	Matrix_(void);
	Matrix_(Matrix_ &Src);
	Matrix_(unsigned width, unsigned height);
	~Matrix_(void);

	void SetVal(float Val,unsigned X, unsigned Y);
	void Transpone();

	float GetVal(unsigned X, unsigned Y) const;
	unsigned Width() const;
	unsigned Height() const;

	Matrix_ operator+(const Matrix_ &A)
	{
		unsigned newWidth = width;

		if(newWidth < A.width)
			newWidth = A.width;

		unsigned newHeight = height;

		if(newHeight < A.height)
			newHeight = A.height;

		Matrix_ R(newWidth,newHeight);

		for(unsigned y = 0; y < newHeight; ++y)
		{
			for(unsigned x = 0; x < newWidth; ++x)
			{
				if( (x < this->width) && (y < this->height) && (x < A.width) && (y < A.height) )
				{
					R.Mat[y][x] = Mat[y][x] + A.Mat[y][x];
				}

				else if( (x < this->width) && (y < this->height) && (x >= A.width) && (y < A.height) )
				{
					R.Mat[y][x] = Mat[y][x];
				}

				else if( (x < this->width) && (y < this->height) && (x < A.width) && (y >= A.height) )
				{
					R.Mat[y][x] = Mat[y][x];
				}

				else if( (x >= this->width) && (y < this->height) && (x < A.width) && (y < A.height) )
				{
					R.Mat[y][x] = A.Mat[y][x];
				}

				else if( (x < this->width) && (y >= this->height) && (x < A.width) && (y < A.height) )
				{
					R.Mat[y][x] = A.Mat[y][x];
				}

				else if( (x >= this->width) && (y >= this->height) && (x >= A.width) && (y >= A.height) )
				{
					R.Mat[y][x] = 0.0f;
				}
			}
		}

		return R;

	}

	Matrix_ operator-(const Matrix_ &A)
	{
		unsigned newWidth = width;

		if(newWidth < A.width)
			newWidth = A.width;

		unsigned newHeight = height;

		if(newHeight < A.height)
			newHeight = A.height;

		Matrix_ R(newWidth,newHeight);

		for(unsigned y = 0; y < newHeight; ++y)
		{
			for(unsigned x = 0; x < newWidth; ++x)
			{
				if( (x < this->width) && (y < this->height) && (x < A.width) && (y < A.height) )
				{
					R.Mat[y][x] = Mat[y][x] - A.Mat[y][x];
				}

				else if( (x < this->width) && (y < this->height) && (x >= A.width) && (y < A.height) )
				{
					R.Mat[y][x] = Mat[y][x];
				}

				else if( (x < this->width) && (y < this->height) && (x < A.width) && (y >= A.height) )
				{
					R.Mat[y][x] = Mat[y][x];
				}

				else if( (x >= this->width) && (y < this->height) && (x < A.width) && (y < A.height) )
				{
					R.Mat[y][x] = -A.Mat[y][x];
				}

				else if( (x < this->width) && (y >= this->height) && (x < A.width) && (y < A.height) )
				{
					R.Mat[y][x] = -A.Mat[y][x];
				}

				else if( (x >= this->width) && (y >= this->height) && (x >= A.width) && (y >= A.height) )
				{
					R.Mat[y][x] = 0.0f;
				}
			}
		}

		return R;
	}

	Matrix_ operator * (const Matrix_ &A)
		{
			if(width != A.height)
				return Matrix_(); // or exeption

			Matrix_ R(A.width,height);

			for(unsigned y = 0; y < R.height; ++y)
			{
				for(unsigned x = 0; x < R.width; ++x)
				{
					for(unsigned i = 0; i < width; ++i)
					{
						R.Mat[y][x] += A.Mat[i][x]*Mat[y][i];
					}
				}
			}

			return R;
		}
	
};

