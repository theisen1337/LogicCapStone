#pragma once
#include <allegro5/allegro.h>

class Tile
{
public:
	enum Types
	{
		GRASS,
		WATER,
		EMPTY
	};
	ALLEGRO_BITMAP *pic;
	Types type;
	Tile(Tile::Types tileType);
	Tile::Types getType() { return type; };
	void genPicture();
};

