#include "Game.h"

int main(int argc, char *argv[])
{
    std::cout << "game init attempt ..." << std::endl;
    
    if(Game::Instance()->init("Retarded", 100, 100, 640, 480, false)) {
        
        while(Game::Instance()->running()) {
            Game::Instance()->handleEvents();
            Game::Instance()->update();
            Game::Instance()->render();
            SDL_Delay(10);
        }

    } else {
        std::cout << "game init failure: " << SDL_GetError() << std::endl;
        return -1;
    }

    std::cout << "game closing" << std::endl;
    Game::Instance()->clean();

    return 0;
}