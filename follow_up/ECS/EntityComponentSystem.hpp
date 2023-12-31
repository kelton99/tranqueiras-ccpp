#ifndef ENTITY_COMPONENT_HPP
#define ENTITY_COMPONENT_HPP

#include <SDL2/SDL.h>
#include <bits/c++config.h>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponenTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template<typename T> inline ComponentID getComponenTypeID() noexcept
{
	static ComponentID typeID = getComponenTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component *, maxComponents>;

class Component {
	public:
		Entity *entity;
		virtual void init() {}
		virtual void update() {}
		virtual void draw() {}
		virtual ~Component() {}
};

class Entity {
	public:
		void update() { for(auto& c: components) c->update();}
		void draw() { for(auto& c: components) c->draw();}
		bool isActive() const {return active;}
		void destroy() {active = false;}
		template<typename T> bool hasComponent() const 
		{
			return componentBitSet[getComponenTypeID<T>];
		}

		template<typename T, typename... TArgs> T& addComponent(TArgs&&... nArgs)
		{
			T* c(new T(std::forward<TArgs>(nArgs)...));
			c->entity = this;
			std::unique_ptr<Component> uPtr{c};
			components.emplace_back(std::move(uPtr));
			componentArray[getComponenTypeID<T>()] = c;
			componentBitSet[getComponenTypeID<T>()] = true;
			c->init();
			return *c;
		}

		template<typename T> T& getComponent() const
		{
			auto ptr(componentArray[getComponenTypeID<T>()]);
			return *static_cast<T*>(ptr);
		}



	private:
		bool active = true;
		std::vector<std::unique_ptr<Component>> components;
		ComponentArray componentArray;
		ComponentBitSet componentBitSet;
};


class Manager {

	public:
		void update() { for(auto& e: entities) e->update(); }
		void draw() { for(auto& e: entities ) e->draw(); }
		void refresh()
		{
			entities.erase(std::remove_if(std::begin(entities), std::end(entities), 
			[](const std::unique_ptr<Entity> &mEntity)
			{
				return !mEntity->isActive();
			}), std::end(entities));
		}
		Entity& addEntity()
		{
			Entity *e = new Entity();
			std::unique_ptr<Entity> uPtr{e};
			entities.emplace_back(std::move(uPtr));
			return *e;
		}
	private:
		std::vector<std::unique_ptr<Entity>> entities;

};


#endif