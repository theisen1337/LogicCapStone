#pragma once

#include <string>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

class Ore
{
public:
	Ore();
	Ore(std::string OreType);
	Ore(int OreType);
	~Ore();


private:
	ALLEGRO_BITMAP * OreImage;
};

