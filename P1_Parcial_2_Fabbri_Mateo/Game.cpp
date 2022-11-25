#include "Game.h"

#include <iostream>

Game::Game()
{
	isActive = false;
	map = new Map({getScreenWidth() - 1, getScreenHeight() - 1});
}

Game::~Game()
{
	clearScreen();
	delete map;
	std::cout << "Deleted game\n";
}

void Game::loop()
{
	do
	{
		play();
	}
	while (isActive);
}

void Game::play()
{
	// Start
	if (!isActive)
		start();

	// Update
	update();

	// Draw
	draw();
}

void Game::start()
{
	isActive = true;
	clearScreen();
}

void Game::update()
{
	map->update();
}

void Game::draw()
{
	map->draw();
}