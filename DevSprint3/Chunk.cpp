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
					if (ref[i][j].compare(tempLoc) == 0)
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
// edited by brandon. uses the int bio to determine the biome
void Chunk::genChunk(int bio)
{
	//bio = 0; //DEBUG

	if (bio == 0)
	{
		//cout << "grass" << endl; //DEBUG
		terrainLayer = gen.initTerrain(terrainLayer, Tile::GRASS); //sets the initial grid to a single tile type
		terrainLayer = gen.setTileGrid(terrainLayer, Tile::WATER); ////places other tiles

		terrainLayer = gen.newLakeAlGore(oreLayer, terrainLayer, Tile::WATER, Tile::TEMP_WATER, 5); //spread 'lake' tiles
		terrainLayer = gen.revamp(terrainLayer, Tile::TEMP_WATER, Tile::WATER); //changes temp files to 'lake' tiles

		oreLayer = gen.setOreGrid(oreLayer, terrainLayer, Tile::COAL, Tile::IRON, Tile::WATER); //places ores
		oreLayer = gen.newOreAlGore(oreLayer, terrainLayer, Tile::COAL, Tile::IRON, 12); //spreads ores
	}
	
	else if (bio > 0)
	{
		//cout << "dessert" << endl; //DEBUG
		terrainLayer = gen.initTerrain(terrainLayer, Tile::SAND); //sets the initial grid to a single tile type
		terrainLayer = gen.setTileGrid(terrainLayer, Tile::QUICK); ////places other tiles

		terrainLayer = gen.newLakeAlGore(oreLayer, terrainLayer, Tile::QUICK, Tile::TEMP_QUICK, 4); //spread 'lake' tiles
		terrainLayer = gen.revamp(terrainLayer, Tile::TEMP_QUICK, Tile::QUICK); //changes temp files to 'lake' tiles

		oreLayer = gen.setOreGrid(oreLayer, terrainLayer, Tile::COAL, Tile::IRON, Tile::QUICK); //places ores
		oreLayer = gen.newOreAlGore(oreLayer, terrainLayer, Tile::COAL, Tile::IRON, 10); //spreads ores
	}
	
	else if (bio < 0)
	{
		//cout << "snow" << endl; //DEBUG
		terrainLayer = gen.initTerrain(terrainLayer, Tile::SNOW); //sets the initial grid to a single tile type
		terrainLayer = gen.setTileGrid(terrainLayer, Tile::WATER); ////places other tiles

		terrainLayer = gen.newLakeAlGore(oreLayer, terrainLayer, Tile::QUICK, Tile::TEMP_QUICK, 4); //spread 'lake' tiles
		terrainLayer = gen.revamp(terrainLayer, Tile::TEMP_QUICK, Tile::QUICK); //changes temp files to 'lake' tiles

		oreLayer = gen.setOreGrid(oreLayer, terrainLayer, Tile::ICE, Tile::IRON, Tile::QUICK); //places ores
		oreLayer = gen.newOreAlGore(oreLayer, terrainLayer, Tile::COAL, Tile::IRON, 10); //spreads ores
	}





	/*
	oreLayer = gen.setOreGrid(oreLayer,terrainLayer);
	oreLayer = gen.newOreAlGore(oreLayer, terrainLayer);
	terrainLayer = gen.setTileGrid(terrainLayer);
	terrainLayer = gen.newLakeAlGore(oreLayer,terrainLayer);
	terrainLayer = gen.revampWater(terrainLayer);
	*/
}

