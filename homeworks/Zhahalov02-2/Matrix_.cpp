#include "Matrix_.h"


Matrix_::Matrix_(void)
{
	Mat = NULL;
	height = 0;
	width = 0;
}

Matrix_::Matrix_(unsigned width, unsigned height)
{
	Mat = NULL;

	this->width = width;
	this->height = height;

	CreateMatrix();	
}

Matrix_::Matrix_(Matrix_ &Src)
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


Matrix_::~Matrix_(void)
{
	if(Mat)
	{
		DeleteMatrix();
	}
}

void Matrix_::CreateMatrix()
{
	Mat = new float *[height];

	for(unsigned i = 0; i< height; ++i)
	{
		Mat[i] = new float[width];
		memset(Mat[i], 0, sizeof(float)*width);
	}	
}

void Matrix_::DeleteMatrix()
{
	for(unsigned i = 0; i< height; ++i)
	{
		delete[] Mat[i];
	}

	delete[] Mat;
}

void Matrix_::Transpone()
{
	Matrix_ newMat(height,width);

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

void Matrix_::SetVal(float Val,unsigned X, unsigned Y)
{
	if( (X >= width) || (Y >= height) ) return; // or exeption

	Mat[Y][X] = Val;
}

float Matrix_::GetVal(unsigned X, unsigned Y) const
{
	if( (X >= width) || (Y >= height) ) return 0.0f; // or exeption

	return Mat[Y][X];
}

unsigned Matrix_::Width() const
{
	return width;
}

unsigned Matrix_::Height() const
{
	return height;
}

