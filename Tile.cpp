#include "Tile.h"

Tile::Tile(Tile::Types tileType)
{	
		//Constructor
	type = tileType;
	atlLoc.resize(2);
	loaded = false;
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
	
			atLoc = "grass1.png";
			break;
		case 2:
			atLoc = "grass2.png";
			break;
		case 3:
			atLoc = "grass3.png";
			break;
		case 4:
			atLoc = "grass4.png";
			break;
		default:
			atLoc = "grass1.png";
			break;
		}
		break;

	case Tile::WATER:
		//IF water set pic to water image
		r = rand() % 4 + 1;
		switch (r)
		{
		case 1:
			atLoc = "water1.png";
			break;
		case 2:
			atLoc = "water2.png";
			break;
		case 3:
			atLoc = "water3.png";
			break;
		case 4:
			atLoc = "water4.png";
			break;
		default:
			atLoc = "water1.png";
			break;
		}
		break;

	case Tile::DIRT:
		//IF dirt set pic to dirt image
		r = rand() % 4 + 1;
		switch (r)
		{
		case 1:
			atLoc = "dirt1.png";
			break;
		case 2:
			atLoc = "dirt2.png";
			break;
		case 3:
			atLoc = "dirt3.png";
			break;
		case 4:
			atLoc = "dirt4.png";
			break;
		default:
			atLoc = "dirt1.png";
			break;
		}

		break;

	case Tile::COAL:
		atLoc = "coal.png";
		break;

	case Tile::IRON:
		atLoc = "iron.png";
		break;

	case Tile::TEMP_IRON:
		atLoc = "iron.png";
		break;

	case Tile::TEMP_COAL:
		atLoc = "coal.png";
		break;

	case Tile::SAND: //added by brandon
		//IF dirt set pic to dirt image
		r = rand() % 4 + 1;
		switch (r)
		{
		case 1:
			atLoc = "sand1.png";
			break;
		case 2:
			atLoc = "sand2.png";
			break;
		case 3:
			atLoc = "sand3.png";
			break;
		case 4:
			atLoc = "sand4.png";
			break;
		default:
			atLoc = "sand5.png";
			break;
		}
	case Tile::QUICK: //added by brandon
		//IF dirt set pic to dirt image
		r = rand() % 4 + 1;
		switch (r)
		{
		case 1:
			atLoc = "qSand1.png";
			break;
		case 2:
			atLoc = "qSand2.png";
			break;
		case 3:
			atLoc = "qSand3.png";
			break;
		case 4:
			atLoc = "qSand4.png";
			break;
		default:
			atLoc = "qSand5.png";
			break;
		}

	case Tile::TEMP_QUICK: //addded by brandon
		atLoc = "qSand1.png";
		break;

	case Tile::SNOW:
		r = rand() % 3 + 1;
		switch (r)
		{
			case 1:
				atLoc = "snow1.png";
				break;
			case 2:
				atLoc = "snow2.png";
				break;
			case 3:
				atLoc = "snow3.png";
				break;
		}

	case Tile::ICE: //added by brandon
		atLoc = "ICE.png";
		break;

	case Tile::EMPTY:
		atLoc = "empty.png";
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