#pragma once

#include <string>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

class Ore
{
public:
	Ore();
	Ore(std::string OreType);
	Ore(int OreType);
	int getHealth();
	int getTravelSpeed();
	virtual void LeftClickInteract();
	virtual void RightClickInteract();
	virtual void Drop();
	void gotHit(int damage);
	void setPositionX(float x);
	float getPositionX();
	void setPositionY(float y);
	float getPositionY();
	~Ore();


private:
	ALLEGRO_BITMAP * OreImage;
	int travelSpeed = 1;
	int health = 1;
	int numberToDrop = 0;
	float xPosition = 0.0f;
	float yPosition = 0.0f;
protected:
	void setTravelSpeed(int speed);
	void setHealth(int health);

};