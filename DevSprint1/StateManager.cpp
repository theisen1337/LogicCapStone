#include "StateManager.h"

// Window Used for Display
ALLEGRO_DISPLAY *display;
// Tilemap Test Image
ALLEGRO_BITMAP *BlahtestImage;
// Custom Font
ALLEGRO_FONT *font;

ALLEGRO_EVENT_QUEUE *queue;


// Create Static Objects (Similar to Vulkan Use)
//static FileIO IO;

//static Items Items;
//static Tile Tile;


// Initialization of Class

// Return Objects for Extraneous Class Use
//FileIO *LogisticsGame::getIO()
//{
//	return &IO;
//}
//Interact *LogisticsGame::getInteractions()
//{
//	return &Interactions;
//}
//World *LogisticsGame::getMap()
//{
//	return &Map;
//}
//Artist *LogisticsGame::getArt()
//{
//	return &Art;
//}
//Items *LogisticsGame::getItems()
//{
//	return &Items;
//}
//Tiles *LogisticsGame::getTile()
//{
//	return &Tile;
//}






void StateManager::run()
{
	// Built in Game Timer
	ALLEGRO_TIMER *timer;

	// RANDOMIZATION //
	srand(time(NULL));

	// Allegro Initialization
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_install_mouse();
	al_install_keyboard();

	// Creates the Window we will be Using
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	display = al_create_display(640, 480);
	al_set_window_title(display, "Allegro 5 Tilemap Example");

	// Sets the default Font to be used
	font = al_create_builtin_font(); // al_load_font("fixed_font.tga", 0, 0);

									 // Sets bitmap flags
	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);


	//#######################################################################################################
	//	Initalize the main Highest level root objects
	//#######################################################################################################
	Interact Interactions;
	World Map;
	Artist Art;
	//#######################################################################################################
	// Creates Buffer and Generates the Map
	Art.tileBuffer(*display, Map);	// >>> Map.CreateTileBuffer(*display);
									//Map.Generate_Terrain();

									// Initializes Timer
	timer = al_create_timer(1.0 / 60);

	// Initializes Interactions
	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	

	// Starts the Timer
	al_start_timer(timer);

	// Begins Loop for Game

	MainLoop(Map, Art, display, font);
	//interactions.beginInteractions(Map, Art, display, font);
}

void StateManager::MainLoop(World &Map, Artist &Art, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * font)
{
	Interact interactions;
	while (true) {

		
		if (interactions.beginInteractions(Map, Art, display, font, queue) == 0)
		{
			break;
		}

		if (interactions.redraw && al_is_event_queue_empty(queue)) {
			interactions.redraw = false;
			double t = al_get_time();
			Art.drawWorld(*display, interactions.scroll_x, interactions.scroll_y, interactions.zoom, interactions.rotate, Map);
			//tile_map_draw(); //draw
			if (font) {
				al_draw_filled_rounded_rectangle(4, 4, 100, 30,
					8, 8, al_map_rgba(0, 0, 0, 200));
				al_draw_textf(font, al_map_rgb(255, 255, 255),
					54, 8, ALLEGRO_ALIGN_CENTRE, "FPS: %d", interactions.fps);
			}
			al_flip_display();
			interactions.fps_accum++;
			if (t - interactions.fps_time >= 1) {
				interactions.fps = interactions.fps_accum;
				interactions.fps_accum = 0;
				interactions.fps_time = t;
			}
		}
		//Art.drawWorld(*display, interactions.scroll_x, interactions.scroll_y, interactions.zoom, interactions.rotate, Map);
		//al_flip_display();

		//interactions.Redraw();
		
	}
}