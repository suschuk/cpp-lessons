#include "Matrix.h"


Matrix::Matrix(void)
{
	Mat = NULL;
	height = 0;
	width = 0;
}

Matrix::Matrix(unsigned width, unsigned height)
{
	Mat = NULL;

	this->width = width;
	this->height = height;

	CreateMatrix();	
}

Matrix::Matrix(Matrix &Src)
{
	width = Src.width;
	height = Src.height;

	CreateMatrix();	

	for(unsigned y = 0; y < height; ++y)
	{
		for(unsigned x = 0; x < width; ++x)
		{
			Mat[y][x] = Src.Mat[y][x];
		}
	}
}


Matrix::~Matrix(void)
{
	if(Mat)
	{
		DeleteMatrix();
	}
}

void Matrix::CreateMatrix()
{
	Mat = new float *[height];

	for(unsigned i = 0; i< height; ++i)
	{
		Mat[i] = new float[width];
		memset(Mat[i], 0, sizeof(float)*width);
	}	
}

void Matrix::DeleteMatrix()
{
	for(unsigned i = 0; i< height; ++i)
	{
		delete[] Mat[i];
	}

	delete[] Mat;
}

void Matrix::Transpone()
{
	Matrix newMat(height,width);

	for(unsigned y = 0; y < height; ++y)
	{
		for(unsigned x = 0; x < width; ++x)
		{
			newMat.Mat[x][y] = Mat[y][x];
		}
	}

	DeleteMatrix();

	width = newMat.width;
	height = newMat.height;

	CreateMatrix();

	for(unsigned y = 0; y < height; ++y)
	{
		for(unsigned x = 0; x < width; ++x)
		{
			 Mat[y][x] = newMat.Mat[y][x];
		}
	}

}

void Matrix::SetVal(float Val,unsigned X, unsigned Y)
{
	if( (X >= width) || (Y >= height) ) return; // or exeption

	Mat[Y][X] = Val;
}

float Matrix::GetVal(unsigned X, unsigned Y) const
{
	if( (X >= width) || (Y >= height) ) return 0.0f; // or exeption

	return Mat[Y][X];
}

unsigned Matrix::Width() const
{
	return width;
}

unsigned Matrix::Height() const
{
	return height;
}

