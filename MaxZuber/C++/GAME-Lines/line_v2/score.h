#pragma once

#include <string>
#include <vector>
struct Score_
{
	std::string name;
	int score;

	Score_(std::string n = "Player", int sc = 0): name(n), score(sc) {};
};

class Score
{

public:
	void toFile();
	void formFile();
	void add(std::string, int scor);

	const std::vector<Score_>& getPlayerList();
private:

	
	std::vector<Score_> plays_;
};