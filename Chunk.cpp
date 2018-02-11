#include "Chunk.h"

void Chunk::genChunkMap()
{
		//
	al_set_target_bitmap(map);

	//These two loops are for looping through map vectors
	for (int l = 0; l < chunkDim; l++)
	{
		for (int m = 0; m < chunkDim; m++)
		{
			al_draw_scaled_bitmap(bottomLayer[l][m].getTilePic() ,
				0, 0,
				tileDim, tileDim,
				(l*tileDim), (m*tileDim),
				tileDim, tileDim, 0);
		}
	}


}
