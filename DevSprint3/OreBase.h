#pragma once

#include <string>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

#include "Tile.h"

class OreBase
{
public:
	enum Type {
		Iron,
		Coal
	};
	//OreBase();
	OreBase(OreBase::Type OT, Tile &t, int wX, int wY, int cX, int cY);
	//OreBase(int OreType);
	int getHealth();
	int getTravelSpeed();
	virtual void leftClickInteract();
	virtual void rightClickInteract();
	virtual void Drop();
	void gotHit(int damage);
	void draw();
	int getWorldX() { return xWorld; }
	void setWorldX(int x) { xWorld = x; };
	int getWorldY() { return yWorld; }
	void setWorldY(int y) { yWorld = y; };

	int getChunkX() { return xChunk; }
	void setChunkX(int x) { xChunk = x; };
	int getChunkY() { return yChunk; }
	void setChunkY(int y) { yChunk = y; };

	int getLocX();
	int getLocY();

	void setTileRef(Tile &tile) { tileRef = tile; };
	Tile &getTileRef() { return tileRef; };
	~OreBase();

	std::string getName();
	bool getStatus() { return status; };
	void setStatus(bool b) { status = b; };

private:
	ALLEGRO_BITMAP * OreImage;
	int travelSpeed = 1;
	int health = 5;
	int numberToDrop = 0;
	int xCoordinate = 0;
	int yCoordinate = 0;
	int xWorld = 0;
	int yWorld = 0;
	int xChunk = 0;
	int yChunk = 0;
	Type oreType;
	Tile & tileRef;
	bool status;
protected:
	void setTravelSpeed(int speed);
	void setHealth(int health);

};