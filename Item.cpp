#include "Item.h"

FileIO IO = *(LogisticsGame::getIO());

// Constructor
Items::Items() 
{
	loadItems();
}

// Overloaded Constructor
Items::Items(std::string name, std::string category, float value, int width, int height, int stackSize)
{
	itemName = name;
	itemCategory = category;
	itemValue = value;
	itemDropped = true;
	itemWidth = width;
	itemHeight = height;
	itemStackSize = stackSize;
}

// Deconstructor
Items::~Items() {}

// Getters which Get Values of Object
std::string Items::getName()
{
	return itemName;
}
std::string Items::getCategory()
{
	return itemCategory;
}
float Items::getValue()
{
	return itemValue;
}
int Items::getWidth()
{
	return itemWidth;
}
int Items::getHeight()
{
	return itemHeight;
}
int Items::getStackSize()
{
	return itemStackSize;
}

// Setters to Change Values of Object
void Items::setDropped()
{
	if (itemDropped == true)
	{
		itemDropped = false;
	}
	if (itemDropped == false)
	{
		itemDropped = true;
	}
}

// Checks to see if item is dropped or not
bool Items::checkDropped()
{
	return itemDropped;
}

// This is called from Interactions Class when item is left Clicked
void Items::pickupItem()
{
	// To Do
}

// This is called from Interactions Class when tile is right clicked with item
void Items::placeItem()
{
	// To Do
}



void Items::loadItems()
{
	checkItemDirectory();
	load_Ores();
	//load_Armor();
	//load_Weapons(); ...
}

void Items::checkItemDirectory()
{
	if (!IO.DirectoryExist("Items"))
	{
		IO.CreateDir("Items");
	}
}

void Items::load_Ores()
{
	if (!IO.DirectoryExist("Items\\Ores"))
	{
		IO.CreateDir("Items\\Ores");
	}

	std::string test[] = { "ITEM_COAL.png" };

	for (int i = 0; i < test->length(); i++)
	{
		std::string file = "Items\\Ores\\" + test[i];
		ALLEGRO_BITMAP *testImage = al_load_bitmap(file.c_str());
		arrItems.push_back(testImage);
	}
}

ALLEGRO_BITMAP * Items::getBitMap()
{

	return ItemImage;
}