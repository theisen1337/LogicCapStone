
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"

#include "World.h"
#include "Interact.h"
#include "FileIO.h"
//#include "Item.h"
//#include "ItemLayer.h"
//#include "Ore.h"
//#include "Tile.h"
#include "Artist.h"

using namespace std;

#pragma once
class StateManager
{
	public:
		//static StateManger getInstance();

		// Return Objects for Extraneous Class Use
		/*FileIO* getIO();
		Interact* getInteractions();
		World* getMap();
		Artist* getArt();*/
		//static Items* getItem();
		//static Tile* getTile();

		void run();
};

