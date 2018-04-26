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
	loaded = true;
}

void Tile::genPicture()
{	
		//Switch statement for setting picture of the tile
	switch (type)
	{
	case Tile::GRASS:

		r = rand() % 4 + 1;
		switch (r)
		{
		case 1:
			pic = al_load_bitmap("Terrain//Grass//grass1.png");
			break;
		case 2:
			pic = al_load_bitmap("Terrain//Grass//grass2.png");
			break;
		case 3:
			pic = al_load_bitmap("Terrain//Grass//grass3.png");
			break;
		case 4:
			pic = al_load_bitmap("Terrain//Grass//grass4.png");
			break;
		default:
			pic = al_load_bitmap("Terrain//Grass//grass1.png");
			break;
		}
		break;

	case Tile::WATER:
		//IF water set pic to water image
		r = rand() % 4 + 1;
		switch (r)
		{
		case 1:
			pic = al_load_bitmap("Terrain//Water//water1.png");
			break;
		case 2:
			pic = al_load_bitmap("Terrain//Water//water2.png");
			break;
		case 3:
			pic = al_load_bitmap("Terrain//Water//water3.png");
			break;
		case 4:
			pic = al_load_bitmap("Terrain//Water//water4.png");
			break;
		default:
			pic = al_load_bitmap("Terrain//Water//water1.png");
			break;
		}
		break;

	case Tile::DIRT:
		//IF dirt set pic to dirt image
		r = rand() % 4 + 1;
		switch (r)
		{
		case 1:
			pic = al_load_bitmap("Terrain//Dirt//dirt1.png");
			break;
		case 2:
			pic = al_load_bitmap("Terrain//Dirt//dirt2.png");
			break;
		case 3:
			pic = al_load_bitmap("Terrain//Dirt//dirt3.png");
			break;
		case 4:
			pic = al_load_bitmap("Terrain//Dirt//dirt4.png");
			break;
		default:
			pic = al_load_bitmap("Terrain//Dirt//dirt1.png");
			break;
		}
		
		break;

	case Tile::COAL:
		pic = al_load_bitmap("Terrain//Ore//coal.png");

		break;

	case Tile::IRON:
		pic = al_load_bitmap("Terrain//Ore//iron.png");

		break;

	case Tile::TEMP_IRON:
		pic = al_load_bitmap("Terrain//Ore//iron.png");

		break;

	case Tile::TEMP_COAL:
		pic = al_load_bitmap("Terrain//Ore//coal.png");

		break;

	case Tile::EMPTY:
		pic = al_load_bitmap("Terrain//Empty//empty.png");

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