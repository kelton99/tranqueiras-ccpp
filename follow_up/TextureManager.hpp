#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP
#include <SDL2/SDL.h>

class TextureManager {

	public:
		static SDL_Texture *loadTexture(const char *filename);
		static void draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
};

#endif