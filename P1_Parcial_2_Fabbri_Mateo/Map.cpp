#include "Map.h"

Map::Map(Vector2 size)
{
	isActive = false;
	this->size = size;
	player = new Character({ 5, 5 });
	character = dynamic_cast<Character*>(player);

	lifePlus = new LifePlus();

	for (int i = 0; i < obsQty; i++)
	{
		obstacles[i] = new Obstacle();
		obs[i] = dynamic_cast<Obstacle*>(obstacles[i]);
	}

	for (int i = 0; i < coinQty; i++)
	{
		coins[i] = new ScoreUp();
		coins[i] = dynamic_cast<ScoreUp*>(coins[i]);
	}
}

Map::~Map()
{
	delete player;
	delete lifePlus;

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
	lifePlus->update();

	for (int i = 0; i < obsQty; i++)
		obstacles[i]->update();

	for (int i = 0; i < obsQty; i++)
	{
		if (character->checkCollision(obs[i]->getPos(), obs[i]->getCollider()))
		{
			character->collideEffect();
			character->loseLife();
		}
	}

	for (int i = 0; i < coinQty; i++)
	{
		if (character->checkCollision(dynamic_cast<ScoreUp*>(coins[i])->getPos(),
			dynamic_cast<ScoreUp*>(coins[i])->getCollider()))
		{
			dynamic_cast<ScoreUp*>(coins[i])->reposition();
			dynamic_cast<ScoreUp*>(coins[i])->collect(character);
		}
	}

	if (character->checkCollision(static_cast<LifePlus*>(lifePlus)->getPos(), static_cast<LifePlus*>(lifePlus)->getCollider()))
	{
		static_cast<LifePlus*>(lifePlus)->reposition();
		static_cast<LifePlus*>(lifePlus)->collect(character);
	}

	if (character->collideWall(size))
		character->collideEffect();
}

void Map::draw()
{
	drawFrame({ 0, 0 }, size);
	player->draw();
	lifePlus->draw();
	character->drawLives();

	for (int i = 0; i < obsQty; i++)
		obstacles[i]->draw();

	for (int i = 0; i < coinQty; i++)
		coins[i]->draw();
}

bool Map::shouldGameEnd()
{
	if (character->getLives() <= 0)
	{
		clearScreen();
		std::cout << "YOU LOSE!\n";
		system("pause");
		return true;
	}

	if (character->getScore() > 1000)
	{
		std::cout << "VICTORY!\n";
		system("pause");
		return true;
	}

	return false;
}

void Map::positionObject(GameObject* obj)
{
	do
	{
		obj->setPos(getRandomPos());

	} while (isObjectColliding(obj));
}

Vector2 Map::getRandomPos()
{
	return { static_cast<float>(rand() % (static_cast<int>(getScreenWidth()) - 2) + 1),
static_cast<float>(rand() % (static_cast<int>(getScreenHeight()) - 2) + 1) };
}

bool Map::isObjectColliding(GameObject* obj)
{
	for (int i = 0; i < obsQty; i++)
	{
		if (obj->checkCollision(obs[i]->getPos(), obs[i]->getCollider()))
			return true;
	}

	for (int i = 0; i < coinQty; i++)
	{
		if (obj->checkCollision(dynamic_cast<ScoreUp*>(coins[i])->getPos(),
			dynamic_cast<ScoreUp*>(coins[i])->getCollider()))
		{
			return true;
		}
	}

	if (obj->checkCollision(static_cast<LifePlus*>(lifePlus)->getPos(), static_cast<LifePlus*>(lifePlus)->getCollider()))
		return true;

	if (obj->collideWall(size))
		return true;

	return false;
}