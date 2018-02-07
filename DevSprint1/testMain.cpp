#include <Windows.h>
#include <iostream>
#include <string>
#include "World.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "Artist.h"

using namespace std;

ALLEGRO_DISPLAY *display = NULL;

ALLEGRO_BITMAP *image;



int main(void) {
	World world = World();
	Artist art = Artist();
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	//al_init_font_addon();


	/* Create our window. */
	//al_set_new_display_flags(ALLEGRO_RESIZABLE);
	display = al_create_display(640, 480);
	al_set_window_title(display, "Allegro 5 Tilemap Example");
	
	//Checking vectors of world and maps
	/*
	int numChunksGen = 0;
	int numTilesLoaded = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (world.getChunk()[i][j].getGen())
								{
									numChunksGen++;
								}
			for (int k = 0; k < 16; k++)
			{
				for (int l = 0; l < 16; l++)
				{
					
					if (world.getChunk()[i][j].getTiles()[k][l].getLoaded())
					{
						numTilesLoaded++;
					}
				}
			}
		}
	}
	std::cout << "Number of Chunks: " << numChunksGen << "\n";
	std::cout << "Number of Tiles: " << numTilesLoaded << "\n";
	*/

	image = al_load_bitmap("Tiles//grass.png");
	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	//al_draw_bitmap(image, 200, 200, 0);

	art.tileBuffer(*display, world); //NOT WORKING
	//art.drawBitmapTest(*display); 
	//al_clear_to_color(al_map_rgba(0, 0, 0, 0));
	al_flip_display();
	al_rest(30.0);
	al_destroy_display(display);


	system("pause");
	return 0;
}
