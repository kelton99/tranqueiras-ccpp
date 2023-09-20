#include <SDL2/SDL.h>

typedef struct Game Game;

struct Game {

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    int is_running;

};

Game *game_init();
int game_is_running(Game *game);
void game_handle_updates(Game *game);
void game_render(Game *game);
void game_update(Game *game);
void game_clear(Game *game);