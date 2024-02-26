#include "player.h"
#include "TextureManager.h"

player::player(int n)
{
	src.x = src.y = 0;
	src.w = dst.w = 30;
	src.h = dst.h = 30;

	dst.x = 750 - n;//750(original value)
	dst.y = 390;//390(original value)
}	

player::~player()
{

}

void player::up(const char* filename)
{
	

	p = TextureManager::TextureAss(filename);
	TextureManager::Draw(p, src, dst);
	
}

void player::upinfo(int d,int n)
{
	
	pos += d;
	if (pos >= 99)
		pos = 99;

	dst.x = coordinate[pos].first - n;
	dst.y = coordinate[pos].second;
	
	snake(n);
	
	ladder(n);
	
}

void player::movement()
{
	if (i == 16)
	{
		upp = false;
	}

	if (i == -16)
	{
		upp = true;
	}

	if (upp)
	{
		if (i % 4 == 0)
			dst.y += 1;

		i++;

	}
	else
	{
		if (i % 4 == 0)
			dst.y -= 1;

		i--;
	}
}

void player::snake(int n)
{
	if (snakes.count(pos))
	{
		
		//Sleep(500);
		pos = snakes[pos];
		upinfo(0, n);

	}
}

void player::ladder(int n)
{
	if (ladders.count(pos))
	{
		//Sleep(500);
		pos = ladders[pos];
		upinfo(0, n);
	}
}