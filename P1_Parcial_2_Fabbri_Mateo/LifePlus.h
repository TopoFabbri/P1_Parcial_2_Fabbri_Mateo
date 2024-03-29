#pragma once
#include "Collectibles.h"
#include "GameObject.h"

class LifePlus : public Collectibles
{
public:
	LifePlus(int id);
	~LifePlus() override;

	void start() override;
	void update() override;

	void collect(Character* player) override;
};