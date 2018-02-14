#include "Chunk.h"




Chunk::Chunk()
{
	bottomLayer.resize(chunkDim, std::vector<Tile>(chunkDim, Tile(Tile::GRASS)));
	initalGen();
	map = al_create_bitmap(2048, 2048);
	genChunkMap();
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
			bottomLayer[l][m].genPicture();
			pic = bottomLayer[l][m].getTilePic();
			al_draw_scaled_bitmap( pic,
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
			bottomLayer[i][j].setChunkX(i);
			bottomLayer[i][j].setChunkY(j);
		}
	}
}
