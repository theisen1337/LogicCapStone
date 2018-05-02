#pragma once

// Standard Includes
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>

// Custom Includes
#include "ItemBase.h"
#include "ItemTemplate.h"

class ItemLayer
{
public:
	//! Constructor
	ItemLayer();
	//! Deconstructor
	~ItemLayer();

	//! Draws the Layer
	void Draw();
	//! Initializes the Layer
	void Init();

	//! Returns the Items
	ALLEGRO_BITMAP * getItems(unsigned int index);

	//! Array to Hold Items
	std::vector<ItemBase> arrItems;

private:
	int SIZE_X = 100;
	int SIZE_Y = 100;
	int arr[100 * 100];
};