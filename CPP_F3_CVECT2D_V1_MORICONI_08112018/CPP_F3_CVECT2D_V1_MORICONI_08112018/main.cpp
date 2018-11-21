#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "cGame.h"

int main(int argc, char * argv[]) {

	const int fps = 60;
	const int frameDelay = 1000 / fps;

	Uint32 frameStart;
	int frameTime;

	CGame game;

	game.init("Lenny's Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	//Boucle de jeu
	while (game.running()) {

		frameStart = SDL_GetTicks();

		game.handleEvents();
		game.update();
		game.render();

		//Gestion des FPS
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {

			SDL_Delay(frameDelay - frameTime);
		}
	}

	game.clean();

	return 0;
}