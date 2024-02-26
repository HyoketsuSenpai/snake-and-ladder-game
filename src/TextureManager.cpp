#include "TextureManager.h"

SDL_Texture* TextureManager::TextureAss(const char* filename)
{
	SDL_Surface* tempS = IMG_Load(filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempS);
	SDL_FreeSurface(tempS);

	return tex;
}

void TextureManager::Draw(SDL_Texture * texture,SDL_Rect src,SDL_Rect dst)
{
	SDL_RenderCopy(Game::renderer,texture,&src,&dst);
}
