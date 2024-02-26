#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Map
{
public:

	Map();
	~Map();

	void Mapping();
	

private:
	
	SDL_Texture * map;

	SDL_Rect src;
	SDL_Rect dst;

	

};