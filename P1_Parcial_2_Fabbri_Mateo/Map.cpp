#include "Map.h"

Map::Map(Vector2 size)
{
	isActive = false;
	this->size = size;
	player = new Character({5, 5});
	for (int i = 0; i < obsQty; i++)
	{
		obstacles[i] = new Obstacle({ 50, 10 });
	}
}

Map::~Map()
{
	delete player;

	for (int i = 0; i < obsQty; i++)
		delete obstacles[i];
}

void Map::start()
{
	if (!isActive)
	{
		isActive = true;
	}
}

void Map::update()
{
	player->update();

	for (int i = 0; i < obsQty; i++)
	{
		obstacles[i]->update();
	}

	for (int i = 0; i < obsQty; i++)
	{
		if (dynamic_cast<Character*>(player)->checkCollision(dynamic_cast<Obstacle*>(obstacles[i])->getPos(), dynamic_cast<Obstacle*>(obstacles[i])->getCollider()))
			dynamic_cast<Character*>(player)->collideEffect();
	}
}

void Map::draw()
{
	drawFrame({ 0, 0 }, size);
	player->draw();

	for (int i = 0; i < obsQty; i++)
	{
		obstacles[i]->draw();
	}
}