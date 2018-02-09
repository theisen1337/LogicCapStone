#pragma once

#include <string>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

class Ore
{
public:
	Ore();
	Ore(std::string OreType);
	Ore(int OreType);
	int getHealth();
	int getTravelSpeed();
	virtual void Interact();
	virtual void Drop();
	void gotHit(int damage);
	~Ore();


private:
	ALLEGRO_BITMAP * OreImage;
	int travelSpeed = 1;
	int health = 1;
	int numberToDrop = 0;
protected:
	void setTravelSpeed(int speed);
	void setHealth(int health);

};