#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP

#include <SDL2/SDL.h>

class TileMap {
	public:
		TileMap();
		~TileMap();
		void loadMap(int arr[20][25]);
		void drawMap();

	private:
		SDL_Rect src, dest;
		SDL_Texture *dirt;
		SDL_Texture *grass;
		SDL_Texture *water;

		int map[20][25];
};

#endif