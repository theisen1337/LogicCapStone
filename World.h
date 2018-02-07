#pragma once
#include <vector>
#include "Chunk.h"
class World
{
private:
		//Dimensions of world vector 
	int worldSize = 3;
		//offset of world vector (Rounds down, so center of vector is 1,1)
	int offset = 3/2;
	 
public:
		//2D vector to hold Chunks
	std::vector<std::vector<Chunk>> world;
		//Constructor
	World();
	
		//First generation of world
	void initialGeneration();
		//Update world depending on character position
	void updateWorld(int charWorldW, int charWorldH);
		//Get vector for the world
	std::vector<std::vector<Chunk>> getChunk() { return world; };
};

