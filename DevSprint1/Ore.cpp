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

void Ore::Interact()
{
	//TODO: Implement
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
