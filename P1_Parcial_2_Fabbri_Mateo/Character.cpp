#include "Character.h"

Character::Character(Vector2 pos)
{
	exPos = pos;
	this->pos = pos;
	boxCollider = { 3, 3 };
	mesh = " 0 /|\\/ \\";
	std::cout << "CreatedCharacter\n";
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

	if (key == 'w')
		pos.y--;

	if (key == 's')
		pos.y++;

	if (key == 'a')
		pos.x--;

	if (key == 'd')
		pos.x++;
}

bool Character::checkCollision(Vector2 pos, Vector2 boxCollider)
{
	Vector2 a1 = { this->pos.x - this->boxCollider.x / 2,
					this->pos.y - this->boxCollider.y / 2 };

	Vector2 a2 = { this->pos.x + this->boxCollider.x / 2,
					this->pos.y + this->boxCollider.y / 2 };

	Vector2 b1 = { pos.x - boxCollider.x / 2,
					pos.y - boxCollider.y / 2 };

	Vector2 b2 = { pos.x + boxCollider.x / 2,
					pos.y + boxCollider.y / 2 };

	return (a2.x < b1.x || a1.x > b2.x || a2.y < b1.y || a1.y > b2.y);
}