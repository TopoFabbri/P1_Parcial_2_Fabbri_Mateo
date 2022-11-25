#pragma once
#include "GameObject.h"
class Obstacle : public GameObject
{
public:
	Obstacle(Vector2 pos);
	~Obstacle() override;

	void start() override;
	void update() override;

	Vector2 getPos();
	Vector2 getCollider();
};