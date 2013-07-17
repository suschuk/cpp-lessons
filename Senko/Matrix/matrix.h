#ifndef MATRIX_H
#define MATRIX_H

using std::ostream;

class Matrix 
{
public:
	Matrix();
	Matrix(int dimention, int number);
	Matrix(int r, int c, int number);
	Matrix(const Matrix& inMatrix);

	friend ostream& operator<<	(ostream& out, const Matrix& inMatrix); 

	void setRows(int rows);
	void setCols(int cols);

	int getRows() const;
	int getCols() const;

	void transp();

	int& operator() (const int r, const int c);

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

	int** matrix_; 

	void allocMatrix ();
};


#endif