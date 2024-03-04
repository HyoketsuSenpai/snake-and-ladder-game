#include "Game.h"
#include "Map.h"
#include "player.h"



Map* map;
player* p1;
player* p2;



SDL_Renderer* Game::renderer = nullptr;




Game::Game()
{}

Game::~Game()
{}

void Game::ini(const char* title, int width, int height, int fullscreen)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	if (fullscreen == 1)
		fullscreen = SDL_WINDOW_FULLSCREEN;
	else
		fullscreen = SDL_WINDOW_SHOWN;

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, fullscreen);
	renderer = SDL_CreateRenderer(window,0,-1);
	SDL_SetRenderDrawColor(renderer,255, 255, 25, 255);
	isrunning = true;

	map = new Map();
	p1 = new player(0);
	p2 = new player(30);

}

void Game::eventHandler()
{
	
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		isrunning = false;
	}
	else if (event.type == SDL_KEYDOWN)
	{
		static int i = 0;
		if (i % 2 == 0)
			p1->upinfo(dice_roll(), 0);
		else
			p2->upinfo(dice_roll(), 30);
		i++;
		/*switch (event.key.keysym.sym)
		{
		case SDLK_s:
			p1->down();
			break;
		case SDLK_w:
			p1->up();
			break;
		case SDLK_d:
			p1->right();
			break;
		case SDLK_a:
			p1->left();
			break;
		case SDLK_p:
			p1->dis();
		default:
			break;
			p1->movement();

		}*/
	
		//roll dice here
	}
}

void Game::update()
{
	p1->movement();
	p2->movement();
}


void Game::render()
{
	SDL_RenderClear(renderer);
	//render individual objects

	map->Mapping();
	p1->up("assets/p1.png");
	p2->up("assets/p2.png");
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

}

int Game::dice_roll()
	{
	static std::mt19937 mt{ std::random_device{}()};
		std::uniform_int_distribution<int> die6{ 1, 6 };
		return die6(mt);
	}