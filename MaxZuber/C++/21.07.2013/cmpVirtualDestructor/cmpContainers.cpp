#include <iostream>
#include <array>
#include <deque>
#include <vector>
#include <list>
#include <ctime>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <exception>
#include <stdlib.h>

using namespace std;

const int REPEAT_TEST = 300;
const int NUM_OPERATIONS[3] = {500, 1000, 2500};



template <class Cont>
void push_back(Cont& c, long& avg, const int& num_op)
{
	cout << "\nCounting..." 
		 << "time of " << num_op << " push_back";
	clock_t t = 0;
	for(int j = 0; j < REPEAT_TEST; ++j)
	{
		t = clock();
		for (int i = 1; i <= num_op ; ++i)
		{

			c.push_back(i);

		}
		t = clock() - t;
		avg += t;
		c.clear();
	}

	c.clear();
	avg /= REPEAT_TEST;
}

template <class Cont>
void insert_front(Cont& c, long& avg, const int& num_op)
{
	cout << "\nCounting..." 
		<< "time of " << num_op << " front_insert";
	clock_t t = 0;

	for(int j = 0; j < REPEAT_TEST; ++j)
	{

		c.push_back(0);
		c.push_back(0);

		auto it = c.begin();
		t = clock();
		for (int i = 1; i <= num_op ; ++i)
		{
			it  = c.begin();
			c.insert(it, i);		
		}

		t = clock() - t;
		avg += t;
		c.clear();
	}


	avg /= REPEAT_TEST;
}

template <class Cont>
void insert_back(Cont& c, long& avg, const int& num_op)
{
	cout << "\nCounting..." 
		<< "time of " << num_op << " back_insert";
	clock_t t = 0;

	for(int j = 0; j < REPEAT_TEST; ++j)
	{

		c.push_back(0);
		c.push_back(0);

		auto it = c.end();
		t = clock();
		for (int i = 1; i <= num_op ; ++i)
		{
			it = c.end();
			c.insert(it, i);		
		}

		t = clock() - t;
		avg += t;
		c.clear();
	}


	avg /= REPEAT_TEST;
}

template <class Cont>
void insert_midl(Cont& c, long& avg, const int& num_op)
{
	cout << "\nCounting..." 
		<< "time of " << num_op << " insert to the middle";
	clock_t t = 0;

	for(int j = 0; j < REPEAT_TEST; ++j)
	{

		c.push_back(0);
		c.push_back(0);

		auto it = c.begin();

		t = clock();
		for (int i = 1; i <= num_op ; ++i)
		{
			it  = c.begin() + i/2;
			c.insert(it, i);
		}

		t = clock() - t;
		avg += t;
		c.clear();
	}


	avg /= REPEAT_TEST;
}


struct TEST_RESULT
{
	long pb_avg[3];		//0-vector, 1-deque, 2-list
	long ins_back[3];
	long ins_front[3];
	long ins_midl[3];
};

void setWindowSize();
void toFile(TEST_RESULT*, const int& size) throw(bad_alloc);
void fromFile(TEST_RESULT*, const int& size) throw(bad_alloc);

int main()
{
	setWindowSize();
	clock_t t = 0;
	long v_pb = 0, v_ins_b = 0, v_ins_f = 0;
	long d_pb = 0, d_ins_b = 0, d_ins_f = 0;
	long l_pb = 0, l_ins_b = 0, l_ins_f = 0;

	string containers[3] = {"Vector", "Deque", "List"};

	const int res_SIZE = 3;
	TEST_RESULT res[3] = {0};
	

	vector<int> v;
	v.push_back(0);

	deque<int> dek;
	dek.push_back(0);

	list<int> l;
	l.push_back(0);

	int choice = 0;
	bool exit = true;
	
	do
	{
		system("cls");
		cout << "         :::MENU:::\n";
		cout << "0 -  exit\n"
			<< "1 - run test\n"
			<< "2 - see result of last test\n"
			<< "3 - write test resul to file\n"
			<< "4 - read resul from file\n" << endl;
		fflush(stdin);
		cin >> choice;
		switch(choice)
		{
		case 0: exit = false; break;
		case 1:
			for(int i = 0; i < 3; i++)
			{
				cout << "\n\n\n    " << containers[0] << endl;
				push_back(v, res[i].pb_avg[0], NUM_OPERATIONS[i]);
				insert_front(v, res[i].ins_front[0], NUM_OPERATIONS[i]);
				insert_back(v, res[i].ins_back[0], NUM_OPERATIONS[i]);
				insert_midl(v, res[i].ins_midl[0], NUM_OPERATIONS[i]);

				cout << "\n\n\n    " << containers[1] << endl;
				push_back(dek, res[i].pb_avg[1], NUM_OPERATIONS[i]);
				insert_front(dek,res[i].ins_front[1], NUM_OPERATIONS[i]);
				insert_back(dek,res[i].ins_back[1], NUM_OPERATIONS[i]);
				insert_midl(dek, res[i].ins_midl[1], NUM_OPERATIONS[i]);

				cout << "\n\n\n    " << containers[2] << endl;
				push_back(l, res[i].pb_avg[2], NUM_OPERATIONS[i]);
				insert_front(l, res[i].ins_front[2], NUM_OPERATIONS[i]);
				insert_back(l, res[i].ins_back[2], NUM_OPERATIONS[i]);		
			}
			cout << "\n TEST FINISH \n";
			system("PAUSE");
			break;
		case 2:
			cout << endl << setw(142) <<"RESULT TABLE" << endl << endl;
			cout << setw(22) <<  " |" << setw(70) << "Number of operation's" << setw(50) << "|" << endl<< endl;
			cout << setw(20) << "" << " |" << setw(20) << NUM_OPERATIONS[0] << setw(20) << "|" << setw(20) << NUM_OPERATIONS[1]
			<< setw(20) << "|" << setw(20) << NUM_OPERATIONS[2] << setw(20) << "|" << endl << endl;

			cout << setw(22) << "" << setfill('-') << setw(120) << ""<< setfill(' ')<<endl;

			cout << setw(20) << "" << " |" << setw(60) << "TEST NAME" << setw(60) << "|" << endl;

			cout << setw(22) << "" <<  setfill('-') << setw(120) << ""<< setfill(' ') <<endl << endl;

			cout << setw(20) << "" << " |" << setw(10) << "p_back" << setw(10) << "f_ins" << setw(10) << "m_ins" << setw(10) << "b_ins |" 
				<< setw(10) << "p_back" << setw(10) << "f_ins" << setw(10) << "m_ins" << setw(10) << "b_ins |"
				<< setw(10) << "p_back" << setw(10) << "f_ins" << setw(10) << "m_ins" << setw(10) << "b_ins |" << endl << endl;

			cout <<setw(22) << "" << setfill('_') << setw(120) << ""<< setfill(' ') <<endl << endl;

			cout << setw(15) << "Container" << setw(7) << " |" << setw(60) << "Time, msec" << setw(60) << "|" << endl;
			cout << setfill('-') << setw(142) << ""<< endl << endl;
			for(int i = 0; i < 3; ++i)
			{
				cout << setfill(' ') << setw(20) << containers[i] << " |";
				for(int j = 0; j < 3; ++j)
				{
					cout << setw(9) << res[j].pb_avg[i] << setw(10) << res[j].ins_front[i] << setw(10) << res[j].ins_midl[i]
					<< setw(10) << res[j].ins_back[i] << "|";
				}
				cout << endl;
			}

			cout << "*\n TEST NAMES:"
				<< "\np_back - Push to the back of container"
				<< "\nf_ins - Insert to the front position of container"
				<< "\nm_ins - Insert to the middle position of container"
				<< "\nb_ins - Insert to the last position of container" << endl;

			system("PAUSE");
			break;
		case 3:
			try 
			{
				toFile(res, res_SIZE);
			}
			catch( bad_alloc& x)
			{
				cout << endl << x.what() << endl;
			}
			system("PAUSE");
			break;
		case 4:
			try
			{
				fromFile(res, res_SIZE);
			}
			catch(bad_alloc& x)
			{
				cout << endl << x.what() << endl;
			}
			system("PAUSE");
			break;
		default: continue;

		}
	} while (exit);

	return 0;
}

void setWindowSize()
{
	int Height = 80;
	int Width = 150;

	_COORD coord; 
	coord.X = Width; 
	coord.Y = Height; 

	_SMALL_RECT Rect; 
	Rect.Top = 0; 
	Rect.Left = 0; 
	Rect.Bottom = Height - 1; 
	Rect.Right = Width - 1; 

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}

void toFile(TEST_RESULT* res, const int& size)
{
	ofstream out;
	out.open("Test_result.dat", ios::binary | ios::out);
	
	if(!out)
	{
		out.close();
		throw bad_alloc("Write error");
	}

	out.write(reinterpret_cast<char*>(res), size * sizeof(TEST_RESULT));
	out.close();
}
void fromFile(TEST_RESULT* res, const int& size) 
{

		ifstream in;
		in.open("Test_result.dat", ios::binary | ios::in);


		if(!in)
		{
			in.close();
			throw bad_alloc("Read error");
		}

		in.read(reinterpret_cast<char*>(res), size * sizeof(TEST_RESULT));
		in.close();



}