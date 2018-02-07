#pragma once
#include <allegro5/allegro.h>
#include <string>

class Tile
{
public:
		//Enum for the types of Tiles
	enum Types
	{
		GRASS,
		WATER,
		EMPTY
	};
		//Check if tile is loaded
	bool loaded;
		//Image of the tile
	ALLEGRO_BITMAP *pic;
		//Type of the tile
	Types type;
		//Constructor
	Tile(Tile::Types tileType);
		//Return Type of tile
	Tile::Types getType() { return type; };
		//Set the type of the Tile
	void setType(Tile::Types tileType);
		//Generate picture depending on type of the tile
	void genPicture();
		//Get the tile pic
	ALLEGRO_BITMAP * getTilePic() { return pic; };
		//Get loaded
	bool getLoaded() { return loaded; };
};

