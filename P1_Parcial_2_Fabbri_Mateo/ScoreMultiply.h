#pragma once
#include "Collectibles.h"
class ScoreMultiply : public Collectibles
{
	public:
	ScoreMultiply(int id);
	~ScoreMultiply() override;

	void start() override;
	void update() override;

	void collect(Character* player) override;
};