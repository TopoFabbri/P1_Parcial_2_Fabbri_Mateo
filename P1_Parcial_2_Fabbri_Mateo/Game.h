#pragma once

#include "AwesomeLibrary.h"
#include "Base.h"
#include "Map.h"

class Game : public Base
{
private:
	Base* map;

public:
	Game();
	~Game() override;

	void loop();
	void play();

	void start() override;
	void update() override;
	void draw() override;
};