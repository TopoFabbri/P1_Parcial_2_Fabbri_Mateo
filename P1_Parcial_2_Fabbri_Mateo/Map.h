#pragma once
#include "AwesomeLibrary.h"
#include "Base.h"
#include "Character.h"
#include "Obstacle.h"

class Map : public Base
{
private:
	static const int obsQty = 1;

	Vector2 size;
	Base* player;
	Base* obstacles[obsQty];

public:
	Map(Vector2 size);
	~Map() override;

	void start() override;
	void update() override;
	void draw() override;
};