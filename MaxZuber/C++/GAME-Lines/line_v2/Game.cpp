#include "Game.h"
#include <ctime>

Game::Game() {

	dClick_ = false;
	score_ = 0;
	CDTimer_ = 0;
};

void Game::draw()
{
	char str[64];
	Painter& p = *Painter::getInstance();
	sprintf_s(str, 64, "Score: %04i / 1000", score_);
	p.text(str, 5, X::HEIGHT * X::SIZE);
	int x = (5 * 60 - (time(0) - CDTimer_));

	if(x % 60 < 0 )
		x = 0;

	sprintf_s(str, 64, "Time left: %02i:%02i", x / 60, x % 60 );
	p.text(str, X::WIDTH * X::SIZE - 4 * X::SIZE,  X::HEIGHT * X::SIZE);
	nodes_.draw(p);
	
	
}
void Game::click(POINT& point)
{
	if(!dClick_)
	{
		point_.x = point.x;
		point_.y = point.y;
		nodes_.mark(point);
		dClick_ = !dClick_;
	}
	else
	{	
		int size = nodes_.swap(point_,point);		
		Game::draw();

		if(size >= 3)
		{
			score_ += size;
			nodes_.animate();
			nodes_.deleteSolidLine();
		}
		nodes_.clearMarkedPoint();
		dClick_ = !dClick_;
	}
}
void Game::start()
{
	CDTimer_ = time(0);
}

int Game::chekGameOver()
{
	if(time(0) -  CDTimer_ < 5/*min*/  * 60/*sec*/ && score_ < 1000)
	{
		return 0;
	}
	else if(time(0) -  CDTimer_ > 5/*min*/  * 60/*sec*/ && score_ < 1000)
	{
		return X::TIME_END;
	}
	else if(time(0) -  CDTimer_ < 5/*min*/  * 60/*sec*/ && score_ > 1000)
	{
		return X::VICTORY;
	}
	return 0;
}

const std::vector<Score_>&  Game::getScoreList()
{
	scoreList.formFile();
	return scoreList.getPlayerList();
}
void Game::addGameScore(std::string n)
{
	scoreList.add(n, score_);
	scoreList.toFile();
}
