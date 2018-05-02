#pragma once

// Allegro Includes
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"

// Standard Includes
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

class ItemBase
{
public:

	//! Constructor
	ItemBase();
	//! Overloaded Constructors
	ItemBase(std::string name);
	ItemBase(std::string name, std::string category, float value, int width, int height, int stackSize, int x, int y);
	//! Deconstructor
	~ItemBase();

	//! Sets the Item Image
	void setPic(std::string path);

	//! Gets Name of Item
	std::string getName();
	//! Gets the Item's Category
	std::string getCategory();
	//! Gets the Item's Value
	float getValue();
	//! Get Item Width
	int getWidth();
	//! Get Item Height
	int getHeight();
	//! Get Item Stacksize
	int getStackSize();

	//! Get X and Y Coordinate
	float getCoordinateX();
	float getCoordinateY();

	//! Set's the Items Name
	void setName(std::string name);

	//! Sets and Detects Dropped Items
	void setDropped(bool boolVar);
	bool checkDropped();

	//! Functions for Picking Up and Placing Items
	void pickupItems();
	void placeItems();

	//! Load Items
	void loadItems();
	//! Check for Directory Existance
	void checkItemsDirectory();
	//! Loads Ores
	void load_Ores();

	//! Retrieves Item Bitmap
	ALLEGRO_BITMAP * getBitMap();

	//! Activates left and right click functionality
	void leftClick();
	void rightClick();

	//! Draws the Item
	void Draw();

	//! Sets the X and Y Positions
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