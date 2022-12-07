#pragma once
#include "GameObject.h"

class Character;

class Collectibles : public GameObject
{
public:
	Collectibles();
	~Collectibles() override;

	virtual void collect(Character* player) = 0;
};