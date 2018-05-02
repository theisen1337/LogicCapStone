#pragma once

// Allegro Includes
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

// Standard Includes
#include <string>

class CharacterPlayer
{
public:
	//! Image offset for direction 
	int imageoffset = 1;
	//! Animation tickers for animating the character
	float imageAni = 0;
	//! X and Y of Player
	float locationX, locationY;
	//! X and Y Chunk Location
	int chunkX, chunkY;

	//! Constructor
	CharacterPlayer();

	//! Deconstructor
	~CharacterPlayer();

	//! Retrieves Reference to Character
	std::string getRef() { return charRef; };

	//! Initializes Class
	void InitializeClass();

private:

	//! Character Reference
	std::string charRef;
};
