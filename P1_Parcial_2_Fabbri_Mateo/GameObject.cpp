#include "GameObject.h"

GameObject::GameObject()
{
	pos = { 5, 5 };
	boxCollider = { 3, 3 };
}

GameObject::~GameObject()
{
}

void GameObject::draw()
{
	erase();
	Vector2 cursor = { pos.x - boxCollider.x / 2, pos.y - boxCollider.y / 2 };

	for (int i = 0; i < boxCollider.y; i++)
	{
		goToCoordinates(cursor);

		for (int j = 0; j < boxCollider.x; j++)
		{
			std::cout << mesh[3 * i + j];
		}

		cursor.y++;
	}
}

void GameObject::erase()
{
	Vector2 cursor = { exPos.x - boxCollider.x / 2, exPos.y - boxCollider.y / 2 };

	for (int i = 0; i < boxCollider.y; i++)
	{
		goToCoordinates(cursor);

		for (int j = 0; j < boxCollider.x; j++)
		{
			std::cout << " ";
		}

		cursor.y++;
	}
}

void GameObject::collideEffect()
{
	pos = exPos;
}

bool GameObject::checkCollision(Vector2 pos, Vector2 boxCollider)
{
}