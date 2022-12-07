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
	Color color;

public:
	GameObject();
	~GameObject() override;

	void draw() override;

	void erase();
	void collideEffect();
	bool checkCollision(Vector2 pos, Vector2 boxCollider);
	bool collideWall(Vector2 map);

	void reposition();
	Vector2 getPos();
	Vector2 getCollider();

	void setPos(Vector2 pos);
};