#include "score.h"
//#include <iostream>
#include <fstream>
#include <algorithm>


bool sort(Score_ one, Score_ two)
{
	return one.score > two.score;
}

void Score::toFile()
{
	std::ofstream out;
	out.open("Score.dat", std::ios::binary| std::ios::app );
	if(out.is_open())
	{
		for(auto it = plays_.begin(); it != plays_.end(); ++it)
		{
			int len = it->name.length();
			out.write((char*)&len, sizeof(len));
			out.write(it->name.c_str(), len);
			out.write((char*)&it->score, sizeof(it->score));
		}
	}
	out.close();
	plays_.clear();

}
void Score::formFile()
{
	plays_.clear();

	std::ifstream in("Score.dat", std::ios::binary);
	Score_ sc;
	if(in.is_open())
	{
		while(!in.eof())
		{

			int len = 0;
			in.read((char*)&len, sizeof(len));
			sc.name.resize(len);
			char buffer[64];
			in.read((char*)&buffer, len);
			buffer[len] = 0;
			int scor = 0;
			in.read((char*)&scor, sizeof(scor));
			plays_.push_back(Score_(buffer, scor));
		}
		plays_.pop_back();
	}
	in.close();

	std::sort(plays_.begin(), plays_.end(), &sort);
}
void Score::add(std::string name, int scor)
{
	plays_.push_back(Score_(name, scor));
}

const std::vector<Score_>& Score::getPlayerList()
{
	return plays_;
}
