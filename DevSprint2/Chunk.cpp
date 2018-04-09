#include "Chunk.h"

// ###############
// # CONSTRUCTOR #
// ###############
Chunk::Chunk() {}

// #######################
// # GENERATES CHUNK MAP #
// #######################
void Chunk::genChunkMap(ALLEGRO_BITMAP* atl, std::vector<std::vector<std::string>> &ref)
{
	//al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
	al_set_target_bitmap(map);

	//These two loops are for looping through map vectors
	for (int l = 0; l < GC::chunkDim; l++)
	{
		for (int m = 0; m < GC::chunkDim; m++)
		{
			terrainLayer[l][m].genPicture();

			for (int i = 0; i < ref.size(); i++)
			{
				for (int j = 0; j < ref[i].size(); j++)
				{
					tempLoc = terrainLayer[l][m].getAtLoc();
					if (ref[i][j].compare(tempLoc)==0)
					{
						al_draw_scaled_bitmap(atl,
							(i*GC::tileDim), (j*GC::tileDim),
							GC::tileDim, GC::tileDim,
							(l*GC::tileDim), (m*GC::tileDim),
							GC::tileDim, GC::tileDim, 0);
						break;
					}
				}
			}
		}
	}

	for (int n = 0; n < GC::chunkDim; n++)
	{
		for (int o = 0; o < GC::chunkDim; o++)
		{
			oreLayer[n][o].genPicture();

			for (int i = 0; i < ref.size(); i++)
			{
				for (int j = 0; j < ref[i].size(); j++)
				{
					tempLoc = oreLayer[n][o].getAtLoc();
					if (ref[i][j].compare(tempLoc) == 0)
					{
						al_draw_scaled_bitmap(atl,
							(i*GC::tileDim), (j*GC::tileDim),
							GC::tileDim, GC::tileDim,
							(n*GC::tileDim), (o*GC::tileDim),
							GC::tileDim, GC::tileDim, 0);
						break;
					}
				}
			}
		}
	}


	isGen = true;
}

// ######################
// # INITIAL GENERATION #
// ######################
void Chunk::initalGen()
{
	terrainLayer.resize(GC::chunkDim, std::vector<Tile>(GC::chunkDim, Tile(Tile::GRASS)));
	oreLayer.resize(GC::chunkDim, std::vector<Tile>(GC::chunkDim, Tile(Tile::EMPTY)));
	map = al_create_bitmap(GC::tileDim * GC::chunkDim, GC::tileDim * GC::chunkDim);
}

// UNDER CONSTRUCTION
void Chunk::genChunk() //Might be worthless
{
	oreLayer = gen.setOreGrid(oreLayer,terrainLayer);
	oreLayer = gen.newOreAlGore(oreLayer, terrainLayer);
	terrainLayer = gen.setTileGrid(terrainLayer);
	terrainLayer = gen.newLakeAlGore(oreLayer,terrainLayer);
	terrainLayer = gen.revampWater(terrainLayer);
}
