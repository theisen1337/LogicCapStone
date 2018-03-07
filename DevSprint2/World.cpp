#include "World.h"



World::World()
{	
		
}

void World::InitalizeClass()
{
	//Sets the vector size
	world.resize(2, std::vector<Chunk>(2, Chunk()));
	//Runs the initial generation of map
	initialGeneration();
}

void World::initialGeneration()
{
	//Assign world positions to chunks
	for (int i = 0; i < worldSize; i++)
	{
		for (int j = 0; j < worldSize; j++) {
			world[i][j].initalGen();
			//world[i][j].setWorldPosW(i);
			//world[i][j].setWorldPosH(j);
			world[i][j].genChunk();
			//world[i][j].toggleGen();
		}
	}

	
}

//Required for Infinate Map
void World::updateWorld(int charWorldW, int charWorldH)
{
	/*
	Get the characters current World Vector position. 
	If they are not in the center Map of the vector
		- Unload chunks no longer viewable
		- Readjust world vector so character current map is center of vector.
		- Load chunks now viewable
			- If new chunks, generate those chunks
		- Set character world vector positions back to center
	*/
}


