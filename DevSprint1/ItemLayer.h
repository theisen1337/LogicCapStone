#pragma once

#include <string>
#include <stdio.h>
#include <iostream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"

#include "main.h"

class ItemLayer
{
public:
	ItemLayer();
	~ItemLayer();

	//void drawTile(int i, float x, float y, float w, float h);
	ALLEGRO_BITMAP * getItem(unsigned int index);

private:
	int SIZE_X = 100;
	int SIZE_Y = 100;
	int arr[100 * 100];

	std::vector<Item> arrItems;
};