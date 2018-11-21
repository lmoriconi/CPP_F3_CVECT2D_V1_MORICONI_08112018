#pragma once

#include "cGame.h"

class CTextureManager {

public:
	
	static SDL_Texture *LoadTexture(const char* fName, SDL_Renderer* ren);

};