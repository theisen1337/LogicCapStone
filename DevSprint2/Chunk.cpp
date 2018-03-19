#include "Chunk.h"




Chunk::Chunk()
{
	
}

void Chunk::genChunkMap(ALLEGRO_BITMAP* atl)
{
	//al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
	al_set_target_bitmap(map);

	//These two loops are for looping through map vectors
	for (int l = 0; l < GC::chunkDim; l++)
	{
		for (int m = 0; m < GC::chunkDim; m++)
		{
			terrainLayer[l][m].genPicture();
			oreLayer[l][m].genPicture();
			tempLoc = terrainLayer[l][m].getTilePic();
			al_draw_scaled_bitmap(atl,
				tempLoc[0], tempLoc[1],
				GC::tileStartDim, GC::tileStartDim,
				(l*GC::tileDim), (m*GC::tileDim),
				GC::tileDim, GC::tileDim, 0);
			tempLoc = oreLayer[l][m].getTilePic();
			al_draw_scaled_bitmap(atl,
				tempLoc[0], tempLoc[1],
				GC::tileStartDim, GC::tileStartDim,
				(l*GC::tileDim), (m*GC::tileDim),
				GC::tileDim, GC::tileDim, 0);
		}
	}

	isGen = true;
}

void Chunk::initalGen()
{
	terrainLayer.resize(GC::chunkDim, std::vector<Tile>(GC::chunkDim, Tile(Tile::GRASS)));
	oreLayer.resize(GC::chunkDim, std::vector<Tile>(GC::chunkDim, Tile(Tile::EMPTY)));
	map = al_create_bitmap(GC::tileDim * GC::chunkDim, GC::tileDim * GC::chunkDim);
}

void Chunk::genChunk() //Might be worthless
{
	
	oreLayer = gen.setOreGrid(oreLayer,terrainLayer);
	oreLayer = gen.newOreAlGore(oreLayer, terrainLayer);
	terrainLayer = gen.setTileGrid(terrainLayer);
	terrainLayer = gen.newLakeAlGore(oreLayer,terrainLayer);
	terrainLayer = gen.revampWater(terrainLayer);
}


