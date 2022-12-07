#include "Character.h"

Character::Character(Vector2 pos)
{
	maxLives = 3;
	lives = 3;
	score = 0;
	exPos = pos;
	this->pos = pos;
	boxCollider = { 3, 3 };
	mesh = " 0 /|\\/ \\";
	std::cout << "Created Character\n";
	color = Color::CYAN;
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
		pos.y--;

	if (key == 's')
		pos.y++;

	if (key == 'a')
		pos.x--;

	if (key == 'd')
		pos.x++;
}

void Character::drawLives()
{
	goToCoordinates({ 1, 1 });
	std::cout << lives << " : " << score;
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

void Character::lifeUp()
{
	if (lives + 1 <= maxLives)
		lives++;
}

void Character::scoreUp()
{
	score++;
}