#include "Chunk.h"




Chunk::Chunk()
{
	
}

void Chunk::genChunkMap()
{
	
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
	map = al_create_bitmap(2050, 2050);
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
	oreLayer = gen.setOreGrid(oreLayer, terrainLayer);
	gen.newOreAlGore(oreLayer, terrainLayer);
	gen.newLakeAlGore(oreLayer, terrainLayer);
	terrainLayer = gen.revampWater(terrainLayer);


	/*Used before the Great Swtich of Water Ore.*/
	/*
	//terrainLayer = gen.lakeAlGore(terrainLayer);
	//oreLayer = gen.lakeAlGore(oreLayer);
	//oreLayer = gen.setOreGrid(oreLayer, terrainLayer);
	//gen.oreAlGore(oreLayer, terrainLayer); //This is for the 'void pointer' version
	//oreLayer = gen.oreAlGore(oreLayer, terrainLayer); //This was for the 'vector return' version
	//oreLayer = gen.revampOre(oreLayer); //commented out to see the tile under the TEMP_COAL
	*/

	//TESTING STUFF
	//gen.waterYouDoing(oreLayer, terrainLayer);
	//gen.oreoCookie(oreLayer, terrainLayer);

	genChunkMap();
}


