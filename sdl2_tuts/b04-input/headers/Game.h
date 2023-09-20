#ifndef __Game__
#define __Game__
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Player.h"
#include "GameObject.h"
#include "TextureManager.h"

class Game{

    public:
        ~Game(){}

        bool init(const char* title, int xpos, int ypos, int width, int
                    height, bool fullscreen);

        SDL_Renderer *getRenderer() const {return m_pRenderer;}
        void draw();
        void render();
        void update();
        void handleEvents();
        void clean();
        bool running(){return m_bRunning;}
        static Game *Instance()
        {
            if(s_pInstance == 0){
                s_pInstance = new Game();
                return s_pInstance;
            }
            return s_pInstance;
        }

    private:
        Game(){}

        static Game *s_pInstance;
        typedef Game TheGame;
        SDL_Window *m_pWindow;
        SDL_Renderer *m_pRenderer;

        std::vector<GameObject*> m_gameObjects;
        
        int m_currentFrame;
        bool m_bRunning;

};

#endif