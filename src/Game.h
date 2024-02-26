#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include<iostream>
#include<cstdlib>
#include<ctime>

class Game
{
public:

	Game();
	~Game();

	void ini(const char * title,int width,int height,int fullscreen);
	void eventHandler();
	void update();
	void render(); 
	void clean();
	int dice_roll();
	bool isRunning() {return isrunning;}

	static SDL_Renderer* renderer;

private:

	bool isrunning{};
	SDL_Window* window;

};

