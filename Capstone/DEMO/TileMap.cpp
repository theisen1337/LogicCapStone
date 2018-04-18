#include "TileMap.h"
#include "Tiles.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

//#include <stdio.h>
#include <stdlib.h>
#include <time.h>       /* time */


TileMap::TileMap()
{
	srand(time(NULL));
	
}


TileMap::~TileMap()
{
}

void TileMap::drawTile(int i, float x, float y, float w, float h)
{
	al_draw_filled_rectangle(x, y, x + w, y + h, al_map_rgb(0, 0, 0));
	al_draw_scaled_bitmap(&*(tiles.getTile(i)), 0, 0, 48, 48, x, y, w, h, 0);
}

void TileMap::CreateTileBuffer(ALLEGRO_DISPLAY &dis)
{
	int i;
	int x, y;
	/* Create the tile atlas. */
	Bitmap = al_create_bitmap(1024, 1024);
	al_set_target_bitmap(Bitmap);
	al_clear_to_color(al_map_rgba(0, 0, 0, 0));
	for (i = 0; i < tiles.getTotal(); i++) {
		/* We draw the tiles a bit bigger (66x66 instead of 64x64)
		* to account for the linear filtering. Normally just leaving
		* the border transparent for sprites or repeating the border
		* for tiling tiles should work well.
		*/
		drawTile(i, i * 66, 0, 66, 66);
	}
	al_set_target_backbuffer(&dis);
}

void TileMap::Generate_Terrain()
{

	for (int y = 0; y < SIZE_Y; y++) {
		for (int x = 0; x < SIZE_X; x++) {
			arr[x + y * 100] = rand() % tiles.grassCount + tiles.grassOffset;
		}
	}
	
	Generate_Ore();

	
		//arr[(rand() % SIZE_X) + (rand() % SIZE_Y) * 100] = rand() % tiles.OreCount + tiles.OreOffset;
}

void TileMap::Generate_Ore()
{
	int seeds = rand() % 20 + 10;
	for (int i = 0; i < seeds; i++)
	{
		int x = (rand() % SIZE_X);
		int y = (rand() % SIZE_Y);
		arr[x + y * 100] = rand() % tiles.OreCount + tiles.OreOffset;
		int spread = rand() % 20 + 10;
		for (int z = 0; z < spread; z++)
		{
			int offsetX = x;
			int offsetY = y;

			while (true)
			{
				switch (rand() % 8)
				{
				//case 0: offsetX--;	offsetY--;	break;
				case 1:;			offsetY--;	break;
				//case 2: offsetX++;	offsetY--;	break;
				case 3: offsetX--; ;			break;
				case 4:; ;			break;
				case 5: offsetX++; ;			break;
				//case 6: offsetX--;	offsetY++;	break;
				case 7:;			offsetY++;	break;
				//case 8: offsetX++;	offsetY++;	break;
				}
				if (offsetX < SIZE_X && offsetY < SIZE_Y && offsetX > 0 && offsetY > 0)
				{
					int ore = rand() % tiles.OreCount + tiles.OreOffset;
					if (arr[offsetX + offsetY * 100] != ore)
					{
						arr[offsetX + offsetY * 100] = ore;
						break;
					}
				}
				else
				{
					offsetX = x;
					offsetY = y;
				}
				
			}
		}

	}
}

void TileMap::TileMapDraw(ALLEGRO_DISPLAY &dis,float scroll_x,float scroll_y, float zoom, float rotate) {
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
			int i = arr[x + y * 100];
			float u = 1 + i * 66;
			float v = 1;
			al_draw_scaled_bitmap(Bitmap, u, v, 64, 64,
				x * 32, y * 32, 32, 32, 0);
		}
	}
	al_hold_bitmap_drawing(0);

	al_identity_transform(&transform);
	al_use_transform(&transform);
}