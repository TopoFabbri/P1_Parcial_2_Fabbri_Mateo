#pragma once
#include "GameObject.h"
class Character : public GameObject
{
private:
	int maxMoves;
	int maxLives;
	int lives;
	int score;
	int moves;

public:
	Character(Vector2 pos, int id);
	~Character() override;

	void start() override;
	void update() override;

	void takeInput();
	int getLives();
	void loseLife();
	int getScore();
	int getMoves();
	void lifeUp();
	void scoreUp();
	void scoreMult();
};