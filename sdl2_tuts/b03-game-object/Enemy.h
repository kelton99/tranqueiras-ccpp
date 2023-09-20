#ifndef Enemy_H
#define Enemy_H

#include <string>
#include <SDL2/SDL.h>

#include "SDLGameObject.h"

class Enemy : public SDLGameObject{
    
    public:
        Enemy(const LoaderParams *pParams);
        void draw();
        void update();
        void clean();
};

#endif