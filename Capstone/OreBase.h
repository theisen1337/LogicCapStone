#pragma once

#include <string>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

class OreBase
{
public:
	OreBase();
	OreBase(std::string OreType);
	OreBase(int OreType);
	int getHealth();
	int getTravelSpeed();
	virtual void leftClickInteract();
	virtual void rightClickInteract();
	virtual void Drop();
	void gotHit(int damage);
	void draw();
	int getXCoordinate() { return xCoordinate; }
	void setXCoordinate(int x);
	int getYCoordinate() { return yCoordinate; }
	void setYCoordinate(int y);
	~OreBase();


private:
	ALLEGRO_BITMAP * OreImage;
	int travelSpeed = 1;
	int health = 1;
	int numberToDrop = 0;
	int xCoordinate = 0;
	int yCoordinate = 0;
protected:
	void setTravelSpeed(int speed);
	void setHealth(int health);

};