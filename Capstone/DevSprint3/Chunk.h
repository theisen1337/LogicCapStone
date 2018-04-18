//! Manages 2D vector of Tiles and Image of the Chunk
#include "Tile.h"
#include <vector>
#include "generate.h"
#include "GlobalConstants.h"
#include "NewGen.h"
#include "ObjectManager.h"

#pragma once
class Chunk
{
public:
	//! Constructor
	Chunk();
	int bio;
	//! Return the Tile Layer
	std::vector<std::vector<Tile>>& getTiles() { return terrainLayer; };

	//! Return the Ore Layer
	std::vector<std::vector<Tile>>& getOre() { return oreLayer; };

	//! Set world X position
	void setWorldPosX(int w) { worldPosX = w; };

	//! Set world Y position
	void setWorldPosY(int h) { worldPosY = h; };

	//! Get world X position
	int getWorldPosX() { return worldPosX; };

	//! Get world Y position
	int getWorldPosY() { return worldPosY; };

	//! Check if Chunk is Generated
	bool getGen() { return isGen; };

	//! Toggle the state of the isGen variable
	void toggleGen() { if (isGen) { isGen = false; } else { isGen = true; } };

	//! Generate chunk map
	void genChunkMap(ALLEGRO_BITMAP* atl, std::vector<std::vector<std::string>> &ref);

	//! Get map
	ALLEGRO_BITMAP * getMap() { return map; };

	//! Initial Generation of Tiles
	void initalGen();

	//! Generate Chunk Resources
	void genChunk();

private:
	//! World X Position
	int worldPosX;
	//! World Y Position
	int worldPosY;

	//! Temp location on atlas for picture drawing
	std::string tempLoc;

	//! 2D vectors for terrain layer of map
	std::vector<std::vector<Tile>> terrainLayer;
	//! 2D vectors for ore layer of map
	std::vector<std::vector<Tile>> oreLayer;

	//! Bool for if the chunk is currently generated
	bool isGen = false;

	//! Bitmap to hold all the tiles drawn to it.
	ALLEGRO_BITMAP *map;

	//! Generation Object
	NewGen gen;
};

