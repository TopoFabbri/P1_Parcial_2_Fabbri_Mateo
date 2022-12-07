#include "LifePlus.h"

#include "Character.h"

LifePlus::LifePlus()
{
	reposition();
	boxCollider = { 1, 1 };
	mesh = "+";
	std::cout << "Created LifePlus\n";
	color = Color::GREEN;
}

LifePlus::~LifePlus()
{
}

void LifePlus::start()
{
}

void LifePlus::update()
{
}

void LifePlus::collect(Character* player)
{
	player->lifeUp();
}