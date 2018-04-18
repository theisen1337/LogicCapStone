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
	//OreBase(Type OreType);
	int getHealth();
	int getTravelSpeed();
	virtual void leftClickInteract();
	virtual void rightClickInteract();
	virtual void Drop();
	void gotHit(int damage);
	void draw();
	int getWorldX() { return xWorld;}
	void setWorldX(int x) { xWorld = x; };
	int getWorldY() { return yWorld;}
	void setWorldY(int y) { yWorld = y; };

	int getChunkX() { return xChunk; }
	void setChunkX(int x) { xChunk = x; };
	int getChunkY() { return yChunk; }
	void setChunkY(int y) { yChunk = y; };

	void setTileRef(Tile &tile) { tileRef = tile; };
	Tile &getTileRef() { return tileRef; };
	~OreBase();


private:
	ALLEGRO_BITMAP * OreImage;
	int travelSpeed = 1;
	int health = 1;
	int numberToDrop = 0;
	int xWorld = 0;
	int yWorld = 0;
	int xChunk = 0;
	int yChunk = 0;
	Type oreType;
	Tile & tileRef;

protected:
	void setTravelSpeed(int speed);
	void setHealth(int health);

};