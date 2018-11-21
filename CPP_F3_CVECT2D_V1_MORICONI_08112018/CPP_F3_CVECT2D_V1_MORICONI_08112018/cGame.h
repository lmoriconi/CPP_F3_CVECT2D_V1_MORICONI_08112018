#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "cGameObject.h"


class CGame {

public:

	CGame();
	~CGame();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

	static SDL_Event event;

private:

	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

};

