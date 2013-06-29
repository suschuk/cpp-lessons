#pragma once

class matrix
{
public:
	matrix(void);
	matrix(int row, int col);
	~matrix(void);
	matrix(matrix &);
	void showMatrix(void);
	void setMatrix(int row, int col);
	matrix& operator = (matrix);
	matrix operator * (matrix);

private:
	double *data;
	int row;
	int col;
};

