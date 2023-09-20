#include <iostream>
#include "Game.h"


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

    m_pTexture = IMG_LoadTexture(m_pRenderer, "char9.png");
    
    m_sourceRectangle.x = m_destinationRectangle.x = 0;
    m_sourceRectangle.y = 60;
    m_destinationRectangle.y = 0;
    m_sourceRectangle.w = m_destinationRectangle.w = 110;
    m_sourceRectangle.h = m_destinationRectangle.h = 80;

    std::cout << "init success" << std::endl;
    m_bRunning = true;

    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
    m_sourceRectangle.x = 128 * int((SDL_GetTicks() / 100) % 5);
}

void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT:
                m_bRunning = false; 
                break;
            
            default: break;
        }
    }
}

void Game::clean()
{
    std::cout << "cleaning game" << std::endl;
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

