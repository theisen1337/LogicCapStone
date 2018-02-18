#pragma once
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Tile.h"
//#######################################
//Added/Changes By Dustin
//#######################################
/*
	*Changed 3D vector into two 2D vectors
		Chunks use two 2D vectors so makes it simpler to change here
		Any refrence to ores[i][j][0] was changed to tiles[i][j]
		Any refrence to ores[i][j][1] was changed to ores[i][j]
	*Changed tile and ore array to an array of types.
		This removed a middle step of having to translate a string into a type to change a tile
	*Commented out all debug outputs 
		May be outdated as can see the map visually now.
	*Changed for loops constraints such as tiles.size() to chunkSize
		The size of a chunk will be set in stone
	*Changed If statments comparing strings to comparing types
		Since arrays are no longer strings they need to compare types
	*Changed situations such as 'ores[i - a][j][1] = "i";' to change to temp types
		Unsure what the lowercase is ment to be in final version
		Set it so they are changing type to a Temp_i or Temp_c
		If this was just for visual debugging in the table then just change the Temp_c and Temp_i to Ore_COAL and ORE_IRON
	*Replaced aLen to be a private variable
		Kinda unsure what aLen was, from what i kinda understood was that it was always 1 if chunks were always squares.
		Have it setting to size of tile[] and ore[] at begining of setTiles and setOres methods.
	*Commented out your main()
		Shouldn't be needed anymore
*/
//#######################################
class Generation
{
private:
	int aLen;
	int chunkSize = 32;
		//2D vectors for bottom layer of map
	std::vector<std::vector<Tile>> terrainLayer;
		//the five current possibilities for the Tile vector (will be changed in the future
	Tile::Types tile[13] = { Tile::GRASS, Tile::GRASS, Tile::GRASS, Tile::GRASS, Tile::GRASS, Tile::GRASS, Tile::GRASS, Tile::GRASS, Tile::GRASS, Tile::DIRT, Tile::DIRT, Tile::DIRT, Tile::WATER };
	Tile::Types ore[12] = { Tile::EMPTY, Tile::EMPTY, Tile::EMPTY, Tile::EMPTY, Tile::EMPTY, Tile::EMPTY, Tile::EMPTY, Tile::EMPTY, Tile::EMPTY, Tile::ORE_COAL, Tile::ORE_COAL, Tile::ORE_IRON };
public:
	Generation();
	std::vector<std::vector<Tile>> setTiles(std::vector<std::vector<Tile>> &tiles);
	std::vector<std::vector<Tile>> setOres(std::vector<std::vector<Tile>> &ores, std::vector<std::vector<Tile>> &tiles);
		//Gets the terrain changes from setOres.
	std::vector<std::vector<Tile>> getTerrain() { return terrainLayer; };

};

