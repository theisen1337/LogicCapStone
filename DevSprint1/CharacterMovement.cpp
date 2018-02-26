#include "CharacterMovement.h"

CharacterMovement::CharacterMovement()//DF
{
	characterXPosition = 0;
	characterYPosition = 0;
}

CharacterMovement::CharacterMovement(int xPosition, int yPosition)
{
	characterXPosition = xPosition;
	characterYPosition = yPosition;
}
//moves the character left the specified distance
int CharacterMovement::moveCharacterLeft(int distance)
{
	characterXPosition -= distance;
	return characterXPosition;
}
//moves the character right the specified distance
int CharacterMovement::moveCharacterRight(int distance)
{
	characterXPosition += distance;
	return characterXPosition;
}
//moves the character up the specified distance
int CharacterMovement::moveCharacterUp(int distance)
{
	characterYPosition -= distance;
	return characterYPosition;
}
//moves the character down the specified distance
int CharacterMovement::moveCharacterDown(int distance)
{
	characterYPosition += distance;
	return characterYPosition;
}
//getters and setters for position
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
