#include "cGameObject.h"

const int SIZE = 48;		//Taille de mon joueur
const int X_BOUND = 800;	//Limite du terrain en X
const int Y_BOUND = 600;	//Limite du terrain en Y
const int SPEED = 3;		//Vitesse du joueur

//Constructeur
CGameObject::CGameObject(const char * texturesheet, SDL_Renderer * ren) {

	renderer = ren;
	objTexture = CTextureManager::LoadTexture(texturesheet, ren);
}

//Constructeur animation
CGameObject::CGameObject(const char * texturesheet, SDL_Renderer * ren, int nFrames, int mSpeed) {

	framesAnimation = nFrames;
	speedAnimation = mSpeed;

	renderer = ren;
	objTexture = CTextureManager::LoadTexture(texturesheet, ren);

}

//Destructeur
CGameObject::~CGameObject() {}

void CGameObject::update() {

	//Taille image
	srcRect.h = SIZE;
	srcRect.w = SIZE;
	srcRect.x = 0;
	srcRect.y = 0;

	//Animation
	if (animated)
		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speedAnimation) % framesAnimation);

	//Gestion inputs
	const Uint8 *statekey = SDL_GetKeyboardState(NULL);
	if (statekey[SDL_SCANCODE_W]) {
		
		if (ypos - SPEED > 0) {
			ypos -= SPEED;
			animated = true;
		}
	}

	if (statekey[SDL_SCANCODE_S]) {

		if (ypos + SPEED < Y_BOUND-SIZE) {
			ypos += SPEED;
			animated = true;
		}

	}

	if (statekey[SDL_SCANCODE_A]) {

		if (xpos - SPEED > 0) {
			xpos -= SPEED;
			animated = true;
			flip = SDL_FLIP_HORIZONTAL;
		}
	}

	if (statekey[SDL_SCANCODE_D]){

		if (xpos + SPEED < X_BOUND-SIZE) {
			xpos += SPEED;
			animated = true;
			flip = SDL_FLIP_NONE;
		}
	}

	//Key is up
	if (CGame::event.type == SDL_KEYUP) {
		switch (CGame::event.key.keysym.sym) {
			
			default:
				animated = false;
				break;
		}
	}

	//Rectangle de destination
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

//affichage du GameObject
void CGameObject::render() {
	
	SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, 0, 0, flip);
}
