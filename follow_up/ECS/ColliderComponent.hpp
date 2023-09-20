#ifndef COLLIDER_COMPONENT_HPP
#define COLLIDER_COMPONENT_HPP

#include "EntityComponentSystem.hpp"
#include "TransformComponent.hpp"
#include <SDL2/SDL_rect.h>
#include <string>
#include <SDL2/SDL.h>

class ColliderComponent : public Component {
	
	public:
		void init() override
		{
		
		}



	private:
		SDL_Rect collider;
		std::string tag;
		TransformComponent *transform;
};

#endif