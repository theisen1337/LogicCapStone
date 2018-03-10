#pragma once
#include "MachineLayer.h"
#include "World.h"
#include "Chunk.h"
#include "Tile.h"
#include "CharacterPlayer.h"
#include "TransportLayer.h"
#include "ObjectManager.h"

class MainDraw
{
private:
	//Tile dimensions
	int tileDim = 64;
	//Chunk dimensions
	int chunkDim = 32;
	//World dimensions
	int worldDim = 2;
	//Bitmap to hold all the tiles drawn to it.
	ALLEGRO_BITMAP *Bitmap;
	//Temp bitmap to hold pictures
	ALLEGRO_BITMAP *pic = NULL;
public:
	void Init();
	void Draw(ObjectManager &OM);
	void tileBuffer(ALLEGRO_DISPLAY &dis, World &world);
	void drawWorld(World world);
	void drawCharacter(CharacterPlayer &c, CharacterMovement movement);
};
