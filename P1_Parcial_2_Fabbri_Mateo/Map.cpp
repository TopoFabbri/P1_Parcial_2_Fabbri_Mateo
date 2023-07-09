#include "Map.h"

Map::Map(Vector2 size)
{
	isActive = false;
	this->size = size;
	player = new Character({ 5, 5 }, 0);
	character = dynamic_cast<Character*>(player);

	lifePlus = new LifePlus(1);

	for (int i = 0; i < obsQty; i++)
	{
		obstacles[i] = new Obstacle(2 + i);
		obs[i] = dynamic_cast<Obstacle*>(obstacles[i]);
	}

	for (int i = 0; i < coinQty; i++)
		coins[i] = new ScoreUp(13 + i);

	for (int i = 0; i < multQty; i++)
		mults[i] = new ScoreMultiply(23 + i);

	hud = new HUD(character);

	positionObject(dynamic_cast<GameObject*>(lifePlus));

	for (int i = 0; i < obsQty; i++)
	{
		positionObject(dynamic_cast<GameObject*>(obs[i]));
	}

	for (int i = 0; i < coinQty; i++)
		positionObject(dynamic_cast<GameObject*>(coins[i]));

	for (int i = 0; i < multQty; i++)
		positionObject(dynamic_cast<GameObject*>(mults[i]));
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
		if (character->checkCollision(obs[i]->getPos(), obs[i]->getCollider(), obs[i]->getId()))
		{
			character->collideEffect();
			character->loseLife();
		}
	}

	if (character->checkCollision(dynamic_cast<LifePlus*>(lifePlus)->getPos(),
		dynamic_cast<LifePlus*>(lifePlus)->getCollider(),
		dynamic_cast<LifePlus*>(lifePlus)->getId()))
	{
		positionObject(dynamic_cast<GameObject*>(lifePlus));
		dynamic_cast<LifePlus*>(lifePlus)->collect(character);
	}

	for (int i = 0; i < coinQty; i++)
	{
		if (character->checkCollision(dynamic_cast<ScoreUp*>(coins[i])->getPos(),
			dynamic_cast<ScoreUp*>(coins[i])->getCollider(),
			dynamic_cast<ScoreUp*>(coins[i])->getId()))
		{
			positionObject(dynamic_cast<GameObject*>(coins[i]));
			dynamic_cast<ScoreUp*>(coins[i])->collect(character);
		}
	}

	for (int i = 0; i < multQty; i++)
	{
		if (character->checkCollision(dynamic_cast<ScoreMultiply*>(mults[i])->getPos(),
			dynamic_cast<ScoreMultiply*>(mults[i])->getCollider(),
			dynamic_cast<ScoreMultiply*>(mults[i])->getId()))
		{
			positionObject(dynamic_cast<GameObject*>(mults[i]));
			dynamic_cast<ScoreMultiply*>(mults[i])->collect(character);
		}
	}

	if (character->collideWall(size))
		character->collideEffect();

	hud->update();
}

void Map::draw()
{
	drawFrame({ 0, 0 }, size);
	player->draw();
	lifePlus->draw();

	for (int i = 0; i < obsQty; i++)
		obstacles[i]->draw();

	for (int i = 0; i < coinQty; i++)
		coins[i]->draw();

	for (int i = 0; i < multQty; i++)
		mults[i]->draw();

	hud->draw();
}

bool Map::shouldGameEnd()
{
	if (character->getLives() <= 0 || character->getMoves() <= 0)
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
		if (obj->checkCollision(obs[i]->getPos(), obs[i]->getCollider(), obs[i]->getId()))
			return true;
	}

	for (int i = 0; i < coinQty; i++)
	{
		if (obj->checkCollision(dynamic_cast<ScoreUp*>(coins[i])->getPos(),
			dynamic_cast<ScoreUp*>(coins[i])->getCollider(),
			dynamic_cast<ScoreUp*>(coins[i])->getId()))
		{
			return true;
		}
	}

	if (obj->checkCollision(static_cast<LifePlus*>(lifePlus)->getPos(),
		static_cast<LifePlus*>(lifePlus)->getCollider(),
		static_cast<LifePlus*>(lifePlus)->getId()))
		return true;

	if (obj->collideWall(size))
		return true;

	return false;
}