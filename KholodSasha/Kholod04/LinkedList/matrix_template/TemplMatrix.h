#ifndef _TEMPL_MATRIX_H_
#define _TEMPL_MATRIX_H_

template <typename T>
class TemplMatrix
{
public:
	TemplMatrix(int row = 5, int col = 5);
	~TemplMatrix(void);
	TemplMatrix(TemplMatrix& matrix);
	TemplMatrix operator= (const TemplMatrix& matrixObj);
	T* operator[] (int i);

	void showMatrix();
	void init();

	void setCol(int col);
	void setRow(int row);
	int getCol();
	int getRow();
private:
	T** matrix;
	int col;
	int row;
};

#endif //_TEMPL_MATRIX_H_