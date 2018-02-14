#ifndef LOGISTICSGAME_H
//#define LOGISTICSGAME_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"

#include "TileMap.h"
#include "Interact.h"
#include "FileIO.h"
#include "Item.h"
#include "ItemLayer.h"
#include "Ore.h"
#include "Tiles.h"

using namespace std;

class LogisticsGame
{
public:
	static LogisticsGame& getInstance();

	// Return Objects for Extraneous Class Use
	static FileIO* getIO();
	static Interact* getInteractions();
	static TileMap* getMap();
	static Items* getItem();
	static Tiles* getTile();

	void run();
};
#endif