#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "World.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_font.h"
#include "Artist.h"

using namespace std;

ALLEGRO_DISPLAY *display = NULL;

ALLEGRO_BITMAP *image;

/*Keep track of pressed mouse button. */
int mouse;
/* Camera parameters. */
float zoom = 0.5, rot;
float scroll_x, scroll_y;
/* Our icon and font. */

//ALLEGRO_BITMAP *icon;
ALLEGRO_FONT *font;
/* Simple FPS counter. */
int fps, fps_accum;
double fps_time;




int main(void) {
	
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *queue;
	bool redraw = true;

	srand(time(NULL));


	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_install_mouse();
	al_install_keyboard();


	World world = World();
	Artist art = Artist();
	/*
	for (int i = 0; i < 32; i++) 
	{
		for (int j = 0; j < 32; j++)
		{
			world.getChunk()[0][1].getTiles()[i][j].setType(Tile::EMPTY);
			world.getChunk()[1][0].getTiles()[i][j].setType(Tile::EMPTY);
			world.getChunk()[1][2].getTiles()[i][j].setType(Tile::EMPTY);
			world.getChunk()[2][1].getTiles()[i][j].setType(Tile::EMPTY);
		}
	}
	*/
	/* Create our window. */
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	display = al_create_display(640, 480);
	al_set_window_title(display, "Allegro 5 Tilemap Example");
	font = al_create_builtin_font();

	//al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
	art.tileBuffer(*display, world);

	timer = al_create_timer(1.0 / 60);
	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	scroll_x = 96 * 32 / 2;
	scroll_y = 96 * 32 / 2;

	while (1) {
		//tile_map_create();
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (event.keyboard.keycode == ALLEGRO_KEY_R)
				//Map.Generate_Terrain();
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				break;
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			mouse = event.mouse.button;
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			mouse = 0;
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			/* Left button scrolls. */
			if (mouse == 1) {
				float x = event.mouse.dx / zoom;
				float y = event.mouse.dy / zoom;
				scroll_x -= x * cos(rot) + y * sin(rot);
				scroll_y -= y * cos(rot) - x * sin(rot);
			}
			/* Right button zooms/rotates. */
			if (mouse == 2) {
				rot += event.mouse.dx * 0.01;
				zoom += event.mouse.dy * 0.01 * zoom;
			}
			zoom += event.mouse.dz * 0.1 * zoom;
			if (zoom < 0.1) zoom = 0.1;
			if (zoom > 10) zoom = 10;
		}
		if (event.type == ALLEGRO_EVENT_TIMER)
			redraw = true;
		if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE) {
			al_acknowledge_resize(display);
			redraw = true;
		}

		if (redraw && al_is_event_queue_empty(queue)) {
			redraw = false;
			double t = al_get_time();
			//THIS LINE IS CHANGED
			art.drawWorld(*display, scroll_x, scroll_y, zoom, rot,world);
			if (font) {
				al_draw_filled_rounded_rectangle(4, 4, 100, 30,
					8, 8, al_map_rgba(0, 0, 0, 200));
				al_draw_textf(font, al_map_rgb(255, 255, 255),
					54, 8, ALLEGRO_ALIGN_CENTRE, "FPS: %d", fps);
			}
			al_flip_display();
			fps_accum++;
			if (t - fps_time >= 1) {
				fps = fps_accum;
				fps_accum = 0;
				fps_time = t;
			}
		}
	}




	/*
	//Checking vectors of world and maps
	std::cout << "Start Counting\n";
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

	//art.tileBuffer(*display, world); //NOT WORKING
	//art.drawBitmapTest(*display); 
	//al_clear_to_color(al_map_rgba(0, 0, 0, 0));
	//al_flip_display();
	//al_rest(30.0);
	al_destroy_display(display);


	system("pause");
	return 0;
}
