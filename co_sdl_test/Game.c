#include <SDL2/SDL.h>
#include <stdlib.h>

#include "Game.h"

Game *game_init()
{

    Game *game = malloc(sizeof(Game));
    game->is_running = 1;

    if(SDL_Init(SDL_INIT_EVERYTHING)){
        printf("Error: %s", SDL_GetError());
        game->is_running = 0;
    }

    if(SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &game->window, &game->renderer)){
        printf("Error: %s", SDL_GetError());
        game->is_running = 0;
    }

    return game;
}

int game_is_running(Game *game)
{
    return game->is_running;
}

void game_handle_updates(Game *game)
{
    SDL_PollEvent(&game->event);
    if (game->event.type == SDL_QUIT) 
        game->is_running = 0;
        
}

void game_render(Game *game)
{        
        SDL_SetRenderDrawColor(game->renderer, 0x00, 0x25, 0x00, 0x00);
        SDL_RenderClear(game->renderer);
        SDL_RenderPresent(game->renderer);
}

void game_clear(Game *game)
{
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->renderer);
    SDL_Quit();
}