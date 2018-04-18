#pragma once

#include "OreBase.h"
#include <vector>

class OreLayer
{
public:
	std::vector<OreBase> layer;
	void Compute();
	void Draw();
	OreLayer();
	~OreLayer();
	void addToLayer(OreBase newOre);
};