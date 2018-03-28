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

void ItemLayer::Init()
{
	/*IronOreItem iron = IronOreItem();
	iron.setXY(128 * 6, 128 * 6);
	iron.setPic("Items//Ore//ITEM_IRON2.png");
	CoalOreItem coal = CoalOreItem();
	coal.setXY(128 * 7, 128 * 6);
	coal.setPic("Items//Ore//ITEM_COAL2.png");
	arrItems.push_back(iron);
	arrItems.push_back(coal);*/
}

void ItemLayer::Draw(ALLEGRO_BITMAP * itemAtl, std::vector<std::vector<std::string>> &itemRef)
{
	if (!arrItems.empty())
	{
		for (int i = 0; i < arrItems.size(); i++)
			arrItems[i].Draw(itemAtl, itemRef);
	}
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