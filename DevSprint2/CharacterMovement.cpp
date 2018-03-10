#include "CharacterMovement.h"

//! default constructor
CharacterMovement::CharacterMovement()
{
	characterXPosition = 0;
	characterYPosition = 0;
}
//! constructor that takes a starting position as parameters
CharacterMovement::CharacterMovement(int xPosition, int yPosition)
{
	characterXPosition = xPosition;
	characterYPosition = yPosition;
}
//! get the x position of the character
int CharacterMovement::getCharacterXPosition()
{
	return characterXPosition;
}
//! set the x position of the character
void CharacterMovement::setCharacterXPosition(int x)
{
	characterXPosition = x;
}
//! get the y position of the character
int CharacterMovement::getCharacterYPosition()
{
	return characterYPosition;
}
//! set the y position of the character
void CharacterMovement::setCharacterYPosition(int y)
{
	characterYPosition = y;
}
//! move the character in the x position
void CharacterMovement::moveCharacterX()
{
	characterXPosition += vx;
}
//! move the character in the y position
void CharacterMovement::moveCharacterY()
{
	characterYPosition += vy;
}
//! get the speed of the character
int CharacterMovement::getSpeed()
{
	return speed;
}
