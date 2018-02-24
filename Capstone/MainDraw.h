#pragma once
#include "MachineLayer.h"
#include "World.h"
#include "Chunk.h"
#include "Tile.h"
#include "CharacterPlayer.h"

class MainDraw
{
private:
	//Tile dimensions
	int tileDim = 64;
	//Chunk dimensions
	int chunkDim = 32;
	//World dimensions
	int worldDim = 3;
	//Bitmap to hold all the tiles drawn to it.
	ALLEGRO_BITMAP *Bitmap;
	//Temp bitmap to hold pictures
	ALLEGRO_BITMAP *pic = NULL;
public:
	void Draw(MachineLayer & ML);
	void tileBuffer(ALLEGRO_DISPLAY &dis, World &world);
	void drawWorld(ALLEGRO_DISPLAY &dis, float scroll_x, float scroll_y, float zoom, float rotate, World world);
	void drawCharacter(ALLEGRO_DISPLAY &dis, float scroll_x, float scroll_y, float zoom, float rotate, World world, CharacterPlayer &c, int xPosition, int yPosition);
};