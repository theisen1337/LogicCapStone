#pragma once
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"

#include "main.h"

class Tiles
{
public:
	Tiles();
	~Tiles();

	void loadTiles();
	int getTotal();
	ALLEGRO_BITMAP * getTile(unsigned int index);

	int grassCount = 0;
	int grassOffset = 0;

	int OreCount = 0;
	int OreOffset = 0;



private:
	void load_Terrian();
		void load_Grass();
		void load_Ore();

		

	//std::vector<ALLEGRO_BITMAP*> grassTiles;
	std::vector<ALLEGRO_BITMAP*> arrTiles;
};

