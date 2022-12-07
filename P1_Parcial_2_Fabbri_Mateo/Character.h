#pragma once
#include "GameObject.h"
class Character : public GameObject
{
private:
	int maxLives;
	int lives;
	int score;

public:
	Character(Vector2 pos);
	~Character() override;

	void start() override;
	void update() override;

	void takeInput();
	void drawLives();
	int getLives();
	void loseLife();
	int getScore();
	void lifeUp();
	void scoreUp();
};