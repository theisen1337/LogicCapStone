#include "Tile.h"
#include <vector>
#include "generate.h"
#include "GlobalConstants.h"

#pragma once
class Chunk
{
private:
	//! World X Position
	int worldPosW;

	//! World Y Position
	int worldPosH;

	//! Temp location on atlas for picture drawing
	std::vector<int> tempLoc;

	//! 2D vectors for bottom layer of map
	std::vector<std::vector<Tile>> terrainLayer;

	//! 2D vectors for ore layer of map
	std::vector<std::vector<Tile>> oreLayer;

	//! Bool for if the chunk is currently generated
	bool isGen = false;

	//! Bitmap to hold all the tiles drawn to it.
	ALLEGRO_BITMAP *map;

	//! Generation Object
	Generation gen;
public:
	//! Constructor
	Chunk();

	//! Get tile from bottom layer
	std::vector<std::vector<Tile>> getTiles() { return terrainLayer; };

	std::vector<std::vector<Tile>> getOre() { return oreLayer; };

	//! Set world X position
	void setWorldPosW(int w) { worldPosW = w; };

	//! Set world Y position
	void setWorldPosH(int h) { worldPosH = h; };

	//! Get world X position
	int getWorldPosW() { return worldPosW; };

	//! Get world Y position
	int getWorldPosH() { return worldPosH; };

	//! Check if Chunk is Generated
	bool getGen() { return isGen; };

	//! Toggle the state of the isGen variable
	void toggleGen() { if (isGen) { isGen = false; } else { isGen = true; } };

	//! Generate chunk map
	void genChunkMap(ALLEGRO_BITMAP* atl);

	//! Get map
	ALLEGRO_BITMAP * getMap() { return map; };

	//! Initial Generation of Tiles
	void initalGen();

	//! Generate Chunk Resources
	void genChunk();
};

