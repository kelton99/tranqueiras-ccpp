#include "headers/Game.h"

int main(int argc, char *argv[])
{
    const int FPS = 60;
    const int DELAY_TIME = 1000.0f / FPS;

    std::cout << "game init attempt ..." << std::endl;
    
    if(Game::Instance()->init("Retarded", 100, 100, 640, 480, false)) {
        
        Uint32 frameStart, frameTime;

        while(Game::Instance()->running()) {

            frameStart = SDL_GetTicks();

            Game::Instance()->handleEvents();
            Game::Instance()->update();
            Game::Instance()->render();
            
            frameTime = SDL_GetTicks() - frameStart;

            if(frameTime < DELAY_TIME) SDL_Delay((int) (DELAY_TIME - frameTime));
        }

    } else {
        std::cout << "game init failure: " << SDL_GetError() << std::endl;
        return -1;
    }

    std::cout << "game closing" << std::endl;
    Game::Instance()->clean();

    return 0;
}