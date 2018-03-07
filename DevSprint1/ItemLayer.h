#pragma once

#include <string>
#include <stdio.h>
#include <iostream>


#include "ItemBase.h"

#include <vector>
#include <array>
#include "ItemTemplate.h"

class ItemLayer
{
public:
	ItemLayer();
	~ItemLayer();

	void Draw();
	void Init();

	ALLEGRO_BITMAP * getItems(unsigned int index);

	std::vector<ItemBase> arrItems;

private:
	int SIZE_X = 100;
	int SIZE_Y = 100;
	int arr[100 * 100];
};