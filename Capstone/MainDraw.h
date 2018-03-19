//! MainDraw Class
/*!
Manages all the drawing to the screen
*/

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "MachineLayer.h"
#include "World.h"
#include "Chunk.h"
#include "Tile.h"
#include "CharacterPlayer.h"
#include "TransportLayer.h"
#include "ObjectManager.h"
#include "CharacterMovement.h"
#include "GlobalConstants.h"
#include "ImageAtlas.h"

class MainDraw
{
private:
	//! Object to handle all the Image Atlasing
	ImageAtlas ia;

	//! Main atlas for all image atlases
	ALLEGRO_BITMAP *atlas;
public:
	//! Initialization of Drawing
	void Init();

	//! Draw the Machine and Item Layer
	void Draw(ObjectManager &OM);

	//! Draw the World and Ore Layers
	void drawWorld(World &world, ALLEGRO_DISPLAY &dis);

	//! Draw the Character Layer
	void drawCharacter(CharacterPlayer &c, CharacterMovement movement);
};
