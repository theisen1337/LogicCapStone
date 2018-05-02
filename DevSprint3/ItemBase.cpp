#include "ItemBase.h"
#include "FileIO.h"
FileIO IO;

// #######################
// # Default Constructor #
// #######################
ItemBase::ItemBase() {}

// ##########################
// # Overloaded Constructor #
// ##########################
ItemBase::ItemBase(std::string name)
{
	ItemsName = name;
}

// ##########################
// # Overloaded Constructor #
// ##########################
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

// #################
// # Deconstructor #
// #################
ItemBase::~ItemBase() {}

// ###################
// # Set Item Bitmap #
// ###################
void ItemBase::setPic(std::string path)
{
	FileIO file;
	ItemsImage = al_load_bitmap(file.openPicture(path).c_str());
}

// #################
// # Set Item Name #
// #################
void ItemBase::setName(std::string name)
{
	ItemsName = name;
}

// ####################
// # Get X Coordinate #
// ####################
float ItemBase::getCoordinateX()
{
	return xCoordinate;
}

// ####################
// # Get Y Coordinate #
// ####################
float ItemBase::getCoordinateY()
{
	return yCoordinate;
}

// ###################
// # Left Click Item #
// ###################
void ItemBase::leftClick()
{
	al_show_native_message_box(al_get_current_display(),
		"Item:",
		ItemsName.c_str(),
		"Success",
		NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

// ####################
// # Right Click Item #
// ####################
void ItemBase::rightClick()
{

}

// ###############################
// # Set the X and Y Coordinates #
// ###############################
void ItemBase::setXY(float x, float y)
{
	xCoordinate = x, yCoordinate = y;
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

// ##############################
// # Set the Item Dropped Check #
// ##############################
void ItemBase::setDropped(bool boolVar)
{
	ItemsDropped = boolVar;
}

// #########################
// # Check if Item Dropped #
// #########################
bool ItemBase::checkDropped()
{
	return ItemsDropped;
}

// ################
// # Pickup Items #
// ################
void ItemBase::pickupItems()
{
	// To Do
}

// ###############
// # Place Items #
// ###############
void ItemBase::placeItems()
{
	// To Do
}

// ##############
// # Load Items #
// ##############
void ItemBase::loadItems()
{
	checkItemsDirectory();
	load_Ores();
	//load_Armor();
	//load_Weapons(); ...
}

// #############################
// # Checks for Item Directory #
// #############################
void ItemBase::checkItemsDirectory()
{
	if (!IO.DirectoryExist("Items"))
	{
		IO.CreateDir("Items");
	}
}

// ############################
// # Checks for Ore Directory #
// ############################
void ItemBase::load_Ores()
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

// ######################
// # Returns the Bitmap #
// ######################
ALLEGRO_BITMAP * ItemBase::getBitMap()
{
	return ItemsImage;
}

// ##################
// # Draws the Item #
// ##################
void ItemBase::Draw()
{
	al_draw_bitmap(ItemsImage, xCoordinate, yCoordinate,0);
}
