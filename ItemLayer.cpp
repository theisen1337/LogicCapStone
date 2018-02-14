#include "ItemLayer.h"

Item Items = *(LogisticsGame::getItem());

ItemLayer::ItemLayer() {}
ItemLayer::~ItemLayer() {}

ALLEGRO_BITMAP * ItemLayer::getItem(unsigned int index)
{
	if (index >= (arrItems.size()))
	{
		//error out of bounds
		return nullptr;
	}
	return (arrItems.at(index).getBitMap());
}