#include "ItemTemplate.h"

CoalOreItem::CoalOreItem()
{
	//ItemBase("Coal-Ore");
	setPic("Resources//Items//ITEM_COAL.png");
	setName("Coal");
}

IronOreItem::IronOreItem()
{
	//ItemBase("Iron-Ore"); // <----- Bug
	setPic("Resources//Items//ITEM_IRON.png");
	setName("Iron");
}