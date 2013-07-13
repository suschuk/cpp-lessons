# include <iostream>
# include <string.h>
# include <math.h>

# ifndef CLASSMAT_H_
# define CLASSMAT_H_

class matrix
{
private:
	int **num;
	int size;
public:
	void set_mat(int **num);
	void set_size(int size);

	int** get_mat();
	int get_size();

	matrix();
	matrix(int** tmp, int size);
	matrix(const matrix& tmp);
	~matrix();

	void randomfill_matrix();
	void show_matrix();

	int operator+(const matrix& tmp);
	int operator-(const matrix& tmp);
	matrix* operator*(const matrix& tmp);
};



#endif