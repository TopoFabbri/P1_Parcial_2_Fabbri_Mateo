#include "Obstacle.h"

Obstacle::Obstacle(int id)
{
	exPos = pos;
	reposition();
	boxCollider = { 2, 1 };
	mesh = "^^";
	std::cout << "Created Obstacle\n";
	color = Color::RED;
	this->id = id;
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