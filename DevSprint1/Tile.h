#pragma once
#include <allegro5/allegro.h>
#include <string>
#include <stdlib.h>
#include <iostream>

class Tile
{
public:
	//! Types Enum
	/*!
		The different Types of tiles possible.
	*/
	enum Types
	{
		GRASS, /*! Grass tile*/
		WATER,/*! Water tile*/
		DIRT,/*! Dirt tile*/
		COAL,/*! Coal ore tile*/
		IRON,/*! Iron ore tile*/ 
		TEMP_COAL,/*! Temp coal, Used in Generation*/
		TEMP_IRON,/*! Temp iron, Used in Generation*/
		TEMP_WATER,/*! Temp water, Used in Generation*/
		EMPTY/*! Empty tile*/
	};
	//! Loaded Tile Boolean
	/*!
		Allows to check if a tile is currently loaded.
	*/
	bool loaded;

	//! Image of the tile
	ALLEGRO_BITMAP *pic;


	//! Type of the tile
	Types type;

	//! Constructor for Tile
	Tile(Tile::Types tileType);

	//! Getter for tile type
	Tile::Types getType() { return type; };
	
	//! Setter for tile type
	void setType(Tile::Types tileType);

	//! Generate tile picture
	/*!
		Generates the random tile image depending on the type
	*/
	void genPicture();
		
	//! Getter for the tile image
	ALLEGRO_BITMAP * getTilePic() { return pic; };
		
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
 };

