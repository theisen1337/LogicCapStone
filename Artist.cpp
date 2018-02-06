#include "Artist.h"



Artist::Artist()
{

}

void Artist::tileBuffer(ALLEGRO_DISPLAY &dis, World world)
{
	//Tile Atlas
	Bitmap = al_create_bitmap(worldSize, worldSize);
	al_set_target_bitmap(Bitmap);
	//al_clear_to_color(al_map_rgba(0, 0, 0, 0));


	std::string path = "Images\\Tiles\\grass.png";
	ALLEGRO_BITMAP *pic = al_load_bitmap(path.c_str());
	//These two loops are for looping through world vector
	for (int j = 0; j < worldDim; j++)
	{
		for (int k = 0; k < worldDim; k++)
		{
			std::vector<std::vector<Chunk>> *tempWorld = &world.getWorld();
			//These two loops are for looping through map vectors
			for (int l = 0; l < chunkDim; l++)
			{
				for (int m = 0; m < chunkDim; m++)
				{
					/*
					al_draw_filled_rectangle(
						l*tileDim + (j * tileDim * chunkDim), m*tileDim + (k * tileDim * chunkDim), 
						(l*tileDim) + (j * tileDim * chunkDim) + tileDim, (m*tileDim) + (k * tileDim * chunkDim) + tileDim,
						al_map_rgb(0, 0, 0));*/
					al_draw_scaled_bitmap(al_load_bitmap(path.c_str()),
						l*tileDim + (j * tileDim * chunkDim), m*tileDim + (k * tileDim * chunkDim), 
						tileDim, tileDim, 
						(l*tileDim) + (j * tileDim * chunkDim) + tileDim, (m*tileDim) + (k * tileDim * chunkDim) + tileDim,
						tileDim, tileDim, 0);
				}
			}
		}
	}
	


}

void Artist::drawWorld(ALLEGRO_DISPLAY &dis, float scroll_x, float scroll_y, float zoom, float rotate)
{
	int x, y;
	ALLEGRO_TRANSFORM transform;
	float w, h;

	w = al_get_display_width(&dis);
	h = al_get_display_height(&dis);

	/* Initialize transformation. */
	al_identity_transform(&transform);
	/* Move to scroll position. */
	al_translate_transform(&transform, -scroll_x, -scroll_y);
	/* Rotate and scale around the center first. */
	al_rotate_transform(&transform, rotate);
	al_scale_transform(&transform, zoom, zoom);
	/* Move scroll position to screen center. */
	al_translate_transform(&transform, w * 0.5, h * 0.5);
	/* All subsequent drawing is transformed. */
	al_use_transform(&transform);

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_hold_bitmap_drawing(1);
	for (y = 0; y < 100; y++) {
		for (x = 0; x < 100; x++) {
			//int i = arr[x + y * 100];
			//float u = 1 + i * 66;
			float v = 1;
			//al_draw_scaled_bitmap(Bitmap, u, v, 64, 64,
				//x * 32, y * 32, 32, 32, 0);
		}
	}
	al_hold_bitmap_drawing(0);
	
	al_identity_transform(&transform);
	al_use_transform(&transform);
}

void Artist::drawBitmapTest(ALLEGRO_DISPLAY & dis)
{
	al_draw_bitmap(Bitmap, 1024, 1024, 0);
}


