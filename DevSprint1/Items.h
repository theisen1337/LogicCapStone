#pragma once

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"

//#include "main.h"


class Items
{
public:
	Items();
	Items(std::string name, std::string category, float value, int width, int height, int stackSize);
	~Items();

	std::string getName();
	std::string getCategory();
	float getValue();
	int getWidth();
	int getHeight();
	int getStackSize();

	void setDropped();
	bool checkDropped();

	void pickupItems();
	void placeItems();

	void loadItems();
	void checkItemsDirectory();
	void load_Ores();
	//ALLEGRO_BITMAP * getItems(unsigned int index);

	ALLEGRO_BITMAP * getBitMap();


private:
	ALLEGRO_BITMAP * ItemsImage;

	//std::vector<ALLEGRO_BITMAP*> grassTiles;
	std::vector<ALLEGRO_BITMAP*> arrItems;

	std::string ItemsName;
	std::string ItemsCategory;
	float ItemsValue;
	int ItemstackSize;
	bool ItemsDropped;
	int ItemsWidth;
	int ItemsHeight;
};