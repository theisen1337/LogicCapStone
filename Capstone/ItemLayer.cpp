#include "ItemLayer.h"

ItemLayer::ItemLayer() 
{
	// Example. Do not use in production.
	
	//CoalOreItem coalOre1 = CoalOreItem();
	//IronOreItem ironOre1 = IronOreItem();

	//arrItems.push_back(coalOre1);
	//arrItems.push_back(ironOre1);
}

ItemLayer::~ItemLayer() {}

void ItemLayer::Draw()
{
	//for (int i = 0; i < arrItems.size(); i++)
	//	arrItems.at(i).Draw();
}

ALLEGRO_BITMAP * ItemLayer::getItems(unsigned int index)
{
	if (index >= (arrItems.size()))
	{
		//error out of bounds
		return nullptr;
	}
	return (arrItems.at(index).getBitMap());
}