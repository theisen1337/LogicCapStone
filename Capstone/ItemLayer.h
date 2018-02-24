#pragma once

#include <string>
#include <stdio.h>
#include <iostream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"

#include "Items.h"

#include <vector>
#include "ItemTemplate.h"

class ItemLayer
{
public:
	ItemLayer();
	~ItemLayer();

	void Draw();

	ALLEGRO_BITMAP * getItems(unsigned int index);

private:
	int SIZE_X = 100;
	int SIZE_Y = 100;
	int arr[100 * 100];

	std::vector<Items> arrItems;
};