#ifndef TRANSFORM_COMPONENT_HPP
#define TRANSFORM_COMPONENT_HPP

#include "EntityComponentSystem.hpp"
#include "../Vector2D.hpp"

struct TransformComponent : public Component {

	Vector2D position;
	Vector2D velocity;
	int speed = 3;


	TransformComponent() { position = Vector2D(); }

	TransformComponent(double x, double y) { position = Vector2D(x, y);}

	void init() override
	{
		velocity = Vector2D();
	}
	void update() override
	{
			position.x += velocity.x * speed;
			position.y += velocity.y * speed;
	}
};

#endif