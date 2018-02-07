#pragma once

#include <string>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

class Item
{
public:
	Item();
	Item(std::string name, std::string category, float value, int width, int height, int stackSize);
	~Item();

	std::string getName();
	std::string getCategory();
	float getValue();
	int getWidth();
	int getHeight();
	int getStackSize();

	void setDropped();
	bool checkDropped();

	void pickupItem();

private:
	ALLEGRO_BITMAP * ItemImage;

	std::string itemName;
	std::string itemCategory;
	float itemValue;
	int itemStackSize;
	bool itemDropped;
	int itemWidth;
	int itemHeight;
};