#include "Ore.h"
#include <string>


Ore::Ore()
{
}

Ore::Ore(std::string oreType)
{

}

int Ore::getHealth()
{
	return health;
}

int Ore::getTravelSpeed()
{
	return travelSpeed;
}

void Ore::leftClick()
{
	al_show_native_message_box(al_get_current_display(),
		"Character Interaction",
		"Character left clicked on an ore",
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void Ore::rightClick()
{
	al_show_native_message_box(al_get_current_display(),
		"Character Interaction",
		"Character right clicked on an ore ore",
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void Ore::Drop()
{
	//TODO: Implement
}

void Ore::gotHit(int damage)
{
	health -= damage;
	if (health < 0)
	{
		Drop();
	}
}

void Ore::draw()
{
}

void Ore::setXCoordinate(int x)
{
	xCoordinate = x;
}

void Ore::setYCoordinate(int y)
{
	yCoordinate = y;
}

Ore::~Ore()
{
}

void Ore::setTravelSpeed(int speed)
{
	travelSpeed = speed;
}

void Ore::setHealth(int health)
{
	this->health = health;
}
