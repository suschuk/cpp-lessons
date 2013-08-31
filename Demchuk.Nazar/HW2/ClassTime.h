# ifndef CLASSTIME_H_
# define CLASSTIME_H_

class time
{
public:
	time();
	time(int s);
	time(int s, char* h);
	time(time& tmp);
	~time();

	void amer_fill();
	void fill();
	void print();
	void convert_toAmer();
	void convert_fromAmer();
	void compare(time& a, time& b);
	void equalize();

	void operator+(time& some);
	void operator-(time& some);
private:
	int min;
	char* half;
};


#endif