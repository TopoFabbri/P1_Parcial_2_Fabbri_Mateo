#pragma once
#include "Base.h"
#include "Character.h"

class HUD : public Base
{
protected:
	int score;
	int moves;
	int lives;
	Character* player;

public:
	HUD(Character* player);
	~HUD() override;

	void start() override;
	void update() override;
	void draw() override;
};
