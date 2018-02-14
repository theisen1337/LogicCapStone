/* Simple Allegro 5 tilemap example from allegro.cc:
*
* http://www.allegro.cc/forums/thread/606482
*
* Also see here for more info:
*
* http://wiki.allegro.cc/index.php?title=Allegro_5_Tutorial
*
* Place fixed_font.tga and icon.tga from the Allegro 5 examples/data
* folder next to the .exe and there will be an FPS counter and an
* icon.
*
* Left mouse = Pan
* Right mouse = Rotozoom
* Esc = Quit
*/

#include "main.h"

// Window Used for Display
ALLEGRO_DISPLAY *display;
// Tilemap Test Image
ALLEGRO_BITMAP *BlahtestImage;
// Custom Font
ALLEGRO_FONT *font;

// Create Static Objects (Similar to Vulkan Use)
static FileIO IO;
static Interact Interactions;
static TileMap Map;
static Items Item;
static Tiles Tile;

// Initialization of Class
LogisticsGame& LogisticsGame::getInstance()
{
	static LogisticsGame instance;

	return instance;
}

// Return Objects for Extraneous Class Use
FileIO *LogisticsGame::getIO()
{
	return &IO;
}
Interact *LogisticsGame::getInteractions()
{
	return &Interactions;
}
TileMap *LogisticsGame::getMap()
{
	return &Map;
}
Items *LogisticsGame::getItem()
{
	return &Item;
}
Tiles *LogisticsGame::getTile()
{
	return &Tile;
}

LogisticsGame game = LogisticsGame::getInstance();

void LogisticsGame::run()
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

	// Creates Buffer and Generates the Map
	Map.CreateTileBuffer(*display);
	Map.Generate_Terrain();

	// Initializes Timer
	timer = al_create_timer(1.0 / 60);

	// Initializes Interactions
	Interact interactions(timer, display);

	// Starts the Timer
	al_start_timer(timer);

	// Begins Loop for Game
	interactions.beginInteractions(Map, display, font);
}

int main(void) 
{
	try
	{
		game.run();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}