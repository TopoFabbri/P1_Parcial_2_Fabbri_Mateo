#pragma once
#include "AwesomeLibrary.h"
#include "Base.h"
#include "Character.h"
#include "Obstacle.h"
#include "LifePlus.h"
#include "ScoreUp.h"

class Map : public Base
{
private:
	static const int obsQty = 10;
	static const int coinQty = 10;

	Vector2 size;
	Base* player;
	Base* obstacles[obsQty];
	Base* lifePlus;
	Base* coins[coinQty];

	Character* character;
	Obstacle* obs[obsQty];

public:
	Map(Vector2 size);
	~Map() override;

	void start() override;
	void update() override;
	void draw() override;
	bool shouldGameEnd();
	void positionObject(GameObject* obj);
	Vector2 getRandomPos();
	bool isObjectColliding(GameObject* obj);
};