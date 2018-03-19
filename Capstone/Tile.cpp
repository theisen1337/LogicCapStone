#include "Tile.h"

Tile::Tile(Tile::Types tileType)
{	
		//Constructor
	type = tileType;
	atlLoc.resize(2);
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
	switch (type)
	{
	case Tile::GRASS:

		r = rand() % 4 + 1;
		switch (r)
		{
		case 1:
			//pic = al_load_bitmap("Terrain//Grass//grass1.png");
			atlLoc[0] = 0;
			atlLoc[1] = 0;
			break;
		case 2:
			//pic = al_load_bitmap("Terrain//Grass//grass2.png");
			atlLoc[0] = 48;
			atlLoc[1] = 0;
			break;
		case 3:
			//pic = al_load_bitmap("Terrain//Grass//grass3.png");
			atlLoc[0] = 96;
			atlLoc[1] = 0;
			break;
		case 4:
			//pic = al_load_bitmap("Terrain//Grass//grass4.png");
			atlLoc[0] = 144;
			atlLoc[1] = 0;
			break;
		default:
			//pic = al_load_bitmap("Terrain//Grass//grass1.png");
			atlLoc[0] = 0;
			atlLoc[1] = 0;
			break;
		}
		break;

	case Tile::WATER:
		//IF water set pic to water image
		r = rand() % 4 + 1;
		switch (r)
		{
		case 1:
			//pic = al_load_bitmap("Terrain//Water//water1.png");
			atlLoc[0] = 0;
			atlLoc[1] = 96;
			break;
		case 2:
			//pic = al_load_bitmap("Terrain//Water//water2.png");
			atlLoc[0] = 48;
			atlLoc[1] = 96;
			break;
		case 3:
			//pic = al_load_bitmap("Terrain//Water//water3.png");
			atlLoc[0] = 96;
			atlLoc[1] = 96;
			break;
		case 4:
			//pic = al_load_bitmap("Terrain//Water//water4.png");
			atlLoc[0] = 144;
			atlLoc[1] = 96;
			break;
		default:
			//pic = al_load_bitmap("Terrain//Water//water1.png");
			atlLoc[0] = 0;
			atlLoc[1] = 96;
			break;
		}
		break;

	case Tile::DIRT:
		//IF dirt set pic to dirt image
		r = rand() % 4 + 1;
		switch (r)
		{
		case 1:
			//pic = al_load_bitmap("Terrain//Dirt//dirt1.png");
			atlLoc[0] = 0;
			atlLoc[1] = 48;
			break;
		case 2:
			//pic = al_load_bitmap("Terrain//Dirt//dirt2.png");
			atlLoc[0] = 48;
			atlLoc[1] = 48;
			break;
		case 3:
			//pic = al_load_bitmap("Terrain//Dirt//dirt3.png");
			atlLoc[0] = 0;
			atlLoc[1] = 96;
			break;
		case 4:
			//pic = al_load_bitmap("Terrain//Dirt//dirt4.png");
			atlLoc[0] = 0;
			atlLoc[1] = 144;
			break;
		default:
			//pic = al_load_bitmap("Terrain//Dirt//dirt1.png");
			atlLoc[0] = 0;
			atlLoc[1] = 48;
			break;
		}

		break;

	case Tile::COAL:
		//pic = al_load_bitmap("Terrain//Ore//coal.png");
		atlLoc[0] = 48;
		atlLoc[1] = 144;
		break;

	case Tile::IRON:
		//pic = al_load_bitmap("Terrain//Ore//iron.png");
		atlLoc[0] = 0;
		atlLoc[1] = 144;
		break;

	case Tile::TEMP_IRON:
		//pic = al_load_bitmap("Terrain//Ore//iron.png");
		atlLoc[0] = 0;
		atlLoc[1] = 144;
		break;

	case Tile::TEMP_COAL:
		//pic = al_load_bitmap("Terrain//Ore//coal.png");
		atlLoc[0] = 48;
		atlLoc[1] = 144;
		break;

	case Tile::EMPTY:
		//pic = al_load_bitmap("Terrain//Empty//empty.png");
		atlLoc[0] = 144;
		atlLoc[1] = 144;
		break;
	default:
		break;
	}

	loaded = true;
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