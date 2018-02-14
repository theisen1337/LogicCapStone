#include "Ore.h"
#include <string>


Ore::Ore()
{
}

Ore::Ore(std::string oreType)
{

}

Ore::Ore(int OreType)
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

void Ore::LeftClickInteract()
{
}

void Ore::RightClickInteract()
{
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

void Ore::setPositionX(float x)
{
	xPosition = x;
}

float Ore::getPositionX()
{
	return xPosition;
}

void Ore::setPositionY(float y)
{
	yPosition = y;
}


float Ore::getPositionY()
{
	return yPosition;
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
