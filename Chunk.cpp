#include "Chunk.h"




Chunk::Chunk()
{
	terrainLayer.resize(chunkDim, std::vector<Tile>(chunkDim, Tile(Tile::GRASS)));
	oreLayer.resize(chunkDim, std::vector<Tile>(chunkDim, Tile(Tile::EMPTY)));
	initalGen();
	map = al_create_bitmap(1024, 1024);
}

void Chunk::genChunkMap()
{
		//
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
	for (int i = 0; i < chunkDim; i++)
	{
		for (int j = 0; j < chunkDim; j++)
		{
			terrainLayer[i][j].setChunkX(i);
			terrainLayer[i][j].setChunkY(j);
			oreLayer[i][j].setChunkX(i);
			oreLayer[i][j].setChunkY(j);
		}
	}
}

void Chunk::genChunk() //Might be worthless
{
	terrainLayer = gen.setTiles(terrainLayer);
	oreLayer = gen.setOres(oreLayer, terrainLayer);
	terrainLayer = gen.getTerrain();
	genChunkMap();
}


