#pragma once

// Standard Includes
#include <vector>
#include <math.h>

// Custom Includes
#include "GlobalStatics.h"
#include "World.h"
#include "Tile.h"

//! Directional Structure
struct Compass {
bool N;
bool E;
bool S;
bool W;
};

class CharacterMovement
{
public:

	//! Default Constructor
	CharacterMovement();
	//! Constructor with starting position parameters
	CharacterMovement(int xPosition, int yPosition);

	//! Get the x position of the character
	int & getCharacterXPosition();
	//! Set the x position of the character
	void setCharacterXPosition(int x);

	//! Get the y position of the character
	int & getCharacterYPosition();
	//! Set the y position of the character
	void setCharacterYPosition(int y);

	//! velocity in y direction
	int vy = 0;
	//! velocity in x direction
	int vx = 0;

	//! move the character horizontally
	void moveCharacterX();
	//! move the character vertically
	void moveCharacterY();

	//! get the speed of the character
	int getSpeed();
	
	//!direction of player;
	Compass CharCompass;

private:
	
	//! y position for the character
	int characterYPosition = 0;
	//! x position for the character
	int characterXPosition = 0;
	//! speed for how fast the character will move
	int speed = 5;
};