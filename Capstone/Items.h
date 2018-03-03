#pragma once

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"


class Items
{
public:
	Items();
	Items(std::string name);
	Items(std::string name, std::string category, float value, int width, int height, int stackSize, int x, int y);
	~Items();

	void setPic(std::string path);
	std::string getName();
	std::string getCategory();
	float getValue();
	int getWidth();
	int getHeight();
	int getStackSize();

	float getCoordinateX();
	float getCoordinateY();

	void setDropped(bool boolVar);
	bool checkDropped();

	void pickupItems();
	void placeItems();

	void loadItems();
	void checkItemsDirectory();
	void load_Ores();
	//ALLEGRO_BITMAP * getItems(unsigned int index);

	ALLEGRO_BITMAP * getBitMap();

	void leftClick();
	void rightClick();

	void Draw();

	void setXY(float x, float y); 

private:
	ALLEGRO_BITMAP * ItemsImage;

	std::vector<ALLEGRO_BITMAP*> arrItems;

	std::string ItemsName;
	std::string ItemsCategory;
	float ItemsValue;
	int ItemstackSize;
	bool ItemsDropped;
	int ItemsWidth;
	int ItemsHeight;
	float xCoordinate;
	float yCoordinate;
};