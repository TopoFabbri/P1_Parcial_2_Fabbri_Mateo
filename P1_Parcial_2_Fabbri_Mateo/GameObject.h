#pragma once
#include "AwesomeLibrary.h"
#include "Base.h"

class GameObject : public Base
{
protected:
	Vector2 exPos;
	Vector2 pos;
	Vector2 boxCollider;
	std::string mesh;

public:
	GameObject();
	~GameObject() override;

	void draw() override;

	void erase();
	void collideEffect();
	virtual bool checkCollision(Vector2 pos, Vector2 boxCollider);
};