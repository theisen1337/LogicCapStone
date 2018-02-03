#pragma once
#include <vector>
#include "Chunk.h"
class World
{
private:
	int worldSize = 5;
	int offset = 5/2;
	 
public:
	std::vector<std::vector<Chunk>> world;
	World();
	void initialGeneration();
	void updateWorld(int charWorldW, int charWorldH);
	std::vector<std::vector<Chunk>> getWorld() { return world; };
};

