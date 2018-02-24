#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

class CharacterPlayer
{

public:

	float locationX, locationY;
	int chuckX, chuckY;


	CharacterPlayer();
	~CharacterPlayer();

	ALLEGRO_BITMAP * getPic() { return characterPIC; };

private:
	ALLEGRO_BITMAP *characterPIC;

};

