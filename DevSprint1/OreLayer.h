#pragma once

#include "Ore.h"
#include <vector>

class OreLayer
{
public:
	std::vector<Ore> layer;
	void Compute();
	void Draw();
	OreLayer();
	~OreLayer();
	void addToLayer(Ore newOre);
};