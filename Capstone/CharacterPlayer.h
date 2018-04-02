#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <string>

class CharacterPlayer
{

public:

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

