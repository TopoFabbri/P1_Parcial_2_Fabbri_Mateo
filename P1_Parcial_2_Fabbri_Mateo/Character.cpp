#include "Character.h"

Character::Character(Vector2 pos, int id)
{
	maxMoves = 400;
	maxLives = 3;
	lives = 3;
	score = 0;
	moves = maxMoves;
	exPos = pos;
	this->pos = pos;
	boxCollider = { 3, 3 };
	mesh = " 0 /|\\/ \\";
	std::cout << "Created Character\n";
	color = Color::CYAN;
	this->id = id;
}

Character::~Character()
{
	std::cout << "Deleted Character\n";
}

void Character::start()
{
}

void Character::update()
{
	exPos = pos;
	takeInput();
}

void Character::takeInput()
{
	int key = getKey(false);
	key = tolower(key);

	if (key == 'w')
	{
		pos.y--;
		moves--;
	}

	if (key == 's')
	{
		pos.y++;
		moves--;
	}

	if (key == 'a')
	{
		pos.x--;
		moves--;
	}

	if (key == 'd')
	{
		pos.x++;
		moves--;
	}
}

int Character::getLives()
{
	return lives;
}

void Character::loseLife()
{
	lives--;
}

int Character::getScore()
{
	return score;
}

int Character::getMoves()
{
	return moves;
}

void Character::lifeUp()
{
	if (lives + 1 <= maxLives)
		lives++;
}

void Character::scoreUp()
{
	score++;
}

void Character::scoreMult()
{
	score *= 2;
}