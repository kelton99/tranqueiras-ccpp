#include <iostream>
#include "headers/Game.h"
#include "headers/TextureManager.h"
#include "headers/Enemy.h"
#include "headers/InputHandler.h"

Game *Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width,
int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen) flags = SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL init success" << std::endl;
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(m_pWindow != 0) {
            std::cout << "window creation success" << std::endl;
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer != 0){
                std::cout << "renderer creation success" << std::endl;
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            } else {
                std::cout << "renderer init fail" << std::endl;
                return false;
            }
        } else {
            std::cout << "window init fail" << std::endl;
            return false;
        }
    } else {
        std::cout << "SDL init fail" << std::endl;
        return false;
    }

    std::cout << "init success" << std::endl;
    if(!TextureManager::Instance()->load("char9.png", "animate", m_pRenderer))
        return false;

    m_gameObjects.push_back(new Player((new LoaderParams(100, 100, 128, 82, "animate"))));
    m_gameObjects.push_back(new Enemy((new LoaderParams(300, 300, 128, 82, "animate"))));
  
    m_bRunning = true;

    return true;
}

void Game::draw()
{
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++){
        m_gameObjects[i] -> draw();
    }
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++){
        m_gameObjects[i] -> draw();
    }
    SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++){
        m_gameObjects[i] -> update();
    }
}

void Game::handleEvents()
{
    InputHandler::Instance()->update();
}

void Game::clean()
{
    std::cout << "cleaning game" << std::endl;
    InputHandler::Instance()->clean();
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

