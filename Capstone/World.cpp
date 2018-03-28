#include "World.h"



World::World()
{	
		
}

void World::InitalizeClass()
{
	//worldSize = 5;
	//Sets the vector size
	world.resize(GC::worldDim, std::vector<Chunk>(GC::worldDim, Chunk()));
	//Runs the initial generation of map
	initialGeneration();
}

void World::initialGeneration()
{
	//Assign world positions to chunks
	for (int i = 0; i < GC::worldDim; i++)
	{
		for (int j = 0; j < GC::worldDim; j++) {
			world[i][j].initalGen();
			world[i][j].genChunk();
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

void World::drawWorld(ALLEGRO_BITMAP* atl, ALLEGRO_DISPLAY &dis, std::vector<std::vector<std::string>> &ref)
{

	for (int i = 0; i < GC::worldDim; i++)
	{
		for (int j = 0; j < GC::worldDim; j++)
		{
			if (!world[i][j].getGen())
			{
				world[i][j].genChunkMap(atl,ref);
				al_set_target_backbuffer(&dis);
			}

			al_draw_bitmap(world[i][j].getMap(), (i * (GC::tileDim * GC::chunkDim)), (j * (GC::tileDim * GC::chunkDim)), 0);
		}
	}


}



