#pragma once

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
//#include "Items.h"
//#include "ItemsLayer.h"
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
		//static Items* getItems();
		//static Tile* getTile();

		void run();
		
		void Computing();
		void Drawing();
		void Interacting();
		void Exiting();


		void MainLoop(); //World &Map, Artist &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font
};

