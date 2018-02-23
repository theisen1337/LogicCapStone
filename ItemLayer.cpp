#include "ItemLayer.h"

//Items Items = *(LogisticsGame::getItems());

ItemsLayer::ItemsLayer() {}
ItemsLayer::~ItemsLayer() {}

ALLEGRO_BITMAP * ItemsLayer::getItems(unsigned int index)
{
	if (index >= (arrItems.size()))
	{
		//error out of bounds
		return nullptr;
	}
	return (arrItems.at(index).getBitMap());
}