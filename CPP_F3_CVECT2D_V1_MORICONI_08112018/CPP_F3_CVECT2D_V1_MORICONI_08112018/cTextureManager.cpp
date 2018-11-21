#include "cTextureManager.h"

SDL_Texture * CTextureManager::LoadTexture(const char * fName, SDL_Renderer * ren)
{
	SDL_Surface* tempSurface = IMG_Load(fName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}
