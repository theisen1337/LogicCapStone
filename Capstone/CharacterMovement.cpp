#include "CharacterMovement.h"

// ###############
// # CONSTRUCTOR #
// ###############
CharacterMovement::CharacterMovement()
{
	characterXPosition = 0;
	characterYPosition = 0;
}

// ########################
// # OVERLOADED CHARACTER #
// ########################
CharacterMovement::CharacterMovement(int xPosition, int yPosition)
{
	characterXPosition = xPosition;
	characterYPosition = yPosition;
}

// #####################
// # RETURN X POSITION #
// #####################
int CharacterMovement::getCharacterXPosition()
{
	return characterXPosition;
}
// #####################
// # RETURN Y POSITION #
// #####################
int CharacterMovement::getCharacterYPosition()
{
	return characterYPosition;
}
// ################
// # RETURN SPEED #
// ################
int CharacterMovement::getSpeed()
{
	return speed;
}

// ##################
// # SET X POSITION #
// ##################
void CharacterMovement::setCharacterXPosition(int x)
{
	characterXPosition = x;
}
// ##################
// # SET Y POSITION #
// ##################
void CharacterMovement::setCharacterYPosition(int y)
{
	characterYPosition = y;
}

// ###################
// # MOVE X POSITION #
// ###################
void CharacterMovement::moveCharacterX()
{
	characterXPosition += vx;
}
// ###################
// # MOVE Y POSITION #
// ###################
void CharacterMovement::moveCharacterY()
{
	characterYPosition += vy;
}


