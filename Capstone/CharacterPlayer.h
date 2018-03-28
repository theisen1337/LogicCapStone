#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <string>

class CharacterPlayer
{

public:

	float locationX, locationY;
	int chuckX, chuckY;


	CharacterPlayer();
	~CharacterPlayer();

	std::string getRef() { return charRef; };
	void InitializeClass();

private:
	std::string charRef;
};

