#include "cGame.h"

CGameObject *player;
SDL_Event CGame::event;

void CGame::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;

	if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "Subsystems Initialized!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window) std::cout << "Window Created!" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		
		if (renderer) {

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}
		isRunning = true;
	}
	else isRunning = false;
	
	//Création du player GameObject
	player = new CGameObject("Assets/player.png", renderer, 4, 100);

}

//Quit function
void CGame::handleEvents() {

	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) isRunning = false;
}

//MAJ du player gameObject
void CGame::update() {

	player->update();
}

//Actualiser affuchage
void CGame::render() {

	SDL_RenderClear(renderer);
	player->render();
	SDL_RenderPresent(renderer);

}
//Fermer fenêtre, détruire Renderer et quitter jeu
void CGame::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned !" << std::endl;
}

//True si jeu lancé
bool CGame::running()
{
	return isRunning;
}


CGame::CGame() {}

CGame::~CGame() {}