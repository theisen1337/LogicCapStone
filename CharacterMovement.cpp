#include "CharacterMovement.h"

CharacterMovement::CharacterMovement(int xPosition, int yPosition)
{
	characterXPosition = xPosition;
	characterYPosition = yPosition;
}

int CharacterMovement::moveCharacterLeft(int distance)
{
	characterXPosition -= distance;
	return characterXPosition;
}

int CharacterMovement::moveCharacterRight(int distance)
{
	characterXPosition += distance;
	return characterXPosition;
}

int CharacterMovement::moveCharacterUp(int distance)
{
	characterYPosition -= distance;
	return characterYPosition;
}

int CharacterMovement::moveCharacterDown(int distance)
{
	characterYPosition += distance;
	return characterYPosition;
}

int CharacterMovement::getCharacterXPosition()
{
	return characterXPosition;
}

void CharacterMovement::setCharacterXPosition(int x)
{
	characterXPosition = x;
}

int CharacterMovement::getCharacterYPosition()
{
	return characterYPosition;
}

void CharacterMovement::setCharacterYPosition(int y)
{
	characterYPosition = y;
}
