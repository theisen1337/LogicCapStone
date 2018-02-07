#include "Tile.h"
#include <vector>
#pragma once
class Chunk
{
private:
		//Chunk width and heights
	int chunkWidth = 64;
	int chunkHeight = 64;
		//Position of the chunk in the world vector
	int worldPosW;
	int worldPosH;
		//2D vectors for bottom layer of map
	std::vector<std::vector<Tile>> bottomLayer;
		//Bool for if the chunk is currently generated
	bool isGen = false;
public:
		//Constructor
	Chunk() {
		bottomLayer.resize(chunkWidth, std::vector<Tile>(chunkHeight,Tile(Tile::GRASS)));
	};
		//Get tile from bottom layer
	std::vector<std::vector<Tile>> getTiles() { return bottomLayer; };
		//Set Width of chunk
	void setWidth(int w) { chunkWidth = w; };
		//Set Height of chunk
	void setHeight(int h) { chunkHeight = h; };
		//Get Width of chunk
	int getWidth() { return chunkWidth; };
		//Get Height of chunk
	int getHeight() { return chunkHeight; };
		//Set world positions 
	void setWorldPosW(int w) { worldPosW = w; };
	void setWorldPosH(int h) { worldPosH = h; };
		//Get world positions
	int getWorldPosW() { return worldPosW; };
	int getWorldPosH() { return worldPosH; };
		//Get isGen boolean
	bool getGen() { return isGen; };
		//Toggle the state of the isGen variable
	void toggleGen() { if (isGen) { isGen = false; } else { isGen = true; } }
};

