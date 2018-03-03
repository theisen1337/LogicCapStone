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
	void InitializeClass();
	ALLEGRO_BITMAP *characterPIC;
	ALLEGRO_BITMAP * getPic() { return characterPIC; };

private:
	//ALLEGRO_BITMAP *characterPIC = al_load_bitmap("Character//Character.png");

};

