#include "StateManager.h"

void StateManager::run()
{
	Initialization();

	//Might be Removed
	mainDraw.tileBuffer(*display, Map);	

	// Starts the Timer
	al_start_timer(timer);

	MainLoop(); //Map, Art, display, font
}

void StateManager::MainLoop()
{
	while (GAMERUN)
	{
		Interacting();
		Transformations();
		Drawing();
		Computing();
	}
	Exiting();
}

void StateManager::Initialization()
{
	// RANDOMIZATION //
	srand(time(NULL));

	// Creates the Window we will be Using
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	display = al_create_display(640, 480);
	al_set_window_title(display, "Allegro 5 Tilemap Example");

	// Sets the default Font to be used
	font = al_create_builtin_font(); 

	// Sets bitmap flags
	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
	al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);

	//INITIALIZE THE OBJECTS
	Map.InitalizeClass();
	player.InitializeClass();
	mainDraw.Init();

	timer = al_create_timer(1.0 / 60);

	// Initializes Interactions
	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
}

void StateManager::Transformations()
{
	w = al_get_display_width(display);
	h = al_get_display_height(display);

	/* Initialize transformation. */
	al_identity_transform(&transform);
	/* Move to scroll position. */
	al_translate_transform(&transform, -interactions.scroll_x, -interactions.scroll_y);
	/* Rotate and scale around the center first. */
	al_rotate_transform(&transform, interactions.rotate);
	al_scale_transform(&transform, interactions.zoom, interactions.zoom);
	/* Move scroll position to screen center. */
	al_translate_transform(&transform, w * 0.5, h * 0.5);
	/* All subsequent drawing is transformed. */
	al_use_transform(&transform);
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
	GAMERUN = interactions.beginInteractions(Map, mainDraw, display, font, queue, ObjMang);

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

	if (interactions.redraw && al_is_event_queue_empty(queue)) 
	{
		interactions.redraw = false;
		double t = al_get_time();

		al_hold_bitmap_drawing(1);

		//DRAW ALL LAYERS
		mainDraw.drawWorld(Map);
		mainDraw.drawCharacter(player, interactions.movement.getCharacterXPosition(), interactions.movement.getCharacterYPosition());
		mainDraw.Draw(ObjMang); 


		al_hold_bitmap_drawing(0);

		al_identity_transform(&transform);
		al_use_transform(&transform);


		if (font) {
			al_draw_filled_rounded_rectangle(4, 4, 100, 30,
				8, 8, al_map_rgba(0, 0, 0, 200));
			al_draw_textf(font, al_map_rgb(255, 255, 255),
				54, 8, ALLEGRO_ALIGN_CENTRE, "FPS: %d", interactions.fps);

			al_draw_filled_rounded_rectangle(4, 44, 100, 74,
				8, 8, al_map_rgba(0, 0, 0, 200));
			al_draw_textf(font, al_map_rgb(255, 255, 255),
				54, 48, ALLEGRO_ALIGN_CENTRE, "CPS: %d", GlobStat.getCPS());
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

	mainCompute.Compute(ObjMang);

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