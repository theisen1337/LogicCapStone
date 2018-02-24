#include "StateManager.h"

#include "MainDraw.h"
#include "MainCompute.h"

#include "MachineLayer.h"


// Window Used for Display
ALLEGRO_DISPLAY *display;
// Tilemap Test Image
ALLEGRO_BITMAP *BlahtestImage;
// Custom Font
ALLEGRO_FONT *font;

ALLEGRO_EVENT_QUEUE *queue;


//#######################################################################################################
//	Initalize the main Highest level root objects
//#######################################################################################################
Interact Interactions;
World Map;
Artist Art;
Interact interactions;
MainDraw mainDraw;
MainCompute mainCompute;

MachineLayer machineLayer;
ItemLayer itemLayer;
OreLayer oreLayer;
//#######################################################################################################
//#######################################################################################################
//	Variables
//#######################################################################################################
bool GAMERUN = true;
//#######################################################################################################


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

	Map.InitalizeClass();

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

	MainLoop(); //Map, Art, display, font
}

void StateManager::MainLoop()
{

	while (GAMERUN) 
	{
		Interacting();
		Drawing();
		Computing();
	}
	Exiting();
}



void StateManager::Interacting()
{
	//#####################################################################
	/*
	#
	#		Main Interacting
	#
	*/
	//#####################################################################

	//Returns false if the game exit button is pressed	
	GAMERUN = interactions.beginInteractions(Map, Art, display, font, queue, itemLayer, oreLayer, machineLayer);

	//#####################################################################
	/*
	#
	#		Main Interacting
	#
	*/
	//#####################################################################
}

void StateManager::Drawing()
{
	//#####################################################################
	/*
	#
	#		Main Drawing
	#
	*/
	//#####################################################################

	if (interactions.redraw && al_is_event_queue_empty(queue)) {
		interactions.redraw = false;
		double t = al_get_time();
		Art.drawWorld(*display, interactions.scroll_x, interactions.scroll_y, interactions.zoom, interactions.rotate, Map);

		Art.drawCharacter(*display, interactions.scroll_x, interactions.scroll_y, interactions.zoom, interactions.rotate, Map, interactions.character, interactions.movement.getCharacterXPosition(), interactions.movement.getCharacterYPosition());

		mainDraw.Draw(machineLayer); //Main Draw for Layers

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

	//#####################################################################
	/*
	#
	#		Main Drawing
	#
	*/
	//#####################################################################
}

void StateManager::Computing()
{
	//#####################################################################
	/*
	#
	#		Main Computing
	#
	*/
	//#####################################################################

	mainCompute.Compute(machineLayer);

	//#####################################################################
	/*
	#
	#		Main Computing
	#
	*/
	//#####################################################################
}

void StateManager::Exiting()
{
	//Keep up stuff here!
	std::cout << "CLEAN UP STUFF!!!!!!";
}