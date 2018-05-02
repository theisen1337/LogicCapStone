#include "ItemLayer.h"

// ###############
// # Constructor #
// ###############
ItemLayer::ItemLayer() {}

// #################
// # Deconstructor #
// #################
ItemLayer::~ItemLayer() {}

// ####################
// # Initialize Layer #
// ####################
void ItemLayer::Init() {}

// ###################
// # Draws the Layer #
// ###################
void ItemLayer::Draw()
{
	if (!arrItems.empty())
	{
		for (int i = 0; i < arrItems.size(); i++)
			arrItems.at(i).Draw();
	}
}

// #####################
// # Returns the Items #
// #####################
ALLEGRO_BITMAP * ItemLayer::getItems(unsigned int index)
{
	if (index >= (arrItems.size()))
	{
		//error out of bounds
		return nullptr;
	}
	return (arrItems.at(index).getBitMap());
}
