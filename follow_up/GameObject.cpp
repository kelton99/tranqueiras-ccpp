#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "Game.hpp"

GameObject::GameObject(const char *textureSheet, int x, int y)
{
	objTexture = TextureManager::loadTexture(textureSheet);
	xpos = x;
	ypos = y;
}

void GameObject::update()
{
	xpos++;
	ypos++;
	srcRect.h = srcRect.w = 15;
	srcRect.x = srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}