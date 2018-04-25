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


//added by brandon, 
vector < vector <int> > World::bioChange1(vector < vector <int> > &biome)
{
	for (int i = 0; i < 5; i++) //5x5 world
	{
		for (int j = 0; j < 5; j++)
		{
			cout << biome[i][j]; //DEBUG
		}
	}

	int bio;
	int r;

	for (int i = 0; i < biome.size(); i++) //5x5 world
	{
		for (int j = 0; j < biome[i].size(); j++)
		{
			r = rand() % 2;
			if (r == 0 && i != 0)
			{
				bio = biome[i - 1][j]; //choose the topper
			}
			else if (r == 1 && j != 0)
			{
				bio = biome[i][j - 1]; //choose the lefter
			}
			else if (r == 0 && i == 0 && j != 0) //choose the left when we're at the top
			{
				bio = biome[i][j - 1];
			}
			else if (r == 1 && j == 0 && i != 0) //choose the top when we're at the left
			{
				bio = biome[i - 1][j];
			}
			else //biome1[0][0]
			{
				bio = 0;
			}

			cout << "r: " << r << ", bio: " << bio << endl;

			r = rand() % 3 - 1;
			biome[i][j] = bio + r;

			cout << "r: " << r << ", biome: " << biome[i][j] << endl << endl;
		}
	}

	//DEBUG
	for (int i = 0; i < 5; i++) //5x5 world
	{
		for (int j = 0; j < 5; j++)
		{
			cout << biome[i][j] << " ";
		}
		cout << endl;
	}

	return biome;
}


//added by brandon, fixes the edges NOT DONE
vector< vector <Chunk> > World::borderControl(vector< vector <Chunk> > world)
{
	//32x32-tile chunks, 5x5-chunk world, resulting in 160x160-tile world
	//worldtile[i*32][j*32]

	int r;

	for (int i = 0; i < GC::worldDim; i++)
	{
		for (int j = 0; j < GC::worldDim; j++)
		{
			/*
			// world[i][j]
			//Top edge


			if (i != 0)
			{
				for (int y = 0; y < 32; y++)
				{
					r = rand() % 3; //0,1,2
					worldtile[i*32+1][j*32] = worldtile[i*32-r][j*32]; //the tile 1 below the first tile of the chunk will be either the same, or changed to one of the above tiles
					worldtile[i*32+2][j*32] = worldtile[i*32-r][j*32];
				}
			}

			//Left edge
			if (j != 0)
			{
				for (int x = 0; x < 32; x++)
				{
					r = rand() % 3; //0,1,2
					worldtile[i*32][j*32+1] = worldtile[i*32][j*32-r]; //the tile 1 below the first tile of the chunk will be either the same, or changed to one of the left tiles
					worldtile[i*32][j*32+2] = worldtile[i*32][j*32-r];
				}
			}


			*/	
		}
	}
	return world;
}

void World::initialGeneration()
{
	//Assign world positions to chunks

	//CONSTRUCTION
	//ADD HERE!!
	biome.resize(GC::worldDim, vector<int>(GC::worldDim, 0)); //resize the vector to be the same as the World
	cout << biome.size() << biome[0].size();
	bioChange1(biome); //change the biome stats for the biome vector

	//DEBUG
	for (int i = 0; i < GC::worldDim; i++)
	{
		for (int j = 0; j < GC::worldDim; j++)
		{
			cout << biome[i][j] << " ";
		}
		cout << endl;
	}

	//Actual Generation
	for (int i = 0; i < GC::worldDim; i++)
	{
		for (int j = 0; j < GC::worldDim; j++) 
		{
			world[i][j].initalGen();
			//world[i][j].genChunk(); //old
			//world[i][j].genChunk(0); //DEBUG
			world[i][j].genChunk(biome[i][j]); //use the biome stat from the biome vector
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

//32x32-tile chunks, 5x5-chunk world, resulting in 160x160-tile world

