#include "ItemBase.h"
#include "FileIO.h"
FileIO IO;

// Constructor
ItemBase::ItemBase() {}

// Deconstructor
ItemBase::~ItemBase() {}

ItemBase::ItemBase(std::string name)
{
	ItemsName = name;
	xCoordinate = 0;
	yCoordinate = 0;
}

// Overloaded Constructor
ItemBase::ItemBase(std::string name, std::string category, float value, int width, int height, int stackSize, int x, int y)
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

void ItemBase::setPic(std::string path)
{
	FileIO file;
	ItemsImage = al_load_bitmap(file.openPicture(path).c_str());
}
void ItemBase::setName(std::string name)
{
	ItemsName = name;
}

float ItemBase::getCoordinateX()
{
	return xCoordinate;
}
float ItemBase::getCoordinateY()
{
	return yCoordinate;
}

void ItemBase::leftClick()
{
	al_show_native_message_box(al_get_current_display(),
		"Item:",
		ItemsName.c_str(),
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);
}
void ItemBase::rightClick()
{

}

void ItemBase::setXY(float x, float y)
{
	xCoordinate = x;
	yCoordinate = y;
}

// Getters which Get Values of Object
std::string ItemBase::getName()
{
	return ItemsName;
}
std::string ItemBase::getCategory()
{
	return ItemsCategory;
}
float ItemBase::getValue()
{
	return ItemsValue;
}
int ItemBase::getWidth()
{
	return ItemsWidth;
}
int ItemBase::getHeight()
{
	return ItemsHeight;
}
int ItemBase::getStackSize()
{
	return ItemstackSize;
}

// Setters to Change Values of Object
void ItemBase::setDropped(bool boolVar)
{
	ItemsDropped = boolVar;
}

// Checks to see if Items is dropped or not
bool ItemBase::checkDropped()
{
	return ItemsDropped;
}

// This is called from Interactions Class when Items is left Clicked
void ItemBase::pickupItems()
{
	// To Do
}

// This is called from Interactions Class when tile is right clicked with Items
void ItemBase::placeItems()
{
	// To Do
}

void ItemBase::loadItems()
{
	checkItemsDirectory();
	load_Ores();
	//load_Armor();
	//load_Weapons(); ...
}

// Ensures we have Access to the Item Image Directory
void ItemBase::checkItemsDirectory()
{
	if (!IO.DirectoryExist("Items"))
	{
		IO.CreateDir("Items");
	}
}

void ItemBase::load_Ores()
{
	// Checks for Ore Images
	if (!IO.DirectoryExist("Items\\Ores"))
	{
		IO.CreateDir("Items\\Ores");
	}

	// Loads up Coal Items
	std::string test[] = { "Items_COAL.png" };

	for (int i = 0; i < test->length(); i++)
	{
		std::string file = "Items\\Ores\\" + test[i];
		ALLEGRO_BITMAP *testImage = al_load_bitmap(file.c_str());
		arrItems.push_back(testImage);
	}
}

ALLEGRO_BITMAP * ItemBase::getBitMap()
{
	return ItemsImage;
}

void ItemBase::Draw()
{
	al_draw_bitmap(ItemsImage, xCoordinate, yCoordinate, 0);
	//al_draw_scaled_bitmap(ItemsImage,0,0, 16,16, xCoordinate, yCoordinate, 32,32,0);
}