#include "OreLayer.h"

void OreLayer::Compute()
{
}

void OreLayer::Draw()
{
	for (int i = 0; i < arrOres.size(); i++)
	{
		arrOres.at(i).draw();
	}
}

OreLayer::OreLayer()
{
}

OreLayer::~OreLayer()
{
}

void OreLayer::addToLayer(Ore newOre)
{
	arrOres.push_back(newOre);
}
