#include <SDL2/SDL.h>
#include "Game.h"

int main(int argc, char **argv)
{
    Game *game = game_init();

    
    while (game_is_running(game)) {

        game_handle_updates(game);

        game_render(game);

    }

    game_clear(game);
    return 0;

}