#include "Tile.h"
#include <vector>
#pragma once
class Chunk
{
private:
	int tileDimensions = 64;
	int chunkWidth = 64;
	int chunkHeight = 64;
	int spacing = 64;
	int worldPosW;
	int worldPosH;
	std::vector<std::vector<Tile>> topLayer;
	std::vector<std::vector<Tile>> middleLayer;
	std::vector<std::vector<Tile>> bottomLayer;
	bool isGen = false;
public:
	// constructor
	Chunk() {
		bottomLayer.resize(tileDimensions, std::vector<Tile>(tileDimensions,Tile(Tile::GRASS)));
		middleLayer.resize(tileDimensions, std::vector<Tile>(tileDimensions, Tile(Tile::EMPTY)));
		topLayer.resize(tileDimensions, std::vector<Tile>(tileDimensions, Tile(Tile::EMPTY)));
	};
	Tile* getTile(int x, int y) { return &topLayer[x][y]; };
	void setWidth(int w) { chunkWidth = w; };
	void setHeight(int h) { chunkHeight = h; };
	int getWidth() { return chunkWidth; };
	int getHeight() { return chunkHeight; };
	void setDimensions(int d) { tileDimensions = d; };
	void setWorldPosW(int w) { worldPosW = w; };
	void setWorldPosH(int h) { worldPosH = h; };
	int getWorldPosW() { return worldPosW; };
	int getWorldPosH() { return worldPosH; };
	bool getGen() { return isGen; };
	void toggleGen() { if (isGen) { isGen = false; } else { isGen = true; } }
};

