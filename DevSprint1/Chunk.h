#include "Tile.h"
#include <vector>
#pragma once
class Chunk
{
private:
		//Chunk width and heights
	int chunkDim = 32;
		//Tile width and heights
	int tileDim = 64;
		//Position of the chunk in the world vector
	int worldPosW;
	int worldPosH;
		//2D vectors for bottom layer of map
	std::vector<std::vector<Tile>> bottomLayer;
		//Bool for if the chunk is currently generated
	bool isGen = false;
		//Bitmap to hold all the tiles drawn to it.
	ALLEGRO_BITMAP *map;
public:
		//Constructor
	Chunk();
		//Get tile from bottom layer
	std::vector<std::vector<Tile>> getTiles() { return bottomLayer; };
		//Set Width of chunk
	void setChunkDim(int w) { chunkDim = w; };
		//Set Height of chunk
	int getChunkDim() { return chunkDim; };
		//Set world positions 
	void setWorldPosW(int w) { worldPosW = w; };
	void setWorldPosH(int h) { worldPosH = h; };
		//Get world positions
	int getWorldPosW() { return worldPosW; };
	int getWorldPosH() { return worldPosH; };
		//Get isGen boolean
	bool getGen() { return isGen; };
		//Toggle the state of the isGen variable
	void toggleGen() { if (isGen) { isGen = false; } else { isGen = true; } };
		//Generate chunk map
	void genChunkMap();
		//Get map
	ALLEGRO_BITMAP * getMap() { return map; };
		//Initial Generation of Tiles
	void initalGen();

};

