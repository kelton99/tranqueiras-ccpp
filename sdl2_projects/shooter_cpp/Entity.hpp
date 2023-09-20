#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>

class Entity {

    public:
        Entity(int x, int y, int side, SDL_Texture *texture);

    private:
        double x;
        double y;
        double dx;
        double dy;
        int h;
        int w;
        int health;
        int reload;
        SDL_Texture *texture;
};

#endif