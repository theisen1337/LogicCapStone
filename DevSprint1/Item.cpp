#include "Item.h"

// Constructor
Item::Item() {}

// Overloaded Constructor
Item::Item(std::string name, std::string category, float value, int width, int height, int stackSize)
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
Item::~Item() {}

// Getters which Get Values of Object
std::string Item::getName()
{
	return itemName;
}
std::string Item::getCategory()
{
	return itemCategory;
}
float Item::getValue()
{
	return itemValue;
}
int Item::getWidth()
{
	return itemWidth;
}
int Item::getHeight()
{
	return itemHeight;
}
int Item::getStackSize()
{
	return itemStackSize;
}

// Setters to Change Values of Object
void Item::setDropped()
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
bool Item::checkDropped()
{
	return itemDropped;
}

// This is called from Interactions Class when item is Right Clicked
void Item::pickupItem()
{
	// To Do
}

// This is called from Interactions Class when item is left clicked
