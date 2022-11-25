#pragma once
#include "GameObject.h"
class Character : public GameObject
{
public:
	Character(Vector2 pos);
	~Character() override;

	void start() override;
	void update() override;

	void takeInput();
	bool checkCollision(Vector2 pos, Vector2 boxCollider) override;
};