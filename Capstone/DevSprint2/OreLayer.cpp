#include "OreLayer.h"

void OreLayer::Compute()
{
}

void OreLayer::Draw()
{
	for (int i = 0; i < layer.size(); i++)
	{
		layer.at(i).draw();
	}
}

OreLayer::OreLayer()
{
}

OreLayer::~OreLayer()
{
}

void OreLayer::addToLayer(OreBase newOre)
{
	layer.push_back(newOre);
}
