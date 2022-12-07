#include "ScoreUp.h"
#include "Character.h"

ScoreUp::ScoreUp()
{
	reposition();
	boxCollider = { 1, 1 };
	mesh = "O";
	std::cout << "Created ScoreUp\n";
	color = Color::YELLOW;
}

ScoreUp::~ScoreUp()
{
}

void ScoreUp::start()
{
}

void ScoreUp::update()
{
}

void ScoreUp::collect(Character* player)
{
	player->scoreUp();
}