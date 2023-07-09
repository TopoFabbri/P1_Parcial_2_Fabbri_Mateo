#pragma once
#include "GameObject.h"
class Obstacle : public GameObject
{
public:
	Obstacle(int id);
	~Obstacle() override;

	void start() override;
	void update() override;
};