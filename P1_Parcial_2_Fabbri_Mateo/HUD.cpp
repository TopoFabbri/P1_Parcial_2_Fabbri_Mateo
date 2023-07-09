#include "HUD.h"

HUD::HUD(Character* player)
{
	this->player = player;
	score = 0;
	moves = 0;
	lives = 3;
}

HUD::~HUD()
{
}

void HUD::start()
{
}

void HUD::update()
{
	score = player->getScore();
	lives = player->getLives();
	moves = player->getMoves();
}

void HUD::draw()
{
	goToCoordinates({ 1, 1 });
	std::cout << "               ";
	goToCoordinates({ 1, 1 });
	std::cout << "Score: " << score;

	goToCoordinates({ getScreenWidth() / 2 - 1, 1 });
	std::cout << "      ";
	goToCoordinates({ getScreenWidth() / 2 - 1, 1 });
	for (int i = 0; i < lives; i++)
	{
		std::cout << "<3";
	}

	goToCoordinates({ getScreenWidth() - 20, 1 });
	std::cout << "          ";
	goToCoordinates({ getScreenWidth() - 20, 1 });
	std::cout << "Moves: " << moves;
}