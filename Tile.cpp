#include "Tile.h"

Tile::Tile(Tile::Types tileType)
{	
		//Constructor
	type = tileType;
	genPicture();
}

void Tile::setType(Tile::Types tileType)
{
		//Set the tile type and generate new picture
	type = tileType;
	genPicture();
}

void Tile::genPicture()
{	
		//Switch statement for setting picture of the tile
	std::string path;
	switch (type)
	{
	case Tile::GRASS:
		//IF Grass set pic to grass image
		path = "Images\\Tiles\\grass.png";
		pic = al_load_bitmap(path.c_str());
		break;
	case Tile::WATER:
		//IF water set pic to water image

		break;
	case Tile::EMPTY:


		break;
	default:
		break;
	}
}

/*TO DO'S
-refrences to image file dependant on type
	:randomly select out of a selection of grass.png that look
	 slightly different to allow more variety to the look of the
	 map.

-Tile positioning
	:Data information to hold the tiles position. This information
	 is like what layer and coords on the layer. (may not need)

*/