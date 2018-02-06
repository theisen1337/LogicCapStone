#include "World.h"
#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "Artist.h"



ALLEGRO_DISPLAY *display = NULL;

ALLEGRO_BITMAP *BlahtestImage;


int main(void) {
	World world = World();
	Artist art = Artist();
	al_init();
	/*
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	*/
	//al_init_primitives_addon();

	/* Create our window. */
	//al_set_new_display_flags(ALLEGRO_RESIZABLE);
	display = al_create_display(640, 480);
	al_set_window_title(display, "Allegro 5 Tilemap Example");
	
	art.tileBuffer(*display, world);
	art.drawBitmapTest(*display);
	//al_clear_to_color(al_map_rgba(0, 0, 0, 0));
	al_flip_display();
	al_rest(5.0);
	al_destroy_display(display);


	system("pause");
	return 0;
}