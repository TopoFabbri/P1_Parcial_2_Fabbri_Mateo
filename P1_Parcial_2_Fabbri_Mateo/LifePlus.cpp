#include "LifePlus.h"

#include "Character.h"

LifePlus::LifePlus(int id)
{
	reposition();
	boxCollider = { 1, 1 };
	mesh = "+";
	std::cout << "Created LifePlus\n";
	color = Color::GREEN;
	this->id = id;
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