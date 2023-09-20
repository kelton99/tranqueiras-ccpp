#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "Game.hpp"

int main(void)
{

	const int FPS = 60;
	const int frame_delay = 1000/FPS;
	Uint32 frame_start;
	int frame_time;

	Game game;
	game.init("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640);
	while(game.running()) {
		frame_start = SDL_GetTicks();
		game.handle_events();
		game.update();
		game.render();

		frame_time = SDL_GetTicks() - frame_start;

		if(frame_delay > frame_time)
			SDL_Delay(frame_delay - frame_time);
	}

	game.clean();
	return 0;
}
