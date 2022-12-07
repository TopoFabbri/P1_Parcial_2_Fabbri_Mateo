#pragma once
#include "Collectibles.h"

class ScoreUp : public Collectibles
{
public:
	ScoreUp();
	~ScoreUp() override;

	void start() override;
	void update() override;

	void collect(Character* player) override;
};