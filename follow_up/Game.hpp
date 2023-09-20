#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>

class Game {

	public:
		Game();
		~Game();
		void init(const char *title, int xpos, int ypos, int width, int height);
		void handle_events();
		void update();
		void render();
		void clean();
		bool running() {return is_running;}
		static SDL_Renderer *renderer;
		static SDL_Event event;
	private:
		bool is_running;
		SDL_Window *window;

};
#endif