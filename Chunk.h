//! Manages 2D vector of Tiles and Image of the Chunk
#include "Tile.h"
#include <vector>
#include <ctime>
#include "NewGen.h"
#include "GlobalConstants.h"

#pragma once
class Chunk
{
public:
	//! Constructor
	Chunk();

	//! Return the Tile Layer
	std::vector<std::vector<Tile>> & getTiles() { return terrainLayer; };

	//! Return the Ore Layer
	std::vector<std::vector<Tile>> & getOre() { return oreLayer; };

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
	void genChunkMap(ALLEGRO_BITMAP* atl, std::vector<std::vector<std::string>> &ref);

	//! Get map
	ALLEGRO_BITMAP * getMap() { return map; };

	//! Initial Generation of Tiles
	void initalGen();

	//! Generate Chunk Resources
	//void Chunk::genChunk() //void Chunk::genChunk(vector < vector <int> > biome) 
	void genChunk(int bio);


private:
	//! used as a bio stat
	//int bio = 0;
	int h, w;

	//! used as placeholder for biome stats
	//vector < vector <int> > biome1;

	//! World X Position
	int worldPosW;
	//! World Y Position
	int worldPosH;

	//! Biome stat
	int temp = 0; //added by Brandon

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

