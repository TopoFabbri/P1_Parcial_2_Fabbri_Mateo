#pragma once
#include "GameObject.h"
class Obstacle : public GameObject
{
public:
	Obstacle();
	~Obstacle() override;

	void start() override;
	void update() override;
};