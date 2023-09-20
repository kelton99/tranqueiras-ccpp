#include "Game.hpp"
#include "ECS/KeyboardController.hpp"
#include "ECS/TransformComponent.hpp"
#include "ECS/SpriteComponent.hpp"
#include "TextureManager.hpp"
#include "TileMap.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"

TileMap *map;
Manager manager;

SDL_Renderer *Game::renderer = nullptr;

SDL_Event Game::event;

auto& player(manager.addEntity());

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystens Initialised!..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_RESIZABLE);

		if(window)
			std::cout << "window created!" << std::endl;
		
		renderer = SDL_CreateRenderer(window, -1, 0);

		if(renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}
		is_running = true;
		map = new TileMap();
		player.addComponent<TransformComponent>();
		player.addComponent<SpriteComponent>("assets/player.png");
		player.addComponent<KeyboardController>();
	} else {
		is_running = false;
	}
}

void Game::handle_events()
{
	SDL_PollEvent(&event);
	switch(event.type) {
		case SDL_QUIT:
			is_running = false;
			break;
	}
}

void Game::update()
{
	manager.refresh();
	manager.update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->drawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleared" << std::endl;
}