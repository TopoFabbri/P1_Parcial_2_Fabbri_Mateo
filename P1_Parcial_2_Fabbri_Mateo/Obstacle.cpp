#include "Obstacle.h"

Obstacle::Obstacle(Vector2 pos)
{
	exPos = pos;
	this->pos = pos;
	boxCollider = { 6, 1 };
	mesh = "/\\/\\/\\";
	std::cout << "Created Obstacle\n";
}

Obstacle::~Obstacle()
{
	std::cout << "Deleted Obstacle";
}

void Obstacle::start()
{
}

void Obstacle::update()
{
}

Vector2 Obstacle::getPos()
{
	return pos;
}

Vector2 Obstacle::getCollider()
{
	return boxCollider;
}