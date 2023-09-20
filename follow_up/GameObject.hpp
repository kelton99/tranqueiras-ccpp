#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <SDL2/SDL.h>

class GameObject {

	public:
		GameObject(const char *textureSheet, int x, int y);
		~GameObject();

		void update();
		void render();

	private:
		int xpos;
		int ypos;
		SDL_Texture *objTexture;
		SDL_Rect srcRect, destRect;
};

#endif