#include "Artist.h"



Artist::Artist()
{

}

void Artist::tileBuffer(ALLEGRO_DISPLAY &dis, World world)
{
	Bitmap = al_create_bitmap(2048, 2048);
	al_set_target_bitmap(Bitmap);
	//These two loops are for looping through world vector
	for (int j = 0; j < worldDim; j++)
	{
		for (int k = 0; k < worldDim; k++)
		{
			al_draw_scaled_bitmap(world.getChunk()[j][k].getMap(),
				0, 0,
				2048, 2048,
				(j*2048), (k*2048),
				2048, 2048, 0);
			//al_set_target_backbuffer(&dis);
		}
	}
	al_set_target_backbuffer(&dis);
}

void Artist::drawWorld(ALLEGRO_DISPLAY &dis, float scroll_x, float scroll_y, float zoom, float rotate, World world)
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
	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {

			al_draw_scaled_bitmap(Bitmap, 0, 0, 1024, 1024, x * 2048, y * 2048, 2048, 2048, 0);
			
		}
	}
	
	al_hold_bitmap_drawing(0);
	
	al_identity_transform(&transform);
	al_use_transform(&transform);
}



