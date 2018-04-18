#include "OreBase.h"


OreBase::OreBase(Type OT, Tile &t, int wX, int wY, int cX, int cY):tileRef(t)
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
	al_show_native_message_box(al_get_current_display(),
		"Character Interaction",
		"Character right clicked on an ore ore",
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void OreBase::Drop()
{
	//TODO: Implement
}

void OreBase::gotHit(int damage)
{
	health -= damage;
	if (health < 0)
	{
		Drop();
	}
}

void OreBase::draw()
{
}

OreBase::~OreBase()
{
}

void OreBase::setTravelSpeed(int speed)
{
	travelSpeed = speed;
}

void OreBase::setHealth(int health)
{
	this->health = health;
}
