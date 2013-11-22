#include "Game.h"
#include "ctime"

Game::Game(unsigned p ): points(p), nodes(Nodes())
{
	buffer = 0;
	hBitmap = 0;
	dclick = false;
	img = Gdiplus::Image::FromFile(L"../mark.png", FALSE);
}

void Game::draw(Painter& p, HDC& hdc)
{
	char str[64];
	buffer = CreateCompatibleDC(hdc);
	hBitmap = CreateCompatibleBitmap(hdc, SIZE * WIDTH, SIZE * HEIGHT + 2 * HEIGHT);
	SelectObject(buffer, hBitmap); 
	p.setHDC(buffer);
	nodes.draw(p);
	sprintf_s(str, 64, "Score: %i", points);
	p.text(str, 5, SIZE * HEIGHT);
	BitBlt(hdc, 0, 0, SIZE * WIDTH, SIZE * HEIGHT + 2 * HEIGHT, buffer, 0, 0, SRCCOPY);
	DeleteDC(buffer);
	DeleteObject(hBitmap);
	p.releaseDC();


}
void Game::move(Painter& p, HDC& hdc,int x, int y)
{
	static std::vector<POINT>* line;
	static POINT p1, p2;
	char str[64];
	buffer = CreateCompatibleDC(hdc);
	hBitmap = CreateCompatibleBitmap(hdc, SIZE * WIDTH, SIZE * HEIGHT + 2 * HEIGHT);
	SelectObject(buffer, hBitmap); 
	p.setHDC(buffer);

	nodes.draw(p);
	sprintf_s(str, 64, "Score: %i", points);
	p.text(str, 5, SIZE * HEIGHT);
	if(!dclick)
	{
		p1.x= x; 
		p1.y =y;
		p.mark(img, 4 + p1.x * 50, 3 + p1.y * 50);
		dclick = true;
	}
	else
	{	
		p2.x = x; 
		p2.y = y;

		line = nodes.swap(p1,p2);

		if(line->size() >= 3)
		{
			points += line->size();
			nodes.draw(p);
			sprintf_s(str, 64, "Score: %i", points);
			p.text(str, 5, SIZE * HEIGHT);

			auto it = line->begin();
			for(; it < line->end(); ++it)
			{
				p.mark(img, 4 +it->x * 50,3 + it->y * 50 );
				BitBlt(hdc,0,0, SIZE * WIDTH,SIZE * HEIGHT + 2 * HEIGHT, buffer,0,0, SRCCOPY);
				Sleep(90);
			}
			nodes.deleteSolidLine();
		}
		else
		{
			nodes.swap(p1, p2);
		}
		line->clear();
		nodes.draw(p);
		sprintf_s(str, 64, "Score: %i", points);
		p.text(str, 5, SIZE * HEIGHT + HEIGHT);
		dclick =!dclick;
	}

	p.text(str, 5, SIZE * HEIGHT);
	BitBlt(hdc,0,0, SIZE * WIDTH, SIZE * HEIGHT, buffer,0,0, SRCCOPY);
	p.releaseDC();

}