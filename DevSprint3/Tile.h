//! Manages Tile information and Tile interaction with chunks
#pragma once
#include <allegro5/allegro.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "GlobalConstants.h"

class Tile
{
public:
	//! Types Enum
	/*!
		The different Types of tiles possible.
	*/
	enum Types
	{
		GRASS,/*! Grass tile*/
		WATER,/*! Water tile*/
		DIRT,/*! Dirt tile*/
		COAL,/*! Coal ore tile*/
		IRON,/*! Iron ore tile*/ 
		TEMP_COAL,/*! Temp coal, Used in Generation*/
		TEMP_IRON,/*! Temp iron, Used in Generation*/
		TEMP_WATER,/*! Temp water, Used in Generation*/
		SAND,
		QUICK, //added by brandon
		TEMP_QUICK, //added by brandon
		SNOW, // added by brandon
		ICE, // added by brandon
		TEMP_ICE, // added by brandon
		DEPORE,
		EMPTY/*! Empty tile*/
	};
	//! Loaded Tile Boolean
	/*!
		Allows to check if a tile is currently loaded.
	*/
	bool loaded;

	//! Vector to hold location of image on atlas
	std::vector<int> atlLoc;

	//! Atlas Location
	std::string atLoc;

	//! Type of the tile
	Types type;

	//! Constructor for Tile
	Tile(Tile::Types tileType);

	//! Getter for tile type
	Tile::Types & getType() { return type; };
	
	//! Setter for tile type
	void setType(Tile::Types tileType);

	//! Generate tile picture
	/*!
		Generates the random tile image depending on the type
	*/
	void genPicture();
		
	//! Getter for the tile image
	std::vector<int> getTilePic() { return atlLoc; };
		
	//! Getter to check if tile is Loaded
	bool getLoaded() { return loaded; };
		
	//! Random Variable
	int r;

	//! Chunk X Location
	int chunkX;

	//! Chunk Y Location
	int chunkY;

	//! Get Chunk X Location
	int getChunkX() { return chunkX; };

	//! Get Chunk Y Location
	int getChunkY() { return chunkY; };

	//! Set Chunk X Location
	void setChunkX(int x) { chunkX = x; };

	//! Set Chunk Y Location
	void setChunkY(int y) { chunkY = y; };

	//! Get the atlas Location
	std::string getAtLoc() { return atLoc; };
 };

