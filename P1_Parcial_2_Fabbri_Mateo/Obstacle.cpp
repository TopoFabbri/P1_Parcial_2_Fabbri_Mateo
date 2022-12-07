#include "Obstacle.h"

Obstacle::Obstacle()
{
	exPos = pos;
	reposition();
	boxCollider = { 2, 1 };
	mesh = "/\\";
	std::cout << "Created Obstacle\n";
	color = Color::RED;
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