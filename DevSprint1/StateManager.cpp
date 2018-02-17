#include "StateManager.h"

// Window Used for Display
ALLEGRO_DISPLAY *display;
// Tilemap Test Image
ALLEGRO_BITMAP *BlahtestImage;
// Custom Font
ALLEGRO_FONT *font;

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
	Interact interactions(timer, display);

	// Starts the Timer
	al_start_timer(timer);

	// Begins Loop for Game
	interactions.beginInteractions(Map, Art, display, font);
}

