#include "ScoreMultiply.h"

#include "Character.h"

ScoreMultiply::ScoreMultiply(int id)
{
	reposition();
	boxCollider = { 1, 1 };
	mesh = "*";
	std::cout << "Created ScoreMultiply\n";
	color = Color::MAGENTA;
}

ScoreMultiply::~ScoreMultiply()
{
}

void ScoreMultiply::start()
{
}

void ScoreMultiply::update()
{
}

void ScoreMultiply::collect(Character* player)
{
	player->scoreMult();
}