#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "World.h"
#include "Chunk.h"
#include "Tile.h"
#pragma once
class Artist
{
private:
		//Tile dimensions
	int tileDim = 64;
		//Chunk dimensions
	int chunkDim = 48;
		//World dimensions
	int worldDim = 3;
		//Bitmap to hold all the tiles drawn to it.
	ALLEGRO_BITMAP *Bitmap;
		//Temp bitmap to hold pictures
	ALLEGRO_BITMAP *pic = NULL;
		/*
		#Maps * #TilesPerMap * 64^2 = #Total Tiles Per World (150994994)
		Number of pixels for world
		*/
	int worldSize = 0;
public:
		//Constructor
	Artist();
		//Create the tile buffer bitmap
	void tileBuffer(ALLEGRO_DISPLAY &dis, World &world);
		//Draw the tile buffer bitmap to the display
	void drawWorld(ALLEGRO_DISPLAY &dis, float scroll_x, float scroll_y, float zoom, float rotate, World world);

	void drawCharacter(ALLEGRO_DISPLAY &dis, float scroll_x, float scroll_y, float zoom, float rotate, World world, ALLEGRO_BITMAP *character, int xPosition, int yPosition);
};


