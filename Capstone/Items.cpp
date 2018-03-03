#include "Items.h"
#include "FileIO.h"
FileIO IO;

// Constructor
Items::Items()
{
	//loadItems(); No! bad taylor
}

Items::Items(std::string path, std::string name)
{
	FileIO file;
	ItemsImage = al_load_bitmap(file.openPicture(path).c_str());
	ItemsName = name;
}

// Overloaded Constructor
Items::Items(std::string name, std::string category, float value, int width, int height, int stackSize, int x, int y)
{
	ItemsName = name;
	ItemsCategory = category;
	ItemsValue = value;
	ItemsDropped = true;
	ItemsWidth = width;
	ItemsHeight = height;
	ItemstackSize = stackSize;
	xCoordinate = x;
	yCoordinate = y;
}

// Deconstructor
Items::~Items() {}
float Items::getCoordinateX()
{
	return xCoordinate;
}
float Items::getCoordinateY()
{
	return yCoordinate;
}

void Items::leftClick()
{

}
void Items::rightClick()
{

}

void Items::setXY(float x, float y)
{
	xCoordinate = x, yCoordinate = y;
}

// Getters which Get Values of Object
std::string Items::getName()
{
	return ItemsName;
}
std::string Items::getCategory()
{
	return ItemsCategory;
}
float Items::getValue()
{
	return ItemsValue;
}
int Items::getWidth()
{
	return ItemsWidth;
}
int Items::getHeight()
{
	return ItemsHeight;
}
int Items::getStackSize()
{
	return ItemstackSize;
}

// Setters to Change Values of Object
void Items::setDropped(bool boolVar)
{
	ItemsDropped = boolVar;
}

// Checks to see if Items is dropped or not
bool Items::checkDropped()
{
	return ItemsDropped;
}

// This is called from Interactions Class when Items is left Clicked
void Items::pickupItems()
{
	// To Do
}

// This is called from Interactions Class when tile is right clicked with Items
void Items::placeItems()
{
	// To Do
}



void Items::loadItems()
{
	checkItemsDirectory();
	load_Ores();
	//load_Armor();
	//load_Weapons(); ...
}

void Items::checkItemsDirectory()
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

	std::string test[] = { "Items_COAL.png" };

	for (int i = 0; i < test->length(); i++)
	{
		std::string file = "Items\\Ores\\" + test[i];
		ALLEGRO_BITMAP *testImage = al_load_bitmap(file.c_str());
		arrItems.push_back(testImage);
	}
}

ALLEGRO_BITMAP * Items::getBitMap()
{

	return ItemsImage;
}

void Items::Draw()
{
	al_draw_scaled_bitmap(ItemsImage, 0, 0, 16, 16,
		xCoordinate, yCoordinate, 32, 32, 0);
}