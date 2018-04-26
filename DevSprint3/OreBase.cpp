#include "OreBase.h"

OreBase::OreBase(Type OT, Tile &t, int wX, int wY, int cX, int cY) :tileRef(t)
{
	oreType = OT;
	xWorld = wX;
	yWorld = wY;
	xChunk = cX;
	yChunk = cY;

}
int OreBase::getHealth()
{
	return health;
}

int OreBase::getTravelSpeed()
{
	return travelSpeed;
}

void OreBase::leftClickInteract()
{
	al_show_native_message_box(al_get_current_display(),
		"Character Interaction",
		"Character left clicked on an ore",
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void OreBase::rightClickInteract()
{
	health--;
	if (health = 0)
	{
		tileRef.setType(Tile::EMPTY);


	}
}

void OreBase::Drop()
{
	//TODO: Implement
}

void OreBase::gotHit(int damage)
{
	
}

void OreBase::draw()
{
}

int OreBase::getLocX()
{
	int loc;
	loc = (xWorld * GC::chunkDim * GC::tileDim) + (xChunk * GC::tileDim);
	return loc;
}

int OreBase::getLocY()
{
	int loc;
	loc = (yWorld * GC::chunkDim * GC::tileDim) + (yChunk * GC::tileDim);
	return loc;
}

OreBase::~OreBase()
{
}

void OreBase::setTravelSpeed(int speed)
{
	
}

void OreBase::setHealth(int health)
{
	
}

std::string OreBase::getName()
{
	std::string name;
	switch (oreType)
	{
	case OreBase::Iron:
		name = "Iron";
		break;
	case OreBase::Coal:
		name = "Coal";
		break;
	default:
		break;
	}

	return name;
}