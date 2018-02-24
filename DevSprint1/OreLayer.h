#pragma once

#include "Ore.h"
#include <vector>

class OreLayer
{
public:
	std::vector<Ore> arrOres;
	void Compute();
	void Draw();
	OreLayer();
	~OreLayer();
	void addToLayer(Ore newOre);
};