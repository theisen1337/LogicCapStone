#include "Chunk.h"




Chunk::Chunk()
{
	
}

void Chunk::genChunkMap()
{
	al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
	al_set_target_bitmap(map);
	ALLEGRO_BITMAP *pic;
	//These two loops are for looping through map vectors
	for (int l = 0; l < chunkDim; l++)
	{
		for (int m = 0; m < chunkDim; m++)
		{
			terrainLayer[l][m].genPicture();
			oreLayer[l][m].genPicture();
			pic = terrainLayer[l][m].getTilePic();
			al_draw_scaled_bitmap( pic,
				0, 0,
				al_get_bitmap_width(pic), al_get_bitmap_height(pic),
				(l*tileDim), (m*tileDim),
				tileDim, tileDim, 0);
			pic = oreLayer[l][m].getTilePic();
			al_draw_scaled_bitmap(pic,
				0, 0,
				al_get_bitmap_width(pic), al_get_bitmap_height(pic),
				(l*tileDim), (m*tileDim),
				tileDim, tileDim, 0);
				
		}
	}


}

void Chunk::initalGen()
{
	terrainLayer.resize(chunkDim, std::vector<Tile>(chunkDim, Tile(Tile::GRASS)));
	oreLayer.resize(chunkDim, std::vector<Tile>(chunkDim, Tile(Tile::EMPTY)));
	map = al_create_bitmap(2048, 2048);
	/*
	for (int i = 0; i < chunkDim; i++)
	{
		for (int j = 0; j < chunkDim; j++)
		{
			terrainLayer[i][j].setChunkX(i);
			terrainLayer[i][j].setChunkY(j);
			oreLayer[i][j].setChunkX(i);
			oreLayer[i][j].setChunkY(j);
		}
	}*/
}

void Chunk::genChunk() //Might be worthless
{
	
	terrainLayer = gen.setTileGrid(terrainLayer);
	terrainLayer = gen.lakeAlGore(terrainLayer);
	oreLayer = gen.setOreGrid(oreLayer,terrainLayer);
	oreLayer = gen.oreAlGore(oreLayer, terrainLayer);
	oreLayer = gen.revampOre(oreLayer);
	genChunkMap();
}


