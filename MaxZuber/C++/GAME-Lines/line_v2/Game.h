#pragma once

#include "Painter.h"
#include "Nodes.h"
#include "define.h"
#include "score.h"

class Game
{
public:
	Game();
	void draw();
	void click(POINT& point);
	void start();
	int chekGameOver();
	const std::vector<Score_>&  getScoreList();
	void addGameScore(std::string n);

private:
	POINT point_;
	Nodes nodes_;
	bool dClick_;
	int score_;
	int CDTimer_;
	Score scoreList;
};