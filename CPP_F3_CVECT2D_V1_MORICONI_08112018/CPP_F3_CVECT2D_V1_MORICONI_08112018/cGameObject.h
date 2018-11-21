#pragma once

#include "cTextureManager.h"
#include "cVect2D.h"

class CGameObject {

public:

	CGameObject(const char* texturesheet, SDL_Renderer* ren);
	CGameObject(const char* texturesheet, SDL_Renderer* ren, int nFrames, int mSpeed);
	~CGameObject();

	void update();
	void render();

	int xpos;
	int ypos;

private:

	//Variable d'animation
	bool animated = false;
	int framesAnimation = 0;
	int speedAnimation = 100;		//millisecondes

	SDL_Texture *objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer *renderer;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

};