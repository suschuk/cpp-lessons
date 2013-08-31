# include <iostream>

# ifndef CLASSARRAY_H_
# define CLASSARRAY_H_

class array
{
public:
	array();
	array(int is);
	array(int* ip, int is);
	~array();

	int* get_p();
	int get_size();

	void set_p(int* sp);
	void set_size(int ss);
	
	void randfill_arr();
	void print_arr();
	
	int operator[](int tmp);
	void operator=(const array& tmp);
	array& operator+(array& tmp);
	array& operator-(array& tmp);
	void operator++();
	void operator--();

private:
	int* p;
	int size;
};

# endif